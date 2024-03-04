#include <bits/stdc++.h>
using namespace std;

string S;
set<string> ret;

int main()
{
    cin.tie(NULL);


    cin >> S;

    for(int i = 0 ; i < S.size(); ++i){
        for(int j = 1; j <= S.size()-i; ++j){
            string part = S.substr(i, j);
            ret.insert(part);
        }
    }

    cout << ret.size();


    return 0;
}