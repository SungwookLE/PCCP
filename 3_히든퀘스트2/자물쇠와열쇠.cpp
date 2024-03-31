#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<vector<int>> upDown =    {{-1,0}, {1,0}};
vector<vector<int>> leftRight = {{0,-1}, {0,1}};
map< vector<vector<int>>, int> visited;

bool keyin(vector<vector<int>>& key, vector<vector<int>>& lock, vector<int>start){
    bool ret = true;
    
    for(int i = 0; i < lock.size(); ++i){
        for(int j =0 ; j < lock[0].size(); ++j){
            int key_i = i+start[0];
            int key_j = j+start[1];
            int val = 0;
            if (key_i>=0 && key_i < key.size())
                if (key_j >= 0 && key_j < key[0].size())
                    val = key[key_i][key_j];
            
            if (lock[i][j] == 1){
                if (val == 1){
                    return false;
                }
            }
            else if (lock[i][j] == 0){
                if (val == 0){
                    return false;
                }
            }
        }
    }
    
    return ret;
}

void rotate90(vector<vector<int>>& key){
    vector<vector<int>> temp = key;
    for(int i =0 ; i < key.size(); ++i){
        for(int j =0 ; j < key[0].size(); ++j){
            key[j][key.size()-i-1] = temp[i][j];
        }
    }    
    return;
}

void debug(int idx, vector<vector<int>>& key, vector<vector<int>>& lock, vector<int> start){
    cout << "DEBUG(" <<idx << ")\n" ;
    cout << start[0] << " " << start[1] << endl;
    
    for(int i =0 ; i < lock.size(); ++i){
        for(int j =0 ; j < lock[0].size(); ++j){
            int key_i = i + start[0];
            int key_j = j + start[1];
            
            int val =0 ;
            if (key_i >=0 && key_i < key.size()){
                if(key_j >= 0 && key_j < key[0].size()){
                    val = key[key_i][key_j];
                }
            }
            cout << val ;
        }
        cout << endl;
    }
}


vector<vector<int>> checked(vector<vector<int>>& key, vector<vector<int>>& lock, vector<int> start){
    
    vector<vector<int>> v(lock.size(), vector<int>(lock[0].size(),0));
    for(int i =0 ; i < lock.size(); ++i){
        for(int j =0 ; j < lock[0].size(); ++j){
            int key_i = i + start[0];
            int key_j = j + start[1];
            
            int val =0 ;
            if (key_i >=0 && key_i < key.size()){
                if(key_j >= 0 && key_j < key[0].size()){
                    val = key[key_i][key_j];
                }
            }
            v[i][j] = val;
        }
    }
    return v;    
}


bool go(int idx, vector<vector<int>>& key, vector<vector<int>>& lock, vector<int> start){
    bool ret = false;
    //debug(idx, key, lock, start);
    
    if(keyin(key,lock, start)){
        return true;
    } 
    
    //if (idx == 40) return false; // 개수를 셀 필요가 없다. 모든 조합에 대해서 중복이 없을 때까지 반복 재귀호출 될테니
    
    for(auto& o1: upDown){
        
        start[0] += o1[0];
        start[1] += o1[1];
        vector<vector<int>> v = checked(key, lock, start);
        if (visited[v]  == 0){
            visited[v] = 1;
            if(go(idx+1, key, lock, start)) return true;
            //visited[v] = 0; // visited를 해제할 필요 없지. (다시 돌릴 필요 없지) 조합은 바뀌지 않을테니..,
        }
        
        start[0] -= o1[0];
        start[1] -= o1[1];
    }
    
    for(auto& o2: leftRight){
        start[0] += o2[0];
        start[1] += o2[1];
        
        vector<vector<int>> v = checked(key, lock, start);
        if (visited[v]  == 0){
            visited[v] = 1;
            if(go(idx+1, key, lock, start)) return true;
            //visited[v] = 0;   
        }
        
        start[0] -= o2[0];
        start[1] -= o2[1];
    }
    
    return ret;    
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    for(int i =0 ; i < 4; ++i){
        vector<vector<int>> v = checked(key, lock, {0,0});
        visited[v] = 1;
        if(go(0, key, lock, {0,0})) return true;
        rotate90(key);
    }
    
    return answer;
}