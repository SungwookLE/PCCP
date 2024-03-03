#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
int main(){
    cin >> N;
    v=vector<int>(N);
    for(int i = 0 ; i < N ; ++i){
        cin >> v[i];

    }

    sort(v.begin(), v.end(), less<int>());
    for(auto vv: v) cout << vv << "\n";


    return 0;
}