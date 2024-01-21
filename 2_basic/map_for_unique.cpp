#include <bits/stdc++.h>

using namespace std;

int main(){


    vector<int> A = {1,1,2,2,3,3};
    map<int, int> mp;
    for(auto a : A){

        if(mp[a])
            continue;;
        mp[a] = 1;
    }

    for(auto m : mp)
        cout << m.first << " ";
    cout << endl;

}