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
int numbers = 0;


void DFS(int i , int j, int complex){

    aparts[i][j] = -1; // marking, 바로 방문
    marked[i][j] = complex;
    numbers+=1;

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


    int count = 1;
    for(int i = 0 ; i < N; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> aparts[i][j];
        }
    }

    vector<int> numbersOfComplex;
    for(int i = 0 ; i < N; ++i){
        for(int j = 0 ; j < N ; ++j){
            numbers = 0;
            if (aparts[i][j] == 1 ){
                DFS(i, j, count);
                count += 1;
                numbersOfComplex.push_back(numbers);
            }
        }
    }

    cout << "--------------------\n";
    for(auto row: marked){
        for(auto element: row) cout << element << " ";
        cout << endl;
    }

    cout << "--------------------\n";
    sort(numbersOfComplex.begin(), numbersOfComplex.end());
    for(auto n : numbersOfComplex) cout << n << " ";
    cout << endl;

    cout << count-1 << endl;



    return 0;
}