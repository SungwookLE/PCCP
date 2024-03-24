#include <bits/stdc++.h>

using namespace std;

int N;
int A[1001];

int main(){
    cin >> N;
    for(int i =0 ; i < N ; ++i) cin >> A[i];

    // 오름차순 정렬 되어있어야함!

    for(int i =0 ; i < N ; ++i){
        auto lowerPos = lower_bound(A, A+N, A[i]); // 요소가 처음 등장하는 시점의 위치 이터레이터
        cout << lowerPos-A << " ";
    }

    auto lowerPos = lower_bound(A, A+N, 10); // 없으면 A.end() 위치 이터레이터
        cout << lowerPos-A << " ";

    cout << endl;
    for(int i =0 ; i < N ; ++i){
        auto upperPos = upper_bound(A, A+N, A[i]); // 요소가 마지막 등장하는 시점의 다음 칸의 위치 이터레이터
        cout << upperPos-A << " ";
    }



    return 0;
}
