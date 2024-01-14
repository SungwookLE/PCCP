#include <iostream>
#include <vector>

using namespace std;

/*
('24.1/6 아이디어는 맞췄는데, 확신이 안서가지고.... 흠.. 헤매었다.)
4 14
2 40
5 110
10 200
3 50

 */

int main(){

    int N ; // (1<=N<=1000)
    int K ; // (1<=K<=10000)

    cin >> N >> K;
    int weight, price;
    vector<pair<int, int> > WeightAndPrice;

    for(int i = 1 ; i <= N; ++i){
        cin >> weight >> price;
        WeightAndPrice.push_back({weight, price});
    }

    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
    
    for(int i = 1; i <= N; ++i){
        for(int j = 1 ; j <= K; ++j){
            if (j-WeightAndPrice[i-1].first >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-WeightAndPrice[i-1].first]+WeightAndPrice[i-1].second);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

   
    cout << endl;
    for (auto row: dp){
        for(auto c: row){
            cout << c << " ";
        }
        cout << endl;
    }

    cout << dp[N][K] << endl;

    return 0;
}