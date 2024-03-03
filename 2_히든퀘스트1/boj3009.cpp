#include <bits/stdc++.h>

using namespace std;

int A, B;
map<int, int> m1, m2;

int main(){
    for(int i =0 ; i < 3; ++i){
        cin >> A >> B;
        m1[A] +=1;
        m2[B] +=1;
    }

    for(auto it : m1){
        if (it.second == 1) cout << it.first << " ";
    }

    for(auto it : m2){
        if (it.second == 1) cout << it.first << " ";
    }


    return 0;
}