#include <bits/stdc++.h>

using namespace std;

int A, B;
int main(){

    while(cin >> A >> B){
        if (A==0 && B==0) break;

        if (A%B == 0) cout << "multiple\n";
        else if (B%A == 0) cout <<"factor\n";
        else cout <<"neither\n";

    }


    return 0;
}