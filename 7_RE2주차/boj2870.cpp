#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> Numbers;

void extract(int idx, string cmp, const string S){

    if (idx == S.size()){
        if (!cmp.empty()){
            Numbers.push_back(cmp);
            cmp = {};
        }
        return;
    }

    if (S[idx]-'0' >= 0 && S[idx]-'0' <= 9){
        if (cmp.size()>0 && cmp.front()=='0') cmp = S[idx];
        else cmp += S[idx];
    }
    else{
        if (!cmp.empty()){
            Numbers.push_back(cmp);
            cmp = {};
        }
    }

    extract(idx+1, cmp, S);
}

int main(){
    cin >> N;
    string S;
    for(int i =0 ; i < N ; ++i){
        cin >> S;
        extract(0, {}, S);
    }

    sort(Numbers.begin(), Numbers.end(), [](auto a, auto b){
        if (a.size() < b.size()) return true;
        else if (a.size() == b.size()){
            return a <b;
        }
        else return false;
    });
    for(auto n : Numbers){
        cout << n << endl;
    }

    return 0;
}