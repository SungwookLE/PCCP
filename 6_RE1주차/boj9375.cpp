#include <bits/stdc++.h>

using namespace std;
int T, N;

unordered_map<string, int> clothes;

int main(){
    cin >> T;

    for(int i =0 ; i < T ; ++i){

        cin >> N;
        string category, _;
        for(int j =0 ; j < N ; ++j){
            cin >> _ >> category;
            clothes[category] ++;
        }
        int ans = 1;
        for(auto r = clothes.begin(); r!=clothes.end(); r++){
            ans *= (r->second+1);
        }

        cout << ans-1 << "\n";
        clothes.clear();
    }


    return 0;
}