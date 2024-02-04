#include <bits/stdc++.h>

using namespace std;

int i = 666;
int N;

int main()
{

    cin >> N;
    for (;; i++) // 무한 루프
    {
        if (to_string(i).find("666") != string::npos)
            N--;
        if (N == 0)
            break;
    }

    cout << i << "\n";

    return 0;
}