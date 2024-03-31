#include <bits/stdc++.h>

using namespace std;

int H , M;

int main(){

    // -45분하기

    cin >> H >> M;
    int minutes = H*60+M;
    minutes -= 45;

    if (minutes < 0){
        minutes = 24*60 + minutes;
    }

    cout << minutes/60 << " "<< minutes%60 << endl;


    return 0;
}