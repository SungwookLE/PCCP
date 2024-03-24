#include <bits/stdc++.h>

using namespace std;

int N;
int A[1001], CNT[1001], prevList[1001];
int ret=1, idx;

void go(int idx, vector<int>& ret){
    
    if (idx == -1) return;

    ret.push_back(A[idx]);
    go(prevList[idx], ret);
    return;
}

int main(){

    cin >> N;
    for(int i =0 ; i < N ; ++i){
        cin >> A[i];
    }

    fill(CNT, CNT+N, 1);
    fill(prevList, prevList+N, -1);

    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < i; ++j){

            if (A[j] < A[i]){
                if (CNT[i] < CNT[j]+1){

                    CNT[i] = CNT[j]+1;
                    prevList[i] = j;

                    if (ret < CNT[i]){
                        ret = CNT[i];
                        idx = i;
                    }
                }
            }
        }
    }

    cout << ret << endl;

    vector<int> list ={};
    go(idx, list);
    reverse(list.begin(), list.end());
    for(auto r : list){
        cout << r << " ";
    }
    cout << endl;


    return 0;

}