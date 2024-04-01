#include <iostream>
#include <vector>
using namespace std;


// 라인 스위핑 알고리즘을 떠올리고 풀었음.

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = w+1;
    int idx = 0;
    
    // 앞단 처리
    while (idx < stations.size() && stations[idx] <= start){
        start = stations[idx] + (2*w+1);
        idx++;
    }
    
    // 중간 처리
    int curr ;
    for( curr = start; curr<=n;  curr+=(2*w+1)){
        if (idx < stations.size() && curr >= stations[idx]){
            curr = stations[idx];
            idx++;
        }
        else answer += 1;
    }
    
    // 끝단 처리
    curr -= (2*w+1);
    while(curr+w < n){
        curr += 2*w+1;
        if (idx < stations.size() && curr >= stations[idx]){
            curr = stations[idx];
            idx++;
        }
        else answer += 1;
    }
    
    return answer;
}