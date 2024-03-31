#include <bits/stdc++.h>

using namespace std;

int T;
int main(){
    cin >> T;


    string s;
    stack<char> stk;
    for(int i = 0 ; i < T; ++i){
        cin >> s;
        stk = stack<char>();

        for(int j =0 ; j < s.size(); ++j){

            
            if (stk.empty()) stk.push(s[j]);
            else{
                if (stk.top() == '(' && s[j] == ')') stk.pop();
                else stk.push(s[j]);
            }

        }
        
        if (stk.empty()) cout <<"YES\n";
        else cout << "NO\n";
    }

    return 0;
}