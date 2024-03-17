#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

void getRead(const string fname, vector<vector<string>>& m, pair<int, int>& s){

    ifstream openFile(fname);
    if (openFile.is_open()){
        string line, tok;
        int row = 0;
        while(getline(openFile, line)){
            m.push_back(vector<string>());
            istringstream iss(line);
            int col = 0;
            while (( iss >> tok) ) {
                m[row].push_back(tok);
                if (tok == "*") s = {row, col};
                col++;
            }
            row++;
        }
    }

    return;
}

void printMap(const vector<vector<string>> m){

    for(auto row : m){
        for(auto col : row) cout << col << " ";
        cout << endl;
    }

}

vector<vector<string>> space;
pair<int, int> start, goal;
vector<vector<int>> delta = {{-1, 0}, {0,-1}, {0,1}};
vector<string> delta_str = {"S", "L", "R"};

class CustomVisited{

    private:
        // Define a custom hasher for tuple<int, int, string>
        struct KeyHasher {
            std::size_t operator()(const std::tuple<int, int, std::string>& k) const {
                // Compute hash based on the hash values of individual tuple elements
                auto hash1 = std::hash<int>{}(std::get<0>(k));
                auto hash2 = std::hash<int>{}(std::get<1>(k));
                auto hash3 = std::hash<std::string>{}(std::get<2>(k));
                return hash1 ^ hash2 ^ hash3; // Combining hashes using XOR
            }
        };

        // Define a custom equality comparator for tuple<int, int, string>
        struct KeyEquals {
            bool operator()(const std::tuple<int, int, std::string>& lhs, const std::tuple<int, int, std::string>& rhs) const {
                return lhs == rhs; // Simply compare tuples for equality
            }
        };

    public:
        unordered_map<tuple<int,int,string>, int, KeyHasher, KeyEquals> v;
        void print(pair<int, int> goal, vector<vector<string>> space){

            for(int i = 0 ; i < space.size(); ++i){
                for(int j =0 ; j < space[0].size(); ++j){
                    int mn = 987654321;
                    for(auto d: delta_str){

                        if (v[{i,j,d}] != 0){
                            mn = min(mn, v[{i,j,d}]);
                        }

                    }
                    if (mn != 987654321) cout << mn << "\t";
                    else cout << "\t";
                }
                cout << endl;
            }

        }
};

CustomVisited visited;

void rrt(pair<int, int> n, pair<int, int> g){

    if ( n.first == g.first && n.second == g.second ){
        cout << "REACH" << endl;
        return;
    }

    for(int i =0 ; i < delta.size(); ++i){

        int next_i = n.first + delta[i][0];
        int next_j = n.second+ delta[i][1];

        if (next_i < 0 || next_j < 0 || next_i >= space.size() || next_j >= space[0].size()) continue;
        if (space[next_i][next_j] == "#") continue;
        if (visited.v[make_tuple(next_i, next_j, delta_str[i])] != 0) continue;

        int mn = 987654321;
        for(auto str: delta_str){
            if (visited.v[{n.first, n.second, str}] != 0){
                if (mn > visited.v[{n.first, n.second, str}])
                    mn = visited.v[{n.first, n.second, str}];
            }
        }
        visited.v[{next_i, next_j, delta_str[i]}] = mn+1;

        rrt({next_i, next_j}, g);
    }

    return;
}

int main(){

    getRead("map.txt", space, start);
    goal = {0, 0};
    printMap(space);
    visited.v[{start.first, start.second, "S"}] = 1;
    rrt(start, goal);
    visited.print(goal, space);


    return 0;
}