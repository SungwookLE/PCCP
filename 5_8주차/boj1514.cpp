#include <bits/stdc++.h>

using namespace std;
int N;
string CUR, PWD;
vector<int> C, P;
#define INIT 100000
int ans = INIT;

int go(vector<int> c, int count){
    int ret = INIT;

    if(count >= ans) return count;
    
    cout << count << ": " ;
    for(int i = 0 ; i < N ; ++i){
        cout << c[i] ;
    }
    cout << endl;
    
    bool isSame = true;
    for(int i = 0 ; i < N ; ++i){
        if (c[i] != P[i]){
            isSame = false;
            break;
        }
    }
    if (isSame){
        ans = count;
        return count;
    }

    vector<vector<int>> comb;
    for(int stride = 1; stride <=3; ++stride){
        for(int i = 0 ; i <= N-stride ; ++i){
            vector<int> temp;
            for(int j = i; j<(i+stride); ++j){
                temp.push_back(j);
            }
            comb.push_back(temp);
        }
    }
    for(auto idx: comb){
        for(int rot = 1; rot <= 3; ++rot){
            for(auto id : idx) c[id] = (c[id]+rot)%10;
            ret = min(ret, go(c, count+1));
            for(auto id : idx) c[id] = (c[id]+10-rot)%10;
        }

        for(int rot = 1; rot <= 3; ++rot){
            for(auto id : idx) c[id] = (c[id]+10-rot)%10;
            ret = min(ret, go(c, count+1));
            for(auto id : idx) c[id] = (c[id]+rot)%10;
        }
    }


    return ret;
}


// 현재 자물쇠의 상태와 세준이의 비밀번호가 주어질 때, 자물쇠를 최소 몇 번 돌려야 풀 수 있는지 구하는 프로그램
int main(){
    cin >> N;
    cin >> CUR >> PWD;
    C = vector<int>(N,0);
    P = vector<int>(N,0);

    for(int i = 0 ; i < N; ++i){
        C[i] = CUR[i]-'0';
        P[i] = PWD[i]-'0';    
    }

    cout << go(C, 0);

    return 0;
}