#include <bits/stdc++.h>

using namespace std;

int A, B, C;
int main(){
    cin >> A >> B;
    cin >> C;

    int minutes = A*60 +B;
    minutes += C;


    if (minutes >= 24*60){
        minutes -= 24*60;

    }

    cout << minutes/60 << " " << minutes%60 << endl;

    return 0;
}