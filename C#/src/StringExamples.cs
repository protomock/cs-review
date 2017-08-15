namespace src
{
    public class StringExamples
    {
        public static int StrToInt(string number)
        {
            var total = 0;
            var neg = number[0] == '-';
            var i = neg ? 1 : 0;

            for (; i < number.Length; i++)
            {
                total *= 10;
                total += number[i] - '0';
            }
            return neg ? -total : total;
        }
    }
}