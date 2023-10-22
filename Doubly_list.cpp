#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *back;
    Node(int _data)
    {
        this->data = _data;
        this->next = NULL;
        this->back = NULL;
    }
};

class NodeIterator
{

private:
    Node *current;

public:
    NodeIterator() { current = NULL; }
    NodeIterator(Node *node) { current = node; }
    int data()
    {

        return this->current->data;
    }

    NodeIterator next()
    {

        this->current = this->current->next;
        return *this;
    }

    Node *current_node()
    {

        return this->current;
    }
};

class LinkedList
{
private:
    int length;

public:
    Node *head = NULL;
    Node *tail = NULL;

    NodeIterator iterator_start()
    {

        NodeIterator itr(this->head);
        return itr;
    }

    void print_list()
    {

        for (NodeIterator itr = this->iterator_start(); itr.current_node() != NULL; itr.next())
        {
            cout << itr.data() << endl;
        }
    }

    Node *find(int _data)
    {

        for (NodeIterator itr = this->iterator_start(); itr.current_node() != NULL; itr.next())
        {

            if (_data == itr.data())
            {
                return itr.current_node();
            }
        }
        return NULL;
    }

    void insert_last(int _data)
    {
        Node *newNode = new Node(_data);
        if (this->tail == NULL)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {

            newNode->back = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    void insert_after(Node *node, int _data)
    {

        Node *newNode = new Node(_data);
        newNode->next = node->next;
        newNode->back = node;
        node->next = newNode;
        if (this->tail = node)
        {

            this->tail = newNode;
        }
        else
        {
            newNode->next->back = newNode;
        }
    }

    void insert_befor(Node *node, int _data)
    {

        Node *newNode = new Node(_data);
        newNode->next = node;
        if (this->head == node)
        {

            this->head = newNode;
        }
        else
        {

            node->back->next = newNode;
            node->back = newNode;
            newNode->back = node->back;
        }
    }

    void delete_node(Node *node)
    {
        if (this->head == this->tail)
        {

            this->head = NULL;
            this->tail = NULL;
        }
        else if (node->back == NULL)
        {

            this->head = node->next;
            node->next->back = NULL;
        }
        else if (node->next == NULL)
        {

            this->tail = node->back;
            this->tail->next = NULL;
            // node->back->next=NULL
        }
        else
        {

            node->back->next = node->next;
            node->next->back = node->back;
        }
        delete node;
    }
};


