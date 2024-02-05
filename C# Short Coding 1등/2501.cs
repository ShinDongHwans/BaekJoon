//https://www.acmicpc.net/short/status/2501/86/1
namespace Baekjoon
{
    class FindKthMinDivisor
    {
        static void findKthMinDivisor()
        {
            var v = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int i=0,j=0;
            while(i<v[0]&&j<v[1]){
                if(v[0]%++i==0) j++;
            }
            Console.Write(j==v[1] ? i:0);
        }
    }
}
