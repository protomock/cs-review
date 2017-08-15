namespace src
{
    public class TreeNode<T>
    {
        public readonly T Value;

        public TreeNode<T> Left { get; set; }

        public TreeNode<T> Right { get; set; }

        public TreeNode(T value)
        {
            Value = value;
        }
    }
}