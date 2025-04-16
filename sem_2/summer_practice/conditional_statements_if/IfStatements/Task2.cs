namespace IfStatements
{
    public static class Task2
    {
        public static int DoSomething1(int i)
        {
            int result = i;
            if ((i >= -5) && (i < 0))
            {
                result = -i;
            }

            if (i < -5)
            {
                result *= -i;
            }

            return result;
        }

        public static int DoSomething2(int i)
        {
            int result = i;
            if ((i >= -5) && (i < 0))
            {
                return -i;
            }

            if (i < -5)
            {
                return -(i * i);
            }

            return result;
        }
    }
}
