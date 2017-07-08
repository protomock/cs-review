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

int main()
{
    Stack<int> *stack = new Stack<int>();
    stack->push(1);
    stack->push(11);

    int popped = stack->pop();
    int poppedAgain = stack->pop();
    int poppedAgainAgain = stack->pop();
};