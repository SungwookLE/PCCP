#include <iostream>
#include <vector>

using namespace std;

/*

4 14
2 40
5 110
10 200
3 50

 */

int main()
{

    int N; // (1<=N<=1000)
    int K; // (1<=K<=10000)

    cin >> N >> K;
    int weight, price;
    vector<pair<int, int>> WeightAndPrice = {{0, 0}};

    for (int i = 1; i <= N; ++i)
    {
        cin >> weight >> price;
        WeightAndPrice.push_back({weight, price});
    }

    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

    for (int j = 1; j <= N; ++j)
    {
        for (int i = 1; i <= K; ++i)
        {
            if (i >= WeightAndPrice[j].first)
                dp[i][j] = max(dp[i][j - 1], dp[i - WeightAndPrice[j].first][j - 1] + WeightAndPrice[j].second);
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    cout << endl;
    for (auto row : dp)
    {
        for (auto c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    cout << dp[K][N] << endl;

    return 0;
}