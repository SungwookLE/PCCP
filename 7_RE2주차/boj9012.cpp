#include <bits/stdc++.h>

using namespace std;

int T;
string cmp;

bool check(string c){
    bool ret = false;
    stack<char> dish;

    for(int i = 0; i < c.size(); ++i){

        if (dish.empty()) dish.push(c[i]);
        else{

            if (dish.top() == '(' && c[i] == ')'){
                dish.pop();
            }
            else{
                dish.push(c[i]);
            }
        }
    }

    if (dish.empty()) ret = true;

    return ret;
}


int main(){
    cin >> T;

    for(int i =0 ; i < T ; ++i){
        cin >> cmp;
        if (check(cmp)){
            cout << "YES\n";
        }
        else{
            cout <<"NO\n";
        }
    }


    return 0;
}