#include <bits/stdc++.h>

using namespace std;

int A, B;
int main(){
    cin >> A >> B;

    int n;
    map<int, int> m, m2;
    for(int i =0 ; i < A ; ++i){
        cin >> n;
        m[n] = 1;
    }

    int ans =0 ;
    for(int i = 0; i < B ; ++i){
        cin >> n;
        m2[n] = 1;
        if(m.count(n)==0) ans++;
    }

    for(auto it : m){

        if(m2.count(it.first)==0) ans++;
    }

    cout << ans;

    return 0;
}