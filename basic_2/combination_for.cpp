#include <bits/stdc++.h>

using namespace std;

int n = 5;
vector<int> V = {1, 2, 3, 4, 5};
int k = 3; // 3개를 뽑는다면

int main()
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                cout << i << ": " << j << ": " << k << endl;
            }
        }
    }

    return 0;
}





