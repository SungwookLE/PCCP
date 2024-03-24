#include <bits/stdc++.h>

using namespace std;

int N;
int LIS[1001], len;

int main(){
    cin >> N;

    int number;
    for(int i =0 ; i < N ; ++i){
        cin >> number;

        // 요소가 처음 등장하는 시점의 위치 이터레이터, 등장하지 않을 경우, LIS.end() 이터레이터 리턴
        auto lowerPos = lower_bound(LIS, LIS+len, number); 

        if(*lowerPos == 0) len++; // end() 위치 이터레이터의 값은 0인데, 이쪽을 가리켰다는 것은 가장 큰 값이라는 의미임, LIS의 길이가 길어졌다.
        *lowerPos = number; // lower_bound 위치에 값을 대입해준다.

        for(int j =0 ; j < N ; ++ j){
            cout << LIS[j] << " " ;
        }
        cout << endl;
    }

    cout << len;


    return 0;
}