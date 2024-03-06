#include <bits/stdc++.h>

using namespace std;

int N;
int main(){
    cin >> N;
    
    stack<int> wait, fin;

    fin.push(0);

    int n;
    for(int i =0 ; i < N ; ++i){
        cin >> n;

        if (fin.top()+1 == n){
            fin.push(n);
        }
        else{ 
            wait.push(n);
        }

        int sz = wait.size();
        for(int i = 0 ; i <sz; ++i){
            if (wait.top() == fin.top()+1){
                fin.push(wait.top());
                wait.pop();
            }
        }
    }

    if (wait.empty()) cout << "Nice\n";
    else cout << "Sad\n";

    return 0;
}