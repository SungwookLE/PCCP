#include <bits/stdc++.h>

using namespace std;

vector<string> s2 = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};
vector<string> s3 = {"dz="};

int main(){


    string S;
    cin >> S;

    int ret2 = 0;
    int ret3 = 0;

    for(int i =0  ; i < S.size() ; ++i){


        if (i>=1){ // 길이 2부터 검사 가능함

            string sub = S.substr(i-1, 2);

            for(auto s : s2){

                if (sub == s) {
                    ret2+=1;
                    break;
                }
            }
        }

        if (i >= 2){
            string sub = S.substr(i-2, 3);
            for(auto s : s3){
                if (sub == s){
                    ret3+=1;
                    ret2-=1;
                    break;
                }
            }
        }

    }

    cout << S.size()  - ret2 - (ret3*2);



    return 0;
}