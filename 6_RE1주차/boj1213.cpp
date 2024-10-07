#include <bits/stdc++.h>

using namespace std;

string N;
map<char, int> C;

void go(map<char, int>C, string& pre, string& cntr){

    int sum = 0;
    for(auto& c : C){
        while (c.second>=2){
            pre+= c.first;
            c.second-=2;
        }
        
        if (c.second ==1){
            cntr+=c.first;
            c.second-=1;
        }
    }
}

int main(){
    cin >> N;
    for(int i =0 ; i < N.size(); ++i){
        C[N[i]]++;
    }

    string pre, cntr, suf; 
    go(C, pre, cntr);
    suf = pre;
    reverse(suf.begin(), suf.end());

    string ans = pre + cntr+suf;

    string cmp = ans;
    reverse(cmp.begin(), cmp.end());
    if (cmp == ans){
        cout << ans << "\n";
    }
    else{
        cout << "I'm Sorry Hansoo\n";
    }





    return 0;
}