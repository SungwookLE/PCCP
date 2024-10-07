#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> mate;
int ans;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    mate.resize(N);

    for(int i =0 ; i < N ; ++i) cin >> mate[i];

    sort(mate.begin(), mate.end());

    auto s = mate.begin();
    auto e = mate.end()-1;

    while (s<e){

        if (*s+*e == M){
            ans ++;
            s = s+1;
            e = e-1;
        }
        else if (*s+*e < M){
            s = s+1;
        }
        else {
            e = e-1;
        }
    }

    cout << ans;

    return 0;
}