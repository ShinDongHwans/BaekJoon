// var f = () => { return Console.ReadLine().Split().Select(int.Parse).ToArray(); };
// Console.Write(new HashSet<string>(Console.ReadLine().Trim().Split()).count);
//1152번 Console.Write(Console.ReadLine().Trim().Split(" ").Length);

// int m = 0, j, i = 0, x = 1, y = 1;
// for (; i++ < 9;)
// {
//     var n = Console.ReadLine().Split().Select(int.Parse).ToArray();
//     for (j = 0; j < 9;)
//         if (m < n[j++])
//         {
//             x = i; y = j; m = n[j - 1];
//         }
// }
// Console.Write(m + "\n" + x + " " + y);