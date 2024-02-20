#include <bits/stdc++.h>
using namespace std;

const int n = 4;
int main(){
    string a[n] = {"사과", "딸기", "포도", "배"};
    for (int i = 0 ; i < (1<<n) ; ++i){
        // i < 16 까지
        /* 그럼 비트로
        00001
        00010
        00011
        00100
        00101
        00110
        00111
        01000
        01001
        01010
        01011
        01100
        01101
        01110
        01111
        */
        string ret = "";
        for(int j = 0 ; j < n ; ++j){
            // j < 4 까지
            if (i & (1 << j)){ // 비트가 켜져 있는지 조회
                ret += (a[j] + " " );
            }
        }
        cout << ret << "\n";
    }
    return 0;
}