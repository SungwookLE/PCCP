#include <bits/stdc++.h>

using namespace std;



bool check(int n){

    if (n<2) return false;
    if (n==2) return true;

    for(int div = 2 ; div*div <= n ; ++div){

        if(n%div==0) return false;
    }

    return true;


}


int T;
int main(){
    cin >> T;
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> dp = vector<int>(1000001,-1);

    int n;
    for(int i =0 ; i < T; ++i){
        cin >> n;

        int cnt =0;
        for(int j = n; j>=n/2; --j){

            if (dp[j] == -1)
                dp[j] = check(j);

            if(dp[j]){
                if (dp[n-j] == -1)
                    dp[n-j] = check(n-j);
                if (dp[n-j]){
                    cnt++;
                } 
            }
        }

        cout << cnt << "\n";
    }


    return 0;
}