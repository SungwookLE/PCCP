#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;

    cin >> s;

    string comp =s;
    reverse(comp.begin(), comp.end());

    cout << ( comp == s ? (1):(0));



    return 0;
}