#include <bits/stdc++.h>

using namespace std;
vector<int> counts;

void make_combi(int start, int r, vector<int> V, map<string, int> wears, int &answer)
{
    // NAIVE하게 모든 COMBINATION을 구해서 구해내려고 하였음
    if (V.size() == r)
    {
        int temp = 1;

        for (auto v : V)
            temp *= counts[v];

        answer += temp;
    }

    for (int j = start + 1; j < counts.size(); ++j)
    {
        V.push_back(j);
        make_combi(j, r, V, wears, answer);
        V.pop_back();
    }
}

int main()
{

    int T;
    cin >> T;

    int n;
    string s1, s2;

    for (int i = 0; i < T; ++i)
    {
        map<string, int> wears;

        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            cin >> s1 >> s2;
            wears[s2] += 1;
        }

        for (auto w : wears)
            counts.push_back(w.second);

        int answer = 0;
        for (int i = 1; i <= counts.size(); ++i)
            make_combi(-1, i, {}, wears, answer);

        cout << answer << "\n";
        counts.clear();
    }

    return 0;
}