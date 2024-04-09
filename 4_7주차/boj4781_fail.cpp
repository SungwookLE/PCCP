#include <bits/stdc++.h>

using namespace std;

int n, m;
double M, p;
vector<int> calories;
vector<int> prices;
vector<int> DP;

int go(int idx, int pTotal, int cTotal){
    if (pTotal > m) return 0;

    int& ret = DP[pTotal]; // << (실패, 이런식으로 하면 감각적으로 DP가 될 것이라 생각했으나 아님, 4/8)
    if(ret != 0) return ret;

    ret = cTotal;
    for(int i =0 ; i < n ; ++i){
        if (pTotal + prices[i] <= m){
            ret = max(ret, go(idx+1, pTotal + prices[i], cTotal + calories[i]));
        }
    }


    return ret;
}

int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){

        cin >> n >> M;
        m = static_cast<int>(M*100+0.5);
        if (n==0 && m==0 ) break;

        calories = vector<int>(n,0);
        prices = vector<int>(n,0);
        DP = vector<int>(50000010,0);

        for(int i =0 ; i < n; ++i){
            cin >> calories[i];
            cin >> p;
            prices[i] = static_cast<int>(p*100+0.5);
        }

        cout << go(0, 0, 0);
            
    }


    return 0;
}