// https://www.acmicpc.net/short/status/2745/86/1
// https://www.acmicpc.net/short/status/11005/86/1
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
        static void aConvert()
        {
            var v = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var o = "";
            while(v[0] > 0){
                o = (char)(v[0]%v[1]+((v[0]%v[1])>=10?55:48))+o;
                v[0]/=v[1];
            }
            Console.Write(o);
        }
    }
}
