#include <bits/stdc++.h>

using namespace std;

int N;
int main(){

    while(cin >> N){

        if (N==-1) break;

        vector<int> v = {1};

        int vv = 2;
        int sum = 1;
        
        while(vv<N){

            if (N%vv == 0){
                sum += vv;
                v.push_back(vv);
            } 
            vv++;

        } 

        if (sum == N){
            cout << N << " = ";
            for(int i = 0 ; i < v.size()-1; ++i) cout << v[i] << " + ";
            cout << v.back();
        } else cout << N << " is NOT perfect.";
        cout << "\n";
    }


    return 0;
}