//https://www.acmicpc.net/short/status/10101/86/1
namespace Baekjoon
{
    class TriangleJudge
    {
        static void judge()
        {
            var f=()=>{return int.Parse(Console.ReadLine());};
            int a=f(),b=f(),c=f();
            Console.Write(a+b+c!=180?"Error":a==b||b==c||a==c?a==60?"Equilateral":"Isosceles":"Scalene");
        }
    }
}
