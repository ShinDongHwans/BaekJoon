// https://www.acmicpc.net/problem/25206
namespace Baekjoon
{
    class GradeCalculator
    {
        static void calculate()
        {
            double s = 0, t = 0, i = 0, m;
            for (; i++ < 20;)
            {
                var v = Console.ReadLine().Split();
                if (v[2][0] == 'P') continue;
                m = double.Parse(v[1]);
                t += m;
                s += m * (v[2][0] == 'F' ? 0 : 69 - v[2][0] + 4.8 - v[2][1] / 10f);
            }
            Console.Write(s / t);
        }
    }
}