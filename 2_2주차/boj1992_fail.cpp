#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> datas;
string answer;

void quard(int N, int i, int j)
{
    if (N == 2)
    {

        if (datas[i][j] == datas[i][j + 1])
            if (datas[i][j + 1] == datas[i + 1][j])
                if (datas[i + 1][j] == datas[i + 1][j + 1])
                {
                    answer += to_string(datas[i][j]);
                    return;
                }

        answer += "(";
        answer += to_string(datas[i][j]);
        answer += to_string(datas[i][j + 1]);
        answer += to_string(datas[i + 1][j]);
        answer += to_string(datas[i + 1][j + 1]);
        answer += ")";
        return;
    }

    answer += "(";
    quard(N / 2, i, j);
    quard(N / 2, i, j + N / 2);
    quard(N / 2, i + N / 2, j);
    quard(N / 2, i + N / 2, j + N / 2);
    answer += ")";

    return;
}

int main()
{

    cin >> N;
    datas = vector<vector<int>>(N, vector<int>(N, 0));

    string s;
    for (int i = 0; i < N; ++i)
    {
        cin >> s;

        for (int j = 0; j < N; ++j)
        {
            datas[i][j] = s[j] - '0';
        }
    }

    quard(N, 0, 0);

    cout << answer << endl;
    return 0;
}