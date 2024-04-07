#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> DP;
vector<vector<int>> Trace;
int main(){

    cin >> N;
    DP = vector<int>(N+10);
    Trace = vector<vector<int>>(N+10);

    DP[1] = 0;
    Trace[1] = {1};

    DP[2] = 1;
    Trace[2] = {2,1};

    DP[3] = 1;    
    Trace[3] = {3,1};

    for(int i = 4 ; i <= N; ++i){

        if (i%3==0 && i%2==0){

            int idx = 0;

            int val = min(min(DP[i/3], DP[i/2]), DP[i-1]);
            if (val == DP[i/3]) idx = i/3;
            else if (val == DP[i/2]) idx = i/2;
            else idx = i-1;

            DP[i] = DP[idx]+1;
            Trace[i].push_back(i);
            Trace[i].insert(Trace[i].end(), Trace[idx].begin(), Trace[idx].end());

        }
        else if (i%3==0){
            int idx = 0;
            if (DP[i/3] < DP[i-1]) idx = i/3;
            else idx = i-1;
            
            DP[i] = DP[idx]+1;
            Trace[i].push_back(i);
            Trace[i].insert(Trace[i].end(), Trace[idx].begin(), Trace[idx].end());
        
        }
        else if (i%2==0){
            int idx = 0;
            if (DP[i/2] < DP[i-1]) idx = i/2;
            else idx = i-1;
            
            DP[i] = DP[idx]+1;
            Trace[i].push_back(i);
            Trace[i].insert(Trace[i].end(), Trace[idx].begin(), Trace[idx].end());

        }
        else{
            
            DP[i] = DP[i-1]+1;
            Trace[i].push_back(i);
            Trace[i].insert(Trace[i].end(), Trace[i-1].begin(), Trace[i-1].end());
        
        }
    }


    int ret = DP[N];
    cout << ret << "\n";

    for(auto t : Trace[N])
        cout << t << " ";


    return 0;
}