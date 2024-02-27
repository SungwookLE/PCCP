#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
string A, B;


// 문자열 뒤집어서 입력 받음
string splus(int idx, int up){

    string ret = "";
    if (idx >= B.size()) {

        for(int i = B.size() ; i < A.size(); ++i){
            int sum = int(A[i]-'0') + up;

            if (sum/10){
                up = sum/10;
                sum = sum%10;
            }
            else up = 0;
            ret += char(sum+'0');
        }
        reverse(ret.begin(), ret.end());

        if (up) return char(up+'0')+ret;
        else return ret;
    }

    int sum = int(A[idx]-'0') + int(B[idx]-'0') + up ;

    if (sum/10){
        ret += splus(idx+1, sum/10);
        sum = (sum%10);
        ret += char(sum+'0');
    }
    else{
        ret += splus(idx+1, 0);
        ret += char(sum+'0');
    }

    return ret;
}


int main(){
    cin >> A >> B;


    string temp = A;
    A = (A.size() > B.size()) ? A : B;
    B = (A.size() > B.size()) ? B : temp;
    
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    cout << splus(0, 0);


    return 0;
}