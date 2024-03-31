#include <bits/stdc++.h>

using namespace std;

int N;
int main(){
    cin >> N;
    int x, y;
    vector<pair<int, int>> v;
    for(int i = 0; i < N ; ++i){
        cin >> x >> y;
        v.push_back({x,y});
    }

    sort(v.begin(), v.end(), [](auto a , auto b){
        if (a.second < b.second) return true;
        else if (a.second == b.second){
            if (a.first < b.first) return true;
            else return false;
        }
        return false;
    });
    for(auto vv: v){
        cout << vv.first << " " << vv.second << "\n";
    }


    return 0;
}