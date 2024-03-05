#include <bits/stdc++.h>

using namespace std;

int T;
int main(){
    cin >> T;
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    long long ret = 0;
    bool check = true;

    for(int i = 0 ; i < T; ++i){
        cin >> n;
        
        for(;;++n){

            if (n<=1) continue;
            else if (n==2){
                ret = 2;
                break;
            }
            
            check =true;
            for(long long div = 2; div*div <= n; ++div){
                if (n%div==0){
                    check = false;
                    break;
                }
            }

            if(check){
                ret = n;
                break;
            }
        }

        cout<< ret <<"\n";

    }

    return 0;
}