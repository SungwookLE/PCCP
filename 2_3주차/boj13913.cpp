#include <bits/stdc++.h>

using namespace std;

queue<int> candidates;
vector<int> delta = {-1, 1, 2};
vector<int> visited, prevp;

int N, K;

int main()
{
    cin >> N >> K;

    visited = vector<int>(1000001, 0);
    prevp = vector<int>(1000001, -1);

    candidates.push(N);
    visited[N] = 1;

    stack<int> ret;
    while (!candidates.empty())
    {

        int now = candidates.front();
        candidates.pop();

        if (now == K)
        {

            cout << visited[now] - 1 << endl;
            stack<int> ret;
            while (now != N)
            {
                ret.push(now);
                now = prevp[now];
            }
            ret.push(N);

            while (!ret.empty())
            {
                cout << ret.top() << " ";
                ret.pop();
            }

            break;
        }

        int idx = 0;
        for (auto next_ : {now-1, now+1, now*2})
        {
            if (next_ >= 0 && next_ < 1000000)
            {
                if (visited[next_] == 0)
                {
                    candidates.push(next_);
                    visited[next_] = visited[now] + 1;
                    prevp[next_] = now;
                }
            }
            idx++;
        }
    }

    return 0;
}