#include <bits/stdc++.h>

using namespace std;

int S;
int M, N;
vector<int> A, B;
vector<int> checked_A, checked_B;


int go(int start_A, int start_B, int sum, vector<int> Ar, vector<int> Br){
    
    int ret = 0;
    if (sum == S){
        for(auto e: Ar) cout << e << " ";
        for(auto e: Br) cout << e << " ";
        cout << endl;
        return 1;
    }
    else if (sum>S){
        return 0;
    }

    if (start_A < M){
        if (checked_A[start_A] == 0){

            if (Ar.empty() || (Ar.size() && (checked_A[(start_A-1)>=0?(start_A-1):(M-1)] == 1 || checked_A[(start_A+1)<M?(start_A+1):(0)] ==1 ))){
                checked_A[start_A] = 1;
                Ar.push_back(A[start_A]);
                ret+=go(start_A+1, start_B, sum + A[start_A], Ar, Br);
                checked_A[start_A] = 0;      
                Ar.pop_back();
            }
            ret+=go(start_A+1, start_B, sum, Ar, Br);
        }
    }
    
    else if (start_B < N){
        if (checked_B[start_B] == 0){
            if (Br.empty() || (Br.size() && (checked_B[(start_B-1)>=0?(start_B-1):(N-1)] == 1 || checked_B[(start_B+1)<N?(start_B+1):(0)] ==1 ))){
                checked_B[start_B] = 1;
                Br.push_back(B[start_B]);
                ret+=go(start_A, start_B+1, sum + B[start_B], Ar, Br);
                checked_B[start_B] = 0;
                Br.pop_back();
            }
            ret+=go(start_A, start_B+1, sum, Ar, Br);
        }
    }



    return ret;
}


int main(){
    cin >> S;
    cin >> M >> N;

    A = vector<int>(M,0);
    B = vector<int>(N,0);

    checked_A = vector<int>(M,0);
    checked_B = vector<int>(N,0);

    for(int i =0 ; i < M ; ++i) cin >> A[i];
    for(int i =0 ; i < N ; ++i) cin >> B[i];

    cout << go(0, 0, 0, {}, {});

    return 0;
}