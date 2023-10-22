#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int _data)
    {
        this->data = _data;
        this->next = NULL;
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

    Node *find_perant(Node *node)
    {
        for (NodeIterator itr = this->iterator_start(); itr.current_node() != NULL; itr.next())
        {

            if (itr.current_node()->next == node)
            {
                return itr.current_node();
            }
        }
        return NULL;
    }
    void insert_last(int _data)
    {
        Node *new_node = new Node(_data);
        // head-> = *head
        if (this->head == NULL)
        {

            this->head = new_node;
            this->tail = new_node;
        }
        else
        {

            this->tail->next = new_node;
            this->tail = new_node;
        }
    }

    void insert_after(Node *node, int _data)
    {

        Node *new_node = new Node(_data);
        new_node->next = node->next;
        node->next = new_node;
        // node tail valdation
        if (this->tail == node)
        {

            this->tail = new_node;
        }
    }

    void insert_befor(Node *node, int _data)
    {

        Node *new_node = new Node(_data);
        new_node->next = node;
        Node *perant = this->find_perant(node);
        if (perant == NULL)
        {
            this->head = new_node;
        }
        else
        {

            perant->next = new_node;
        }
    }

    void delete_node(Node *node)
    {
        if (this->head == this->tail)
        {
            this->head = NULL;
            this->tail = NULL;
        }
        else if (this->head == node)
        {
            this->head = node->next;
        }
        else
        {
            Node *perant = this->find_perant(node);
            if (this->tail == node)
            {
                this->tail = perant;
            }
            else
            {
                perant->next = node->next;
            }
        }

        delete node;
    }
};


