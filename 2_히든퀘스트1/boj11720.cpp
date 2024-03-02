#include <bits/stdc++.h>

using namespace std;
int N;

int main(){
    cin >> N;
    string s;
    cin >> s;

    int sum = 0;
    for(int i = 0; i < N ; ++i){
        sum += (s[i]-'0');

    }
    cout << sum;



    return 0;
}