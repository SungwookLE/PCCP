#include <bits/stdc++.h>

using namespace std;

int main(){

    string S;
    cin >> S;

    sort(S.begin(), S.end(), greater<char>());
    for(auto ss: S) cout<< ss;

    return 0;
}