#include <bits/stdc++.h>

using namespace std;

int T, W;
vector<int> I;
int mx = 0;
int DP[1001][3][31];


// tree: 트리번호
// cnt: 움직인 횟수
int go(int idx, int tree, int cnt){

    int another_tree;
    if (tree==1) another_tree =2;
    else another_tree =1;

    if (idx == T) return 0; // 기저사례

    int &ret = DP[idx][tree][cnt]; // 메모이제이션
    if (ret) return ret;


    // 로직
    if (cnt > 0) ret  = max(go(idx+1, another_tree, cnt-1), go(idx+1, tree, cnt)) + (tree == I[idx]? 1:0);
    else ret = go(idx+1, tree, cnt) + (tree==I[idx]? 1:0);

    return ret;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T >> W;
    // 초기화
    I = vector<int>(T,0);

    for(int i =0 ; i < T; ++i){
        cin >> I[i];
    }

    cout << max(go(0, 2, W-1), go(0, 1, W));


    return 0;
}