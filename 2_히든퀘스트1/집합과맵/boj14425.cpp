#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, int> m;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    string s;
    for(int i =0 ; i < N ; ++i){
        cin >> s;   
        m[s] += 1;
    }

    int cnt = 0;
    for(int i =0 ; i < M ; ++i){
        cin >> s;

        if (m[s]>0) {
            cnt++;
        }

    }
    cout << cnt;


    return 0;
}