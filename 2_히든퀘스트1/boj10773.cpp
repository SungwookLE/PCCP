#include <bits/stdc++.h>

using namespace std;

int K;
stack<int> s;
int main(){
    cin >> K;


    int n;
    for(int i =0 ; i < K ; ++i){
        cin >> n;

        if (n!=0) s.push(n);
        else s.pop();

    }

    int sum =0 ;
    while(s.size()){

        sum += s.top();
        s.pop();
    }

    cout << sum;


    return 0;
}