#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
string A, B;

string string_add(string a, string b){


    int sum = 0;
    string ret = "";
    while(a.size() || b.size() || sum){
        if (a.size()){
            sum += a.back() - '0';
            a.pop_back();
        }
        if (b.size()){
            sum += b.back() - '0';
            b.pop_back();
        }

        ret += (sum%10) + '0';
        sum /= 10;

    }
    reverse(ret.begin(), ret.end());

    return ret;
}


int main(){
    cin >> A >> B;

    cout << string_add(A,B);
    return 0;
}