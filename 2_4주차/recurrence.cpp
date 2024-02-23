#include <bits/stdc++.h>

using namespace std;

vector<int> m = { 0, 1, 2, 3, 4};
vector<int> visited(5,0);
int cnt = 0;
void go(int here, vector<int> ret){

    if (here > 2){
        cnt ++ ;
        for(auto r : ret) cout << r << " ";
        cout << endl;

        return;
    }
    
    for(int i = 0 ; i < 5; ++i){
        
        if (visited[i] == 0){
            visited[i] = 1;
            ret.push_back(m[i]);
            go(here+1, ret);
            ret.pop_back();
            visited[i] = 0;
        }

    }


}


int main(){


    go(0, {});
    cout << cnt << endl;


    return 0;
}