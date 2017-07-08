#include "./node.cpp"

template <class T>
class SinglyLinkedList
{
  public:
    SinglyLinkedList() {}
    ~SinglyLinkedList() {}

    void InsertInFront(const T &data)
    {
        Node<T> *newHead = new Node<T>(data);
        newHead->setNext(head);
        head = newHead;
    }

    const T &RemoveFirst()
    {
        Node<T>* removed = head;
        if (head == NULL) {
            throw; 
        }

        const T &data = head->value();
        head = head->getNext();
        delete removed;

        return data;
    }

    Node<T> *Find(const T &data)
    {
        Node<T> *current = head;
        while (current && data != current->value())
        {
            current = current->getNext();
        }
        return current;
    }

    void Remove(const T &data)
    {
        Node<T> *current = head;
        Node<T> *nextNode = current->getNext();
        while (nextNode && data != nextNode->value())
        {
            current = nextNode;
            nextNode = nextNode->getNext();
        }
        current->setNext(nextNode->getNext());
    }

  private:
    Node<T> *head;
};