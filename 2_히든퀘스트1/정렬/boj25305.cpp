#include <bits/stdc++.h>

using namespace std;

int N, k;
vector<int> scores;

int main(){
    cin >> N >> k;

    scores = vector<int>(N,0);

    for(int i =0 ; i < N ; ++i){
        cin >> scores[i];
    }

    sort(scores.begin(), scores.end(), greater<int>());
    cout << scores[k-1] ;



    return 0;
}