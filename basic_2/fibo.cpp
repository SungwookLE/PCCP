

#include <bits/stdc++.h>
using namespace std;

int fibo_recursion(int n)
{
    if (n == 0 || n == 1)
        return 1;

    int ret = fibo_recursion(n - 1) + fibo_recursion(n - 2);

    return ret;
}

int main()
{

    int n = 6;
    cout << fibo_recursion(n) << endl;

    return 0;
}

