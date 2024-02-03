namespace Test
{
    class Receipt
    {
        static void receipt()
        {
            int t = int.Parse(Console.ReadLine()), n = int.Parse(Console.ReadLine()), s = 0; for (; n-- > 0;) { var p = Console.ReadLine().Split().Select(int.Parse).ToArray(); s += p[0] * p[1]; }
            Console.Write(t == s ? "Yes" : "No");
        }
    }
}