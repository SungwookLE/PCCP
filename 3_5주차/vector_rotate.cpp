#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> V = {1,2,3,4,5,6,7,8,9};

    cout << "반시계\n";
    rotate(V.begin(), V.begin()+1, V.end()); // 반시계 회전
    for(auto v : V) cout << v << " ";
    cout << endl;

    sort(V.begin(), V.end());
    cout << "시계\n";
    rotate(V.begin(), V.begin()+V.size()-1, V.end()); // 시계 회전
    for(auto v : V) cout << v << " ";


    return 0;
}