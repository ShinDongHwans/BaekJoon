namespace Baekjoon
{
    class FindCoordinate
    {
        static void findCoordinate()
        {
            bool a = Console.ReadLine()[0] == 45;
            int b = Console.Read() != 45 ? 0 : 2;
            Console.Write((a != b > 0 ? 2 : 1) + b);
        }
    }
}