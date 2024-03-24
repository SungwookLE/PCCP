#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
int A[1000001], B[1000001];

int main(){

    cin >> T;
    for(int i =0 ; i < T; ++i){

        cin >> N;
        for(int a = 0; a < N ; ++a) cin >> A[a];

        cin >> M;
        for(int b = 0; b < M; ++b) cin >> B[b];
        
        sort(A, A+N);
        for(int b = 0; b < M; ++b){
            int left = 0;
            int right = N-1;
            int mid = 0;

            bool found = false;
            while(left<=right){
                mid = (left+right)/2;
                if (A[mid] > B[b]) right = mid-1;
                else if (A[mid] < B[b]) left = mid+1;
                else if (A[mid] == B[b]){
                    found = true;
                    break;
                }
            }

            if(found) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }

    return 0;
}