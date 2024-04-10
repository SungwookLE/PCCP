#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> Paper(10, vector<int>(10,0));
#define INFI 987654321
int DP[6][6][6][6][6];

bool match(pair<int, int> start, int sz){
    vector<vector<int>> nextPaper = Paper;
    for(int i = start.first; i < start.first+sz; ++i){
        for(int j = start.second; j < start.second+sz; ++j){
            if (i >= 10 || j >= 10) return false;

            if(Paper[i][j] == 1){
                nextPaper[i][j] = 0;
            }
            else{
                return false;
            }
        }
    }

    Paper = nextPaper;
    return true;
}

bool isClear(){

    for(int i =0 ; i < 10 ; ++i){
        for(int j =0 ; j < 10; ++j){
            if (Paper[i][j] == 1) return false;
        }
    }

    return true;
}


int go(pair<int, int> s, int one, int two, int thr, int fou, int fiv){

    if (one < 0 || two < 0 || thr < 0 || fou < 0 || fiv < 0) return 500;
    if (isClear()){

        return 5-one + 5-two + 5-thr + 5-fou + 5-fiv;
    }

    int& ret = DP[one][two][thr][fou][fiv];
    if (ret != INFI) return ret;


    for(int i =0 ; i < 10 ; ++i){
        for(int j =0 ; j < 10; ++j){

            vector<vector<int>> prevPaper = Paper;
            if(Paper[i][j] == 1){

                if (match({i,j}, 5)){
                    ret = min(ret, go({i,j}, one, two, thr, fou, fiv-1));
                    Paper = prevPaper;
                }

                if (match({i,j}, 4)){
                    ret = min(ret, go({i,j}, one, two, thr, fou-1, fiv));
                    Paper = prevPaper;
                }

                if (match({i,j}, 3)){
                    ret = min(ret, go({i,j}, one, two, thr-1, fou, fiv));
                    Paper = prevPaper;
                }
                if (match({i,j}, 2)){
                    ret = min(ret, go({i,j}, one, two-1, thr, fou, fiv));
                    Paper = prevPaper;
                }
                if (match({i,j}, 1)){
                    ret = min(ret, go({i,j}, one-1, two, thr, fou, fiv));
                    Paper = prevPaper;
                }

                
            }
        }
    }


    return ret;
}



int main(){
    
    for(int i =0 ; i < 10; ++i){
        for(int j = 0 ; j < 10 ; ++j){
            cin >> Paper[i][j];
        }
    }
    
    int* begin = &DP[0][0][0][0][0];
    int* end = begin + sizeof(DP) / sizeof(int);
    std::fill(begin, end, INFI);

    int ret = go({0,0}, 5,5,5,5,5);

    if (ret >= 500) cout << -1 ;
    else cout << ret ;

    return 0;
}