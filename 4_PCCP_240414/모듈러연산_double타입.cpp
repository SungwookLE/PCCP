#include <bits/stdc++.h>

using namespace std;

int main(){

    // 그냥 '%' 연산자는 int간의 계산만 지원함
    // 만약 double 타입의 모듈러 연산을 하고 싶다면, fmod(a,b)를 사용하여야함
    double a, b;
    while(true){
        cin >> a >> b ;
        cout << fixed;
        cout.precision(3);
        cout << a << "%" << b << endl;

        cout << fmod(a,b) << endl;
        cout << (fmod(a,b) == 0) << endl;
    }
}