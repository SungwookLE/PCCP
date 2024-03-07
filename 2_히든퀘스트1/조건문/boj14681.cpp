#include <bits/stdc++.h>

using namespace std;

int X, Y;

int main(){
    cin >> X >> Y;


    int bool1 = X>0;
    int bool2 = Y>0;

    if (bool1 && bool2) cout << 1;
    else if(!bool1 && !bool2) cout << 3;
    else if(!bool1 && bool2) cout << 2;
    else if(bool1 && !bool2) cout << 4;

    return 0;

}