#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> Lecture;

// M: 블루레이의 개수
// 모든 기타 강의 동영상을 녹화 / 블루레이의 크기를 최소로 하고, M개의 블루레이는 모두 같은 크기어야한다.
// 가능한 블루레이의 크기 중 최소를 구하는 프로그램을 작성

int mn = 1000000001;

int check(int mid){
    int cnt = 1;

    int ret = 0;
    for(int i =0 ; i < N ; ++i){
        if (ret + Lecture[i] <= mid){
            ret += Lecture[i];
        }
        else{
            cnt += 1;
            ret = Lecture[i];
        }
    }

    return cnt <= M;
}

int main(){
    cin >> N >> M;
    Lecture = vector<int>(N,0);

    int left = 0;
    int right= 0;

    for(int i =0 ; i < N ; ++i){
        cin >> Lecture[i];
        right += Lecture[i];
        if (left < Lecture[i]) left = Lecture[i];
    } 


    while(left<=right){

        int mid = (left+right)/2;
        if (check(mid)){
            right = mid-1;
            if (mn > mid) mn = mid;
        }
        else left = mid+1;

    }

    cout << mn;









    return 0;
}