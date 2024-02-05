//judgeByAngle: https://www.acmicpc.net/short/status/10101/86/1
//judgeBySideLength: https://www.acmicpc.net/short/status/5073/86/1
namespace Baekjoon
{
    class TriangleJudge
    {
        static void judgeByAngle()
        {
            var f=()=>{return int.Parse(Console.ReadLine());};
            int a=f(),b=f(),c=f();
            Console.Write(a+b+c!=180?"Error":a==b||b==c||a==c?a==60?"Equilateral":"Isosceles":"Scalene");
        }

        static void judgeBySideLength()
        {
            while(true){
                var v=Console.ReadLine().Split().Select(int.Parse).ToArray();
                Array.Sort(v);
                if(v[2]==0) break;
                Console.WriteLine(v[2]*2>=v.Sum()?"Invalid":v[2]==v[0]?"Equilateral":(v[1]==v[0]||v[1]==v[2])?"Isosceles":"Scalene ");
            }   
        }
    }
}
