using src;
using Xunit;

namespace test
{
    public class StringExamplesClass
    {
        [Fact]
        public void StrToInt_ShouldReturnTheExpectedResult()
        {
            Assert.Equal(StringExamples.StrToInt("123"), 123);
        }
        [Fact]
        public void StrToInt_ShouldReturnTheExpectedResultWhenNegative()
        {
            Assert.Equal(StringExamples.StrToInt("-123"), -123);
        }
    }
}