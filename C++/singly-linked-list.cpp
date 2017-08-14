#include "./node.cpp"
#include <exception>
#include <cstdio>

template <class T>
class SinglyLinkedList
{
  public:
    SinglyLinkedList() {}
    ~SinglyLinkedList() {}

    Node<T> *getHead()
    {
        return head;
    }

    Node<T> *getTail()
    {
        return tail;
    }

    void DeleteAll()
    {
        Node<T> *next;
        while (head)
        {
            next = head->getNext();
            delete head;
            head = next;
        }

        tail = NULL;
    }

    void InsertInFront(Node<T> *element)
    {
        element->setNext(head);
        head = element;

        if (head->getNext() == NULL)
        {
            tail = element;
        }
    }

    bool DeleteFirst()
    {
        if (head == NULL)
        {
            return false;
        }

        head = head->getNext();
        if (head == NULL)
        {
            tail = NULL;
        }

        return true;
    }

    bool InsertAfter(Node<T> *element, const T &data)
    {
        bool result = false;
        Node<T> *current = head;

        if (!head || !element)
        {
            return result;
        }

        while (current && !result)
        {
            if (current == element)
            {
                Node<T> *node = new Node<T>(data);
                node->setNext(element->getNext());
                element->setNext(node);

                if (!node->getNext())
                {
                    tail = node;
                }
                result = true;
            }

            current = current->getNext();
        }

        return result;
    }

    bool Delete(Node<T> *element)
    {
        bool result = false;
        Node<T> *current = head;

        if (!element)
        {
            return result;
        }

        if (head == element)
        {
            head = element->getNext();
            delete element;

            if (!head)
            {
                tail = NULL;
            }
            result = true;
        }

        while (current)
        {
            if (current->getNext() == element)
            {
                current->setNext(element->getNext());
                delete element;

                if (current->getNext() == NULL)
                {
                    tail = current;
                }
                result = true;
            }
            else
            {
                current = current->getNext();
            }
        }

        return result;
    }

    void reverse()
    {
        this->_reverse(this->head);

        //Swap head and tail
        Node<T> *head = this->head;
        this->head = this->tail;
        this->tail = head;
    }

  private:
    Node<T> *head;
    Node<T> *tail;

    void _reverse(Node<T> *head)
    {
        if (!head)
            return;
        if (!head->getNext())
            return;

        _reverse(head->getNext());

        head->getNext()->setNext(head);
        head->setNext(NULL);
    }
};