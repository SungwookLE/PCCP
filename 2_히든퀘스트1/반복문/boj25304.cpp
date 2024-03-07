#include <bits/stdc++.h>

using namespace std;
int X, N, a, b;
int main(){

    cin>> X;
    cin >> N;

    int ret = 0;
    for(int i = 0 ; i < N ;++i){

        cin >> a >> b;
        ret += a*b;

    }

    if (X==ret) cout << "Yes";
    else cout << "No";



    return 0;
}