#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
pair<int, int> Rs, Rg, Bs, Bg;
vector<vector<int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};

int solution(vector<vector<int>> maze) {
    int answer = 0;
    
    vector<vector<int>> _visited_R = vector<vector<int>>(maze.size(), vector<int>(maze[0].size(),0));
    vector<vector<int>> _visited_B = vector<vector<int>>(maze.size(), vector<int>(maze[0].size(),0));
    
    for(int i = 0 ; i < maze.size(); ++i){
        for(int j =0 ; j < maze[0].size(); ++j){
            if (maze[i][j] == 1) Rs = {i,j};
            else if (maze[i][j] == 2) Bs = {i,j};
            else if (maze[i][j] == 3) Rg = {i,j};
            else if (maze[i][j] == 4) Bg = {i,j};
        }
    }
    
    queue<vector<pair<int, int>>> candidates;
    queue<vector<vector<vector<int>>>> Vcandidates;
    
    candidates.push({Rs, Bs});
    _visited_R[Rs.first][Rs.second] = 1;
    _visited_B[Bs.first][Bs.second] = 1;
    Vcandidates.push({_visited_R, _visited_B});
    
    vector<vector<int>> visited_R , visited_B;
    bool FoundR = 0, FoundB = 0;
    while(candidates.size() && Vcandidates.size()){
        FoundR = false;
        FoundB = false;
        
        pair<int, int> Rnow = candidates.front()[0];
        pair<int, int> Bnow = candidates.front()[1];
        visited_R = Vcandidates.front()[0];
        visited_B = Vcandidates.front()[1];
        
        candidates.pop();
        Vcandidates.pop();
        
        if (Rnow.first == Rg.first && Rnow.second == Rg.second) FoundR = true;
        if (Bnow.first == Bg.first && Bnow.second == Bg.second) FoundB = true;
        
        if (FoundR && FoundB){
            break;
        }
        else if (FoundR == false && FoundB == false){ 
            for(int i =0 ; i < 4 ; ++i){
                int Rnext_i = Rnow.first + delta[i][0];
                int Rnext_j = Rnow.second+ delta[i][1];

                if (Rnext_i <0 || Rnext_i >= maze.size()) continue;
                if (Rnext_j <0 || Rnext_j >= maze[0].size()) continue;
                if(maze[Rnext_i][Rnext_j] == 5) continue;
                if(visited_R[Rnext_i][Rnext_j] != 0) continue;

                for(int j =0 ; j < 4; ++j){

                    int Bnext_i = Bnow.first + delta[j][0];
                    int Bnext_j = Bnow.second+ delta[j][1];

                    if (Bnext_i < 0 || Bnext_i >= maze.size()) continue;
                    if (Bnext_j < 0 || Bnext_j >= maze[0].size()) continue;
                    if (maze[Bnext_i][Bnext_j] == 5) continue;
                    if (visited_B[Bnext_i][Bnext_j] != 0) continue;
                    if (Rnext_i == Bnext_i && Rnext_j == Bnext_j) continue;
                    if (Rnext_i == Bnow.first && Bnext_i == Rnow.first 
                        && Rnext_j == Bnow.second && Bnext_j == Rnow.second) continue;
                    
                    candidates.push({{Rnext_i, Rnext_j}, {Bnext_i, Bnext_j}});
                    visited_R[Rnext_i][Rnext_j] = visited_R[Rnow.first][Rnow.second]+1;
                    visited_B[Bnext_i][Bnext_j] = visited_B[Bnow.first][Bnow.second]+1;
                    Vcandidates.push({visited_R, visited_B});
                    visited_R[Rnext_i][Rnext_j] = 0; // 원복
                    visited_B[Bnext_i][Bnext_j] = 0; // 원복
                }
                
            }
        }
        
        else if (!FoundR){
            for(int i =0 ; i < 4 ; ++i){
                int Rnext_i = Rnow.first + delta[i][0];
                int Rnext_j = Rnow.second+ delta[i][1];
                
                if (Rnext_i <0 || Rnext_i >= maze.size()) continue;
                if (Rnext_j <0 || Rnext_j >= maze[0].size()) continue;
                if(maze[Rnext_i][Rnext_j] == 5) continue;
                if(visited_R[Rnext_i][Rnext_j] != 0) continue;
                if(Rnext_i == Bnow.first && Rnext_j == Bnow.second) continue;
                
                candidates.push({{Rnext_i, Rnext_j}, Bnow});
                visited_R[Rnext_i][Rnext_j] = visited_R[Rnow.first][Rnow.second]+1;
                Vcandidates.push({visited_R, visited_B});
                visited_R[Rnext_i][Rnext_j] = 0; // 원복
                
            }            
        }
        
        else if (!FoundB){
            
            for(int i =0 ; i < 4 ; ++i){
                int Bnext_i = Bnow.first + delta[i][0];
                int Bnext_j = Bnow.second+ delta[i][1];
                
                if (Bnext_i <0 || Bnext_i >= maze.size()) continue;
                if (Bnext_j <0 || Bnext_j >= maze[0].size()) continue;
                if(maze[Bnext_i][Bnext_j] == 5) continue;
                if(visited_B[Bnext_i][Bnext_j] != 0) continue;
                if(Bnext_i == Rnow.first && Bnext_j == Rnow.second) continue;
                
                candidates.push({Rnow, {Bnext_i, Bnext_j}});
                visited_B[Bnext_i][Bnext_j] = visited_B[Bnow.first][Bnow.second]+1;
                Vcandidates.push({visited_R, visited_B});
                visited_B[Bnext_i][Bnext_j] = 0; // 원복
            } 
            
        }
    }
    
    
    if (FoundR && FoundB) answer = max(visited_R[Rg.first][Rg.second], visited_B[Bg.first][Bg.second])-1;
    else answer = 0;
    
    return answer;
}