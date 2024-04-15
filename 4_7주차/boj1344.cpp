#include <bits/stdc++.h>

using namespace std;

double A, B;
double ret;

double DP[20][20][20]; // [A골][B골][idx]

bool isPrime(int num){

    if (num == 0) return false;
    if (num == 1) return false;
    if (num == 2) return true;

    for(int i = 2; i<=num/2; ++i){
        if (num%i==0) return false;
    }
    return true;

}

double goal(int a, int b, int idx){

    if (idx == 18){
        if (isPrime(a) || isPrime(b)){
            return 1; // 조건을 만족했을 때 1을 리턴
        }
        return 0;
    }

    double& ret = DP[a][b][idx];
    if(ret>=0) return ret;

    ret = 0.0;

    ret += A*(1.0-B)*goal(a+1, b, idx+1); // 각각의 경우에 대한 확률을 더함
    ret += (1.0-A)*B*goal(a, b+1, idx+1);  // 각각의 경우에 대한 확률을 더함
    ret += (1.0-A)*(1.0-B)*goal(a, b, idx+1);
    ret += A*B*goal(a+1, b+1, idx+1);

    return ret;
}


int main(){
    // 적어도 한 팀이 골을 소수로 득점할 확률을 출력한다.
    int a, b;
    cin >> a >> b;
    A = 0.01*(double)a;
    B = 0.01*(double)b;
    
    fill(&DP[0][0][0], &DP[0][0][0]+sizeof(DP)/sizeof(double), -0.5);

    ret = goal(0,0,0);
    
    cout << fixed;
    cout << setprecision(10);
    cout << ret;

    return 0;
}