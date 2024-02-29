#include <bits/stdc++.h>

using namespace std;

int n;
string s;
stack<int> stk;
vector<int> d;

int main(){
    cin >> n;
    cin >> s;

    d = vector<int>(n,0);

    int ret = 0;
    for(int i = 0 ; i < n ; ++i){

        if (s[i] == '(') stk.push(i);
        else if (stk.size()){
            d[stk.top()]= 1;
            d[i] = d[stk.top()];
            stk.pop();
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < n ; ++i){
        if (d[i]) {
            cnt ++ ;
            ret = max(ret, cnt);
        }
        else cnt = 0;
    }

    cout << ret;    

   
    return 0;
}