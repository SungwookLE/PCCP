#include <bits/stdc++.h>

using namespace std;

string in;


bool check(string S){
    bool ret = false;
    stack<char> dish1;

    for(int i =0 ; i < S.size(); ++i){

        if (S[i] == ')' || S[i] == '('){
            if (dish1.empty()) dish1.push(S[i]);
            else{
                if (dish1.top() == '(' && S[i] == ')') dish1.pop();
                else dish1.push(S[i]);
            }

        }

        if (S[i] == ']' || S[i] == '['){
            if (dish1.empty()) dish1.push(S[i]);
            else{
                if (dish1.top() == '[' && S[i] == ']') dish1.pop();
                else dish1.push(S[i]);
            }
        }

    }

    if (dish1.empty() ) ret = true;
    return ret;
}

int main(){

    while(1){
        getline(cin, in);
        if (in == "."){
            return 0;
        }
        else{
            if(check(in)) cout << "yes\n";
            else cout << "no\n";
        }

    }

    return 0;
}