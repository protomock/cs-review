#include "./singly-linked-list.cpp"

template <class T>
class Stack
{
  public:
    Stack()
    {
        _stack = new SinglyLinkedList<T>();
    }
    ~Stack() {}

    void push(const T &data)
    {
        _stack->InsertInFront(data);
    }
    const T &pop()
    {
        return _stack->RemoveFirst();
    }

  private:
    SinglyLinkedList<T> *_stack;
};