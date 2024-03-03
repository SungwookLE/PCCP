#include <bits/stdc++.h>

using namespace std;

int N;
int main(){
    cin >> N;
    vector<pair<int, int>> arr;

    int num;
    for(int i =0 ; i < N ; ++i){
        cin >> num;
        arr.push_back({num, i});
    }

    vector<pair<int, int>> c = arr;
    sort(arr.begin(), arr.end());

    int idx =-1;
    int prev_val = 2*1000000000;
    for(auto a : arr){
        

        if (prev_val != a.first)
            idx ++;

        c[a.second].second = idx;
        prev_val = a.first;
    }

    for(auto cc: c) cout << cc.second << " ";

    return 0;
}