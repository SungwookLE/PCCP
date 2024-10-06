#include <bits/stdc++.h>

using namespace std;

int A, B, C;
int TS[101];

int main(){
    cin >> A >> B >> C;
    int a, b;
    for(int i = 0 ; i < 3 ; ++i){
        cin >> a >> b;
        for(int i = a ; i < b; ++i){
            TS[i] ++;
        }
    }
    int ANS = 0;
    for(int i = 0 ; i < 100 ; ++i){
        switch (TS[i])
        {
        case 1:
            ANS += A;
            break;
        case 2:
            ANS += (B*2);
            break;
        case 3:
            ANS += (C*3);
            break;
        }
    }
    cout << ANS;

    return 0;
}