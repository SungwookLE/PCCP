#include <iostream>
#include <vector>

using namespace std;

/*

8
0 1 0 1 1 0 0 0 
0 1 1 0 1 1 0 0
0 0 1 1 1 0 0 0
0 0 0 0 0 1 1 0
0 1 0 1 1 1 0 0
0 1 0 0 0 0 1 1
1 1 0 1 0 0 1 0
0 0 0 0 0 1 1 0

*/

int N;
vector<vector<int>> deltas = {{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<int>> aparts, marked;
vector<int> numbersOfComplex;


void DFS(int i , int j, int complex){

    aparts[i][j] = -1; // marking, 바로 방문
    marked[i][j] = complex;
    numbersOfComplex[complex]++;

    for(auto d: deltas){
        int next_i = i + d[0];
        int next_j = j + d[1];

        if (next_i >= 0 && next_j >= 0 && next_i < N && next_j < N){
            if (aparts[next_i][next_j] == 1)
                DFS(next_i, next_j, complex);
        }
    }

    return;
}

int main(){
    cin >> N;
    aparts = vector<vector<int>>(N, vector<int>(N, 0));
    marked = vector<vector<int>>(N, vector<int>(N, 0));
    numbersOfComplex = vector<int>(N*N,0);

    int count = 1;
    for(int i = 0 ; i < N; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> aparts[i][j];
        }
    }

    for(int i = 0 ; i < N; ++i){
        for(int j = 0 ; j < N ; ++j){
            if (aparts[i][j] == 1 ){
                DFS(i, j, count);
                count += 1;
            }
        }
    }

    cout << "--------------------\n";
    for(auto row: marked){
        for(auto element: row) cout << element << " ";
        cout << endl;
    }

    cout << "--------------------\n";
    sort(numbersOfComplex.begin()+1, numbersOfComplex.begin()+count);
    for(int i = 1 ; i < count ; ++i) 
        cout << numbersOfComplex[i] << " ";
    cout << endl;

    cout << count-1 << endl;



    return 0;
}