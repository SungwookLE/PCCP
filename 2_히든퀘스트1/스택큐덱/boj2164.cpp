#include <bits/stdc++.h>

using namespace std;

int N;
deque<int> n;
int main(){
    cin >> N;

    
    for(int i =0 ; i<N; ++i){
        n.push_back(i+1);
    }

    while(n.size()>1){

        n.pop_front();
        n.push_back(n.front());
        n.pop_front();

    }

    cout << n.front() ;


    return 0;
}