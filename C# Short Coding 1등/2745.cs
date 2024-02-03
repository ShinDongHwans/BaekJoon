// https://www.acmicpc.net/short/status/2745/86/1
namespace Baekjoon
{
    class KBaseConvert
    {
        static void convert()
        {
            var v = Console.ReadLine().Split();
            int s = 0, i = 0, b = int.Parse(v[1]);
            for (; i < v[0].Length; i++) s = s * b + (v[0][i] > 60 ? v[0][i] - 55 : v[0][i] - 48);
            Console.Write(s);
        }
    }
}
