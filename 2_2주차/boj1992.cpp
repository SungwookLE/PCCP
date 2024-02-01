#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> datas;
string answer;

string quard(int N, int i, int j)
{
    if (N == 1)
    {
        string ret = to_string(datas[i][j]); // 사이즈가 1이니 조기종료
        return ret;
    }

    char b = datas[i][j];

    string ret = "";
    for (int ii = i; ii < i + N; ++ii)
    {
        for (int jj = j; jj < j + N; ++jj)
        {
            if (b != datas[ii][jj])
            { // 4개 중 하나라도 다르면 쿼드 호출하고 종료
                ret += "(";
                ret += quard(N / 2, i, j);
                ret += quard(N / 2, i, j + N / 2);
                ret += quard(N / 2, i + N / 2, j);
                ret += quard(N / 2, i + N / 2, j + N / 2);
                ret += ")";
                return ret;
            }
        }
    }

    return to_string(datas[i][j]); // 4개 다 같으면
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

    cout << quard(N, 0, 0) << endl;
    return 0;
}