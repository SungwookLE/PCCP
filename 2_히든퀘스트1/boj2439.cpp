#include <bits/stdc++.h>

using namespace std;
int N;
int main(){
    cin >> N;


    for(int i = 1 ; i <= N ; ++i){
        string s(N,' ');

        for(int j = 1 ; j <= i ; ++j){
            s[N-j] = '*';
        }

        cout << s << "\n";
    }


    return 0;
}