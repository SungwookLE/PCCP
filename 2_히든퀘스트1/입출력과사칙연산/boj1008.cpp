#include <bits/stdc++.h>
using namespace std;

int A, B;
int main(){
    cin >> A >> B;

    double ret = double(A) / double(B);
    cout.precision(15);
    cout << ret;

    return 0;
}