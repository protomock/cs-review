using System;

namespace src
{
    public class BinaryTreeExamples
    {
        public static bool IsBalanced<T>(TreeNode<T> root)
        {
            if (root.Left == null && root.Right == null) return true;

            var leftHeight = GetHeight(root.Left);
            var rightHeight = GetHeight(root.Left);

            return Math.Abs(leftHeight - rightHeight) <= 1;
        }

        private static int GetHeight<T>(TreeNode<T> root)
        {
            if (root == null) return 0;
            if (root.Left == null && root.Right == null) return 0;

            var leftHeight = 1 + GetHeight(root.Left);
            var rightHeight = 1 + GetHeight(root.Left);

            return leftHeight > rightHeight ? leftHeight : rightHeight;
        }
    }
}