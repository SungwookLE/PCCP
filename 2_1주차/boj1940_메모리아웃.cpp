#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> Ms;
int answer = 0;

void make_combi(int start, int r, vector<int> V)
{
    if (r == V.size())
    {
        int sum = 0;
        for (auto v : V)
            sum += Ms[v];
        if (sum == M)
            answer += 1;
    }

    for (int i = start + 1; i < N; ++i)
    {
        V.push_back(i);
        make_combi(i, r, V);
        V.pop_back();
    }
}

int main()
{

    cin >> N;
    cin >> M;

    Ms = vector<int>(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> Ms[i];
    }

    make_combi(-1, 2, {}); // nC2
    cout << answer << "\n";

    return 0;
}