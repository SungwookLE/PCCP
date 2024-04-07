#include <bits/stdc++.h>

using namespace std;


int N;
// DP[날짜][visited]
map<vector<long long>, long long> DP;
vector<int> A;

long long go(int idx, int w, int v, int cnt, int NN){


    if (cnt >= (idx+1)-cnt) return 0;

    if (idx == 2*NN){
        if (w==1){
            if (cnt == NN){
                // for(int i = 0 ; i < idx ; ++i)
                // {
                //     if (v&(1<<i)) cout << 1 << " ";
                //     else cout << 0 << " ";
                // }
                // cout << endl;
                return 1;
            }
        }
        return 0;
    }

    long long& ret = DP[{idx, v}];
    if (ret) return ret;

    ret += (go(idx+1, w^1, v|((w^1)<<idx), cnt+(((w^1)==1)?1:0), NN) + go(idx+1, w, v|((w)<<idx), cnt+((w==1)?1:0), NN));

    return ret;
}


int main(){

    while (cin >>N){
        if (N==0) break;
        A.push_back(N);
    }

    for(auto a : A){
        // W면 0 , H면 1
        DP = map<vector<long long>, long long>();
        cout << go(1, 0, 0, 0, a) << endl;
    }

    return 0;
}