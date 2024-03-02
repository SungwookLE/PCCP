#include <bits/stdc++.h>

using namespace std;

string A, B;

int main(){

    cin >> A >> B;


    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());


    cout << (A>B? (A):(B));



    return 0;
}