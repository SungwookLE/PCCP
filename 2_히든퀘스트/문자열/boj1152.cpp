#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    getline(cin, s);


    istringstream ss(s);
    string token;
    int cnt = 0;
    while(ss>>token) cnt++;

    cout << cnt;
    return 0;
}