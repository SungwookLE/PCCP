#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int N,M;

int solution(vector<vector<int>> ability) {
    int answer = 0;

    N = ability.size(); // 학생 수
    M = ability[0].size(); // 과목 수

    vector<int> idx = vector<int>(N,0);
    for(int i =0 ; i < N ; ++i) idx[i] = i;


    do{

        int id = 0;
        int sum = 0;

        for(int i = 0 ; i < M ; ++i){
            sum += ability[idx[id++]][i];
        }

        answer = max(answer, sum);


    } while(next_permutation(idx.begin(), idx.end()));




    return answer;
}