#include <bits/stdc++.h>
using namespace std;

int T;
int N, M;
vector<int> A, B;

int main(){

    cin >> T;
    for(int i =0 ;i < T ; ++i){
        cin >> N >> M;
        A = vector<int>(N,0);
        B = vector<int>(M,0);

        for(int i =0 ; i < N ; ++i){
            cin >> A[i];
        }

        for(int i =0 ; i < M ; ++i){
            cin >> B[i];
        }
        cout << endl;
        sort(B.begin(), B.end());
        int ret = 0;
        for(int i =0 ; i < N ; ++i){

            auto it = lower_bound(B.begin(), B.end(), A[i]);
            // lower bound: 요소가 첫번째로 등장한 위치 이터레이터를 반환함, 
            // B보다 큰 수여서 찾지 못하면 B.end() 위치 이터레이터 반환
            // B보다 사이 어떤 값이지만 없는 수라면 Value < B[i] 시점의 위치 이터레이터 반환함
 

            ret += it -B.begin();

            cout << it - B.begin() << ": " << *it << " " << A[i] << endl;

        }
        cout <<ret<<endl;
    }


    return 0;
}