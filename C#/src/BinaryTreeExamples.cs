using System;

namespace src
{
    public class BinaryTreeExamples
    {
        public static bool IsBalanced<T>(TreeNode<T> root)
        {
            if (root.Left == null && root.Right == null) return true;

            var leftHeight = GetHeight(root.Left);
            var rightHeight = GetHeight(root.Right);

            return Math.Abs(leftHeight - rightHeight) <= 1;
        }

        public static TreeNode<T> CreateTree<T>(T[] arr)
        {
            return CreateTreeFromPos(arr, 0);
        }

        private static TreeNode<T> CreateTreeFromPos<T>(T[] arr, int start)
        {
            var root = new TreeNode<T>(arr[start]);
            var leftNode = (2 * start) + 1;
            var rightNode = leftNode + 1;

            if (leftNode <= arr.Length - 1) root.Left = CreateTreeFromPos(arr, leftNode);
            if (rightNode <= arr.Length - 1) root.Right = CreateTreeFromPos(arr, rightNode);
            return root;
        }

        private static int GetHeight<T>(TreeNode<T> root)
        {
            if (root == null) return 0;
            return 1 + Math.Max(GetHeight(root.Left), GetHeight(root.Right));
        }
    }
}