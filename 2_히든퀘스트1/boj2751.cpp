#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin >> N;
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v(N,0);
    for(int i = 0; i < N;++i){
        cin >> v[i];
    }


    sort(v.begin(), v.end());
    for(auto vv: v) cout << vv << "\n";

    return 0;
}