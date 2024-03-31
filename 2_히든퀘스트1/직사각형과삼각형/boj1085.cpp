#include <bits/stdc++.h>

using namespace std;

int x, y,w ,  h;
int main(){
    cin >> x >> y >> w >> h;



    int mx = min(x-0, w-x);
    int my = min(y-0, h-y);

    cout << min(mx,my);

    return 0;
}