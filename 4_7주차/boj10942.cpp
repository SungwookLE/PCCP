#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
int M;
vector<pair<int, int>> Q;
int DP[2001][2001];


int go(pair<int, int> q){


    if (q.first >= q.second){
        return true;
    }

    int& ret = DP[q.first][q.second];
    if (ret!=-1) return ret;

    if(A[q.first] == A[q.second]){
        ret = go({q.first+1, q.second-1});
    }
    else return false;

    return ret;
}

int main(){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N ;
    A = vector<int>(N,0);

    for(int i =0 ; i < N ; ++i){
        cin >> A[i];
    }

    fill(&DP[0][0], &DP[0][0]+sizeof(DP)/sizeof(int), -1);

    cin >> M;
    Q = vector<pair<int, int>>(M);
    for(int i =0 ; i < M ; ++i){
        cin >> Q[i].first >> Q[i].second;
        Q[i].first--;
        Q[i].second--;
    }

    for(int i = 0 ; i < M ; ++i)
        cout << go(Q[i]) <<"\n";


    return 0;
}