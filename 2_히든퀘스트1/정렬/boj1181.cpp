#include <bits/stdc++.h>

using namespace std;

int N;
int main(){
    cin >> N;

    vector<string> v(N);
    for(int i =0 ; i < N ; ++i){
        cin >> v[i];

    }

  

    // sort(v.begin(), v.end());


  

    sort(v.begin(), v.end(), [](auto a, auto b){
        if (a.size() < b.size()) return true;
        else if (a.size() == b.size()){
            return a < b;
        }
        else return false;
    });

    auto it = unique(v.begin(), v.end());
    if (it != v.end()){
        v.erase(it, v.end());
    }

   
    for(auto vv : v) cout << vv <<"\n";






    return 0;
}