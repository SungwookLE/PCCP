#include <bits/stdc++.h>

using namespace std;
int N, M;
map<string, int> V;
map<int, string> V2;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    string name;
    for (int i = 0; i < N; ++i)
    {
        cin >> name;
        V[name] = i + 1;
        V2[i] = name;
    }

    string query;
    for (int i = 0; i < M; ++i)
    {
        cin >> query;

        if ((query[0] >= 'A' && query[0] <= 'Z') ||
            (query[0] >= 'a' && query[0] <= 'z'))
        {
            cout << V[query] << "\n";
        }
        else
        {
            cout << V2[stoi(query) - 1] << "\n";
        }
    }

    return 0;
}