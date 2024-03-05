#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){

    while(a%b){
        int mod = a %b;
        a = b;
        b = mod;
    }
    return b;

}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}
int N;
int main(){
    cin >> N;

    int ret =0;
    
    // 약수의 개수가 홀수개라는 것은
    // 열기 -> 닫기 -> 열기 (3회) 창문이 열려있다는 의미임
    // 약수의 개수가 홀수개라는 의미는 제곱수라는 의미임
    // 즉 제곱수를 찾는 문제다

    for(int i =1 ; i *i <= N; ++i)
        ret ++;
    cout << ret;

    return 0;
}