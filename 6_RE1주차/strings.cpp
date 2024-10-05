#include <bits/stdc++.h>

using namespace std;

string dopa = "abcde";

int main(){

    // 자르기
    string dp = dopa.substr(0,3);
    cout << dp << endl;

    // 뒤집기
    reverse(dp.begin(), dp.end());
    cout << dp << endl;

    // 붙이기
    dp += "umzunsik";
    cout << dp << endl;


    cout << fixed << setprecision(2) << 1.123123 << endl;


    // 1-A부터 풀기 (10/5)
    return 0;
}