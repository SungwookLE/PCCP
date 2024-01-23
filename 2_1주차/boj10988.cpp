#include <bits/stdc++.h>

using namespace std;

int main(){

    string A;
    cin >> A;

   
    for(int i = 0 ; i < A.length()/2; ++i){

        if (*(A.begin() + i) == *(A.end() -(i+1)))
            continue;
        else{
            cout << 0 << "\n";
            return 0;
        }
    }

    cout << 1 << "\n";
    return 0;

}