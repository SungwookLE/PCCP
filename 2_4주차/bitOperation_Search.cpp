#include <bits/stdc++.h>
using namespace std;

int main(){

    int S = 20;
    int idx = (S&-S); // 10100 & 01100 --> 켜져있는 제일 낮은 자리의 비트 조회

    cout << idx << "\n"; // 2^2

}