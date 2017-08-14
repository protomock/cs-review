using src;
using Xunit;

namespace test
{
    public class BinaryTreeExamplesTest
    {
        private readonly TreeNode<int> root;

        public BinaryTreeExamplesTest()
        {
            root = new TreeNode<int>(10);
        }
        [Fact]
        public void IsBalanced_OnlyRootNode()
        {
            Assert.True(BinaryTreeExamples.IsBalanced(root));
        }

        [Fact]
        public void IsBalanced_RootNodeHasTwoLeafs()
        {
            root.Left = new TreeNode<int>(12);
            root.Right = new TreeNode<int>(100);
            Assert.True(BinaryTreeExamples.IsBalanced(root));
        }

        [Fact]
        public void IsBalanced_RootNodeHasTwoSubTrees()
        {
            root.Left = new TreeNode<int>(12);
            root.Left.Left = new TreeNode<int>(4);
            root.Left.Right = new TreeNode<int>(78);
            root.Right = new TreeNode<int>(100);
            root.Right.Left = new TreeNode<int>(89);
            root.Right.Right = new TreeNode<int>(112);
            Assert.True(BinaryTreeExamples.IsBalanced(root));
        }

        [Fact]
        public void IsBalanced_NotBalanced()
        {
            root.Left = new TreeNode<int>(12);
            root.Left.Left = new TreeNode<int>(4);
            root.Left.Right = new TreeNode<int>(78);
            root.Left.Right.Left = new TreeNode<int>(22);
            root.Right = new TreeNode<int>(100);
            Assert.False(BinaryTreeExamples.IsBalanced(root));
        }
    }
}
