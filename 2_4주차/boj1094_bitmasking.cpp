#include <bits/stdc++.h>
using namespace std;
int n, ret = 1;

int main(){


    // 2진수에서 1의 개수를 세기
    cin >> n;
    while (n != 1){
        if (n%2) ret ++;
        n >>= 1;
    }

    cout << ret ;
    cout << endl;


    // 16진수로 표현하기
    cin >> n;
    vector<int> v;
    while( n>1 ){
        v.push_back(n%16);
        n >>= 4;
    }
    v.push_back(n);
    reverse(v.begin(), v.end());

    for(auto vv: v) cout << vv << " ";
    cout << endl;

    for(int a: v){
        if (a>=10) cout << char(a+55);
        else cout << a ;
    }
    
    return 0;
}