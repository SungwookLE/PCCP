#include <bits/stdc++.h>

using namespace std;


int N;
vector<int> A;
vector<int> visited(100001,0);

int main(){
    cin >> N;
    A = vector<int>(N,0);
    for(int i =0 ; i < N ; ++i) cin >> A[i];

    auto s = A.begin();
    auto e = A.begin();

    long long ret = 0;
    while ( e < A.end()){

        if (!visited[*e]){
            // 안겹치니까 다음으로 이동
            visited[*e]++;
            e++;
        }

        else{
            // 겹치는게 등장하면 끊어주기 (s를 땡겨줌으로써)
            // s보다 이전에 있던 visited는 0으로
            ret += (e-s);
            visited[*s]--;
            s++;
        }
    }

    ret += (e-s)*(e-s+1)/2; // 등차수열의 합
    cout << ret;


    return 0;
}