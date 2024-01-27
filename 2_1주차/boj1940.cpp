#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> Ms;
int answer = 0;

int main()
{

    cin >> N;
    cin >> M;

    Ms = vector<int>(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> Ms[i];
    }

    if (M > 20000)
        cout << 0 << "\n";
    else
    {
        // 3중 combination 까지는 중첩 for문을 통해서 구현하는게 메모리 차원에서 이득임
        for (int i = 0; i < N; ++i) 
        {
            for (int j = i + 1; j < N; ++j)
            {
                if (Ms[i] + Ms[j] == M)
                    answer += 1;
            }
        }
        cout << answer << "\n";
    }

    return 0;
}