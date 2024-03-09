#include <bits/stdc++.h>

using namespace std;

int A, B;

int main(){
    cin >> A >> B;



    int a = A * (B%10) ;
    int b = A * ((B%100) / 10);
    int c = A * (B/100);

    int ret = a + b*10 + c * 100;
    cout << a << endl << b << endl << c << endl << ret << endl;

    return 0;
}