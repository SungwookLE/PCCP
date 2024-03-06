#include <bits/stdc++.h>

using namespace std;

string s;

int main(){

    while(getline(cin, s)){


        if (s==".") break;
        
        stack<char> st;
        for(int i =0 ; i < s.size()-1; ++i){

            if (s[i] == '(' || s[i] == ')' 
                || s[i] == '[' || s[i] == ']'){
                
                if (st.empty()) st.push(s[i]);
                else{

                    if (st.top() == '(' && s[i] == ')') st.pop();
                    else if (st.top() =='[' && s[i] == ']') st.pop();
                    else st.push(s[i]);
                }

            }

        }

        if (st.size()) cout << "no\n";
        else cout << "yes\n";

    }




    return 0;
}