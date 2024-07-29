#include <bits/stdc++.h>

#define TABLE_SIZE 10000
using namespace std;

void init_table(vector<int>&X1, vector<int>&Y1){
    ofstream fout("out.txt"); // 생성된 샘플

    Y1.resize(TABLE_SIZE+1,0);

    for(int i =0 ; i <= TABLE_SIZE; ++i){
        double x = i *0.001F;
        if (abs(-2.0*x / ((1.0+x*x)*(1.0+x*x))) > 0.1){
            X1.push_back(i);
            Y1[i] = (int)(atan(X1.back()*0.001F)*180.F/M_PI);
            cout << X1.back() << ": " << Y1[i] << "\n";
            fout << X1.back() << ", " << Y1[i] <<"\n";
        }
    }

    cout << endl;

  
}


int main(){


    vector<int> X1, Y1;
    init_table(X1, Y1);


    return 0;
}