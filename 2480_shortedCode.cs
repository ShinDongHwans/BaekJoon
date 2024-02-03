namespace Test
{
    class ThreeDice
    {
        static void threeDice()
        {
            var d = Console.ReadLine().Split().Select(int.Parse).ToArray(); Array.Sort(d); Console.Write((d[0] == d[2] ? 100 + d[0] * 10 : d[0] == d[1] ? 10 + d[0] : d[1] == d[2] ? 10 + d[1] : d[2]) * 100);
        }
    }
}