#include <bits/stdc++.h>

using namespace std;

int Y;
int main(){
    cin >> Y;

    if ((Y%4== 0) && ((Y%100) || (Y%400==0))) cout << 1 ;
    else cout << 0;





    return 0;
}