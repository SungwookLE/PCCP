#include <bits/stdc++.h>

using namespace std;

int N;
int main(){
    cin >> N;

    vector<tuple<int, string, int>> v;

    int age; string name;
    for(int i =0 ; i < N ; ++i){
        cin >> age >> name;
        v.push_back(make_tuple(age, name, i));
    }

    sort(v.begin(), v.end(), [](auto a, auto b){

        if (get<0>(a) < get<0>(b)) return true;
        else if (get<0>(a) == get<0>(b)){

            return get<2>(a) < get<2>(b);
        }
        else return false;

    });

    for(auto vv: v){

        cout << get<0>(vv) << " " << get<1>(vv) <<"\n";

    }
   

 

    return 0;
}