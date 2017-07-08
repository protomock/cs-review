#include <stddef.h>
// You should not depend on compiler generated add copy constructors and assigment operators
template <class T>
class Node
{
  public:
    Node(const T &value) : next(NULL), data(value) {}
    ~Node()
    {
        delete this->next;
        this->setValue(0);
    }

    void operator=(const Node<T> &node)
    {
        next = node.next;
        data = node.data;
    }

    Node *getNext() const { return next; }
    const T &value() const { return data; }
    void setNext(Node *elem) { next = elem; }
    void setValue(const T &value) { data = value; }

  private:
    Node *next;
    T data;
};