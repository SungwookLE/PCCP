#include <bits/stdc++.h>

using namespace std;

int A, B, V;
int main(){
    cin >> A >> B >> V;

    int days = (V-B)/(A-B);
    if ( (V-B)%(A-B) ) days++;
    cout << days;
    return 0;
}