#include <bits/stdc++.h>

using namespace std;


vector<int> v(5,0);
int main(){

    int sum = 0;
    for(int i = 0; i < 5 ; ++i){
        cin >> v[i];
        sum += v[i];
    }


    cout << sum/5 << "\n";
    sort(v.begin(), v.end());
    cout << *(v.begin()+2);



    return 0;
}