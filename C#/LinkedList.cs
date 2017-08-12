using System;
using System.Collections.Generic;

namespace C_
{
    public class LinkedListSamples
    {

        public LinkedListSamples()
        {
            var linkedList = Create();
            var element = FindNthFromLast(linkedList.First, 4);
            Console.WriteLine(element.Value);
        }

        public static LinkedListNode<int> FindNthFromLast(LinkedListNode<int> head, int n)
        {
            if (head == null) return null;
            if (n <= 0) return null;
            if (head.Next == null && n > 1) return null;

            var ahead = head;
            while (--n > 0)
            {
                ahead = ahead.Next;
            }

            var current = head;
            while (ahead.Next != null)
            {
                current = current.Next;
                ahead = ahead.Next;
            }
            return current;
        }

        public static LinkedList<int> Create()
        {

            var linkedList = new LinkedList<int>();

            linkedList
                .AddFirst(new LinkedListNode<int>(4));

            linkedList
               .AddFirst(new LinkedListNode<int>(3));

            linkedList
                .AddFirst(new LinkedListNode<int>(2));

            linkedList
                .AddFirst(new LinkedListNode<int>(1));

            return linkedList;

        }



    }
}