#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int solution(vector<string> arr)
{
    int answer = -1;
    
    vector<int> numbers;
    vector<string> operations;
    
    for(int i = 0 ; i < arr.size(); ++i){
        if (i%2==0)
            numbers.push_back(stoi(arr[i]));
        else
            operations.push_back(arr[i]);
    }        
    
    vector<vector<int>> MAX_DP, MIN_DP;
    
    MAX_DP = vector<vector<int>>(numbers.size(), vector<int>(numbers.size(), -987654321));
    MIN_DP = vector<vector<int>>(numbers.size(), vector<int>(numbers.size(), +987654321));
    
    int n = numbers.size();
    
    for(int step = 0 ; step < n; ++step){
        for(int i =0 ; i < n-step; ++i){
            int j = i +step;
            
            
            if (step==0){
                MAX_DP[i][i] = numbers[i];
                MIN_DP[i][i] = numbers[i];
            }
            else{
                
                for(int k = i; k < j ; ++k){
                    
                    if(operations[k] == "+"){
                        // 이게 구해야 하는 점화식의 핵심이다.
                        MAX_DP[i][j] = max(MAX_DP[i][j], MAX_DP[i][k]+MAX_DP[k+1][j]); 
                        MIN_DP[i][j] = min(MIN_DP[i][j], MIN_DP[i][k]+MIN_DP[k+1][j]);
                    }
                    else{
                        MAX_DP[i][j] = max(MAX_DP[i][j], MAX_DP[i][k]-MIN_DP[k+1][j]);
                        // 빼기 연산의 최대값을 구하기 위해선 MIN 배열도 저장/관리해야한다.
                        MIN_DP[i][j] = min(MIN_DP[i][j], MIN_DP[i][k]-MAX_DP[k+1][j]);
                    }
                }
            }
        }
    }
    
    for(auto row: MAX_DP){
        for(auto ele: row){
            cout << setw(10) << ele << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(auto row: MIN_DP){
        for(auto ele: row){
            cout << setw(10) << ele << " ";
        }
        cout << endl;
    }
    
    answer = MAX_DP.front().back();
  
        
    
    
    return answer;
}