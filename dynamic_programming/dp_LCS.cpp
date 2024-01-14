#include <iostream>
#include <vector>

using namespace std;

int main()
{

    string comp1, comp2;
    cin >> comp1 >> comp2;

    vector<vector<int>> dp(comp1.length() + 1, vector<int>(comp2.length() + 1, 0));

    for (int i = 1; i <= comp2.length(); ++i)
    {
        for (int j = 1; j <= comp1.length(); ++j)
        {
            if (comp2[i] == comp1[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    for (auto row : dp)
    {
        for (auto c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    cout << dp[comp1.length()][comp2.length()] << endl;

    return 0;
}