#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> delta = {-1, 1, 2}; // 2 means multiply 2 times

vector<int> visited;
queue<int> candidates;
vector<int> cnt;

int main()
{
    cin >> N >> K;

    visited = vector<int>(1000001, 0);
    cnt = vector<int>(1000001, 0);

    candidates.push(N);
    visited[N] = 1;
    cnt[N] = 1;

    while (!candidates.empty())
    {
        int now = candidates.front();
        candidates.pop();

        if (now == K) break;

        for (int next_ : {now-1, now+1, now*2}){
            if (next_ >= 0 && next_ < 1000001)
            {
                if (visited[next_] == 0)
                {
                    cnt[next_] += cnt[now]; // 최초 방문
                    visited[next_] = visited[now] + 1;
                    candidates.push(next_);
                }
                else if (visited[next_] == visited[now] + 1)
                {
                    cnt[next_] = cnt[next_] + cnt[now]; // 두번째  방문임, 과거의 방문 횟수를 더해줌
                }
            }
        }
    }

    cout << visited[K] - 1 << endl;
    cout << cnt[K] << endl;

    return 0;
}