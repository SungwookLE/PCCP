#include <bits/stdc++.h>

using namespace std;

int N, K;
deque<int> n;
int main(){
    cin >> N >> K;
    K--;

    for(int i = 1; i <= N; ++i){
        n.push_back(i);
    }

    vector<int> ret;

    int idx = 0;
    while(n.size()){

        idx = (idx+K)%n.size();

        ret.push_back(*(n.begin()+idx));
        n.erase(n.begin()+idx);


    }

    cout << "<";
    for(int i =0 ; i < ret.size()-1; ++i){
        cout << ret[i] << ", ";
    }
    cout <<ret.back()<<">";




    return 0;
}