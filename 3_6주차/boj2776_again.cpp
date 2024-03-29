#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
vector<int> A;


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for(int i =0 ; i < T ; ++i){

        cin >> N;
        A = vector<int>(N,0);

        for(int j =0 ; j < N ; ++j){
            cin >> A[j];
        }
        sort(A.begin(), A.end());
        cin >> M;
        int b;
        for(int j =0 ; j < M ; ++j){
            cin >> b;

            int left= 0 ;
            int right = N;

            bool found = false;

            while (left<=right){
                int mid = (left+right)/2;

                if (A[mid] < b){
                    left = mid+1;
                }
                else if (A[mid] > b){
                    right = mid-1;
                }
                else{
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