#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next = NULL;
    Node<T> *back = NULL;

    Node(T data) { this->data = data; };
};

template <typename T>
class Iterator
{

public:
    Node<T> *current_node;

    Iterator(Node<T> *node)
    {

        current_node = node;
    }
    Iterator()
    {
        current_node = NULL;
    }

    void dont_itr()
    {
        current_node = NULL;
    }

    Iterator next()
    {

        current_node = current_node->next;
        return *this;
    }

    Iterator back()
    {

        current_node = current_node->back;
        return *this;
    };

    void print_data()
    {

        cout << current_node->data;
    }
};

template <typename T>
class Doubly_Linked_List
{
public:
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
    int length = 0;

    Node<T> *find(T node_data)
    {
        for (Iterator<int> itr(head); itr.current_node != NULL; itr.next())
        {

            if (itr.current_node->data == node_data)
            {
                return itr.current_node;
            }
        }

        return NULL;
    }

    void print_list()
    {
        for (Iterator<int> itr(head); itr.current_node != NULL; itr.next())
        {
            cout << itr.current_node->data << endl;
        }
    }
    Doubly_Linked_List<T> copy_list()
    {

        Doubly_Linked_List<T> list;
        for (Iterator<int> itr(head); itr.current_node != NULL; itr.next())
        {
            list.insert_last(itr.current_node->data);
        }
        return list;
    }

    void insert_first(T data)
    {
        Node<T> *newNode = new Node<T>(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = this->head;
            this->head->back = newNode;
            this->head = newNode;
        }

        length++;
    }
    void insert_last(T data)
    {
        Node<T> *newNode = new Node<T>(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->back = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
        }

        length++;
    }

    void insert_after(T search_data, T _data)
    {
        Node<T> *node = this->find(search_data);
        Node<T> *newNode = new Node<T>(_data);
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
        length++;
    }

    void insert_befor(T search_data, T _data)
    {
        Node<T> *node = this->find(search_data);
        Node<T> *newNode = new Node<T>(_data);
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
        length++;
    }

    void delete_node(T data)
    {
        Node<T> *node = this->find(data);
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
        }
        else
        {

            node->back->next = node->next;
            node->next->back = node->back;
        }
        delete node;
        length--;
    }
    void delete_head_for_stack()
    {
        if (this->head != NULL)
        {
            Node<T> *node = this->head;
            this->head = this->head->next;
            delete node;
            length--;
        }
    }

     
};

Doubly_Linked_List<int> Merge_Two_Sorted_Lists(Doubly_Linked_List<int> list_1, Doubly_Linked_List<int> list_2)
{

    Doubly_Linked_List<int> merged_list;
    // merge:
    list_1.tail->next = list_2.head;
    list_2.head->back = list_1.tail;
    merged_list.head = list_1.head;
    merged_list.tail = list_2.tail;

    // insertion sort:
    Iterator<int> itr_1(merged_list.head->next);
    for (; itr_1.current_node != NULL; itr_1.next())
    {
        int key = itr_1.current_node->data;
        Iterator<int> itr_2(itr_1.current_node->back);
        for (; itr_2.current_node != NULL && itr_2.current_node->data > key; itr_2.back())
        {
            itr_2.current_node->next->data = itr_2.current_node->data;
            itr_2.current_node->data = key;
        }
    }

    return merged_list;
}
// stack class
template <typename T>
class Stack
{

public:
    Doubly_Linked_List<T> _data_list;
    Stack()
    {
        this->_data_list = Doubly_Linked_List<T>();
    }
    void push(T _data)
    {

        this->_data_list.insert_first(_data);
    }
    T pop()
    {

        T head_data = this->_data_list.head->data;
        this->_data_list.delete_head_for_stack();
        return head_data;
    }

    T peek()
    {

        return this->_data_list.head->data;
    }

    bool is_empty()
    {
        if (this->_data_list.length <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print_stack()
    {
        this->_data_list.print_list();
    }
};