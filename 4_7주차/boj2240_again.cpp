#include <bits/stdc++.h>

using namespace std;

int T, W;
vector<int> A;
int DP[3][1005][35]; // 트리,T초동안,W횟수


int go(int tree, int idx, int cnt){

    int nextTree ;
    if (tree == 1) nextTree = 2;
    else nextTree = 1;

    if (idx == T){
        return 0;
    }

    int &ret = DP[tree][idx][cnt];
    if (ret != -1) return ret;

    if (cnt == W){
        ret = go(tree, idx+1, cnt)+(tree==A[idx]?1:0);
    }
    else{
        ret = max(go(tree,idx+1, cnt), go(nextTree, idx+1, cnt+1)) + (tree==A[idx]?1:0);
    }

    return ret;
}



int main(){

    cin >> T >> W;
    A = vector<int>(T,0);
    for(int i =0 ; i < T; ++i){
        cin >> A[i];
    }

    memset(DP, -1, sizeof(DP));

    cout << max(go(1, 0, 0), go(2,0,1));



    return 0;
}