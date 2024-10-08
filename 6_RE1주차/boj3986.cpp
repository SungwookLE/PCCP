#include <bits/stdc++.h>

using namespace std;

int N;
int ans;

int main(){
    cin >> N;
    string cmp;
    for(int i =0 ; i < N ; ++i){
        cin >> cmp;

        stack<char> stk;
        for(auto c : cmp){

            if (stk.empty()){
                stk.push(c);
            }
            else{

                if (stk.top() == c){
                    stk.pop();
                }
                else{
                    stk.push(c);
                }
            }
        }

        if (stk.empty()){
            ans++;
        }

    }

    cout << ans;


    return 0;
}