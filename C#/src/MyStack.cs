using System.Collections.Generic;
using System.Dynamic;

namespace src
{
    public class MyStack
    {
        private readonly LinkedList<dynamic> stack;
        private int min { get; set; }

        public MyStack()
        {
            this.stack = new LinkedList<dynamic>();
        }

        public void Push(int value)
        {
            if (value < min) min = value;
            dynamic current = new ExpandoObject();
            current.value = value;
            current.min = min;
            stack.AddFirst(current);
        }

        public int Pop()
        {
            var firstElementValue = stack.First.Value;
            min = firstElementValue.min;
            stack.RemoveFirst();
            return firstElementValue.value;
        }

        public int Min()
        {
            return min;
        }
    }
}