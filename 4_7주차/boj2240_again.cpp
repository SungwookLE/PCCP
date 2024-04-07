#include <bits/stdc++.h>

using namespace std;

int T, W;
vector<int> A;
int DP[3][1005][35]; // 트리,T초동안,W횟수


int go(int tree, int idx, int cnt){

    int nextTree ;
    if (tree == 1) nextTree = 2;
    else nextTree = 1;

    if (idx == T){ // 기저사례
        // 만약 W번 다움직이라는게 문제의 조건이라면
        // if(idx==T) return cnt == W ? 0 : -1E9;
        // 을 통해서 cnt가 W가 아니라면, 최소값을 리턴시켜서 배제시키기

        
        return 0;
    }

    int &ret = DP[tree][idx][cnt]; // 메모이제이션
    if (ret != -1) return ret;


    // 로직
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