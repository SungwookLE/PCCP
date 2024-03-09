#include <bits/stdc++.h>

using namespace std;

int N;
int main(){
    cin >> N;

    vector<int> score = vector<int>(N,0);

    int mx = 0;
    double sum = 0;
    for(int i =0 ; i < N ; ++i){

        cin >> score[i];
        if (mx <score[i]) mx = score[i];

    }

    for(int i = 0 ; i < N ; ++i){

        sum += double(score[i])/double(mx) * 100.0;

    }


    cout.precision(5);
    cout << double(sum)/double(N) ;

    return 0;
}