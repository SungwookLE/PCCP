#include <bits/stdc++.h>

using namespace std;

long long calc(long long a, long long b, long long c)
{   

    if (b == 1)
        return a % c ;

    if (b & 1)
        return calc( (a * a)%c, b / 2, c) % c * a % c;

    return calc((a * a)%c, b / 2, c) % c;
}

int main()
{

    long long A, B, C;
    cin >> A >> B >> C;

    long long answer = calc(A%C, B, C);

    cout << answer ;

    return 0;
}