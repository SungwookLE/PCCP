#include <bits/stdc++.h>

using namespace std;

int A, B, C;
int main(){
    cin >> A >> B >> C;

    // (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C
    cout <<  (A+B)%C << endl
     <<  ((A%C) + (B%C))%C << endl 
     << (A*B)%C << endl 
     << ((A%C) * (B%C))%C << endl;


    return 0;
}