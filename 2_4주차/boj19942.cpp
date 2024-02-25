#include <bits/stdc++.h>
using namespace std;

int N;
int mp, mf, ms, mv;

vector<vector<int>> m;

int main()
{

    cin >> N;
    cin >> mp >> mf >> ms >> mv;

    m = vector<vector<int>>(N, vector<int>(5, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> m[i][j];
        }
    }

    /*
    0000000: 0
    0000001: 1
    0000010: 2
    0000011: 3
    ...
    */
    int min_C = 500 * 200;
    vector<string> ans;

    for (int i = 0; i < (1 << N); ++i)
    {

        int sum_p = 0, sum_f = 0, sum_s = 0, sum_v = 0, sum_c = 0;

        for (int j = 0; j < N; ++j)
        {
            // 비트 마스킹을 통한 조합 combination 획득
            if (i & (1 << j))
            {
                sum_p += m[j][0];
                sum_f += m[j][1];
                sum_s += m[j][2];
                sum_v += m[j][3];
                sum_c += m[j][4];
            }
        }

        if (sum_p >= mp && sum_f >= mf && sum_s >= ms && sum_v >= mv)
        {
            if (min_C > sum_c)
            {
                min_C = sum_c;
                string ret = "";
                for (int j = 0; j < N; ++j)
                {
                    if (i & (1 << j))
                    {
                        // ret += to_string(j+1); //<< 오답
                        ret += (char(j + 1) + '0'); // << 이렇게 해주니 비로소 정답
                    }
                }
                ans = {ret};
            }
            else if (min_C == sum_c)
            {
                string ret = "";
                for (int j = 0; j < N; ++j)
                {
                    if (i & (1 << j))
                    {
                        // ret += to_string(j+1); // << 오답
                        ret += (char(j + 1) + '0'); // << 이렇게 해주니 비로소 정답
                    }
                }
                ans.push_back(ret);
            }
        }
    }

    if (ans.empty())
        cout << -1;
    else
    {
        cout << min_C << "\n";
        sort(ans.begin(), ans.end());
        for (auto s : ans[0])
        {
            cout << int(s-'0') << " ";
        }
    }


    return 0;
}