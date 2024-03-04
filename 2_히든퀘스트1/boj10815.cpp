#include <bits/stdc++.h>

using namespace std;

int M;
map<int, int> m;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;

    int n;
    for(int i = 0; i < M ; ++i){
        cin >> n;
        m[n] += 1;
    }

    cin >> M;
    for(int i = 0; i < M ; ++i){

        cin >> n;
        m[n] -= 1;

        if (m[n] >= 0) cout << 1 <<" ";
        else cout << 0 << " ";
    }

    return 0;
}