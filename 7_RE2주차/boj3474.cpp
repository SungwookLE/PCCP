#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T;
ll NUM;

int main(){
    cin >> T;

    for(int i =0; i < T ; ++i){
        cin >> NUM;

        int cnt2= 0, cnt5=0;
        for(ll i = 2 ; i <=NUM; i*=2){ // 2의 거듭제곱
            cnt2 += NUM/i;
        }
        
        for(ll i = 5 ; i <=NUM; i*=5){ // 5의 거듭제곱
            cnt5+= NUM/i;
        }

        // 왜 팩토리얼이 아닌 NUM만 가지고 계산해도 되는걸까?
        cout << min(cnt2,cnt5) << endl;
    }


    return 0;
}