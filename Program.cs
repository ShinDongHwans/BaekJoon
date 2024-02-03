var f = () => { return Console.ReadLine().Split().Select(int.Parse).ToArray(); };
var i = f();
var l = i[0];
var x = new int[l + 1];
for (; l > 0;) x[l] = l--;
for (; i[1]-- > 0;)
{
    var n = f();
    for (; n[0] < n[1];)
        (x[n[0]], x[n[1]]) = (x[n[1]--], x[n[0]++]);
}
for (l = 1; l < x.Length;)
    Console.Write(x[l++] + " ");