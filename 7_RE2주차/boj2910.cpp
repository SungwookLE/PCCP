#include <bits/stdc++.h>
using namespace std;

// 빈도 정렬
int N, C;

unordered_map<int, vector<int>> Ns;

int main(){
    cin >> N >> C;

    int in;
    for(int i = 1 ; i <= N ; ++i)
    {
        cin >> in;
        if (Ns.count(in)){
            Ns[in][0]++;
            Ns[in][1]=in;
        }
        else{
            Ns[in] = {1, in, i};
        }
    }

    vector<vector<int>> comp;
    for(auto n : Ns){
        comp.push_back(n.second);
    }

    sort(comp.begin(), comp.end(), [](auto a, auto b){

        if (a[0] > b[0]) return true;
        else if (a[0] ==b[0]) return a[2] < b[2];
        else return false;

    });

    for(auto c : comp){

        for(int i = 0 ; i < c[0] ; ++i){
            cout << c[1] << " ";
        }

    }
    

    return 0;
}