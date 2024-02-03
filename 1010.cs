namespace Baekjoon
{
    class Test
    {
        static void sub()
        {
            int t = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < t; i++)
            {
                string line = Console.ReadLine();
                string[] words = line.Split();

                uint a = Convert.ToUInt32(words[0]);
                uint b = Convert.ToUInt32(words[1]);

                Console.WriteLine(com(a, b));
            }
        }

        static uint com(uint a, uint b)
        {
            uint answer = 1;

            for (uint i = b; i > b - a; i--)
            {
                answer *= i;
                answer /= (b - i + 1);
            }
            return answer;
        }
    }
}