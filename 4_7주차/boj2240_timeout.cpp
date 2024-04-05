#include <bits/stdc++.h>

using namespace std;

int T, W;
vector<int> I;
int mx = 0;

void go(int g, int idx, int tree, int cnt){

    if (idx == T){
        cout << g << " ";
        if (mx < g) mx = g;
        return;
    }

    if (cnt == W){
        go(g + (I[idx]==tree? 1:0), idx+1, tree, cnt);
    }
    else{

        int next_tree;
        if (tree == 1) next_tree= 2;
        else next_tree =1;

        go(g + (I[idx]==tree? 1:0), idx+1, next_tree, cnt+1);
        go(g + (I[idx]==tree? 1:0), idx+1, tree, cnt);
    }

    return;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T >> W;
    I = vector<int>(T,0);

    for(int i =0 ; i < T; ++i){
        cin >> I[i];
    }

    // 완전탐색으로
    go(0, 0, 1, 0);

    cout << endl << mx ;

    return 0;
}