#include <bits/stdc++.h>

using namespace std;

map<string, double> m;

int main(){

    string subject;
    string num;
    string grade;


    m["A+"] = 4.5;
    m["A0"] = 4.0;
    m["B+"] = 3.5;
    m["B0"] = 3.0;
    m["C+"] = 2.5;
    m["C0"] = 2.0;
    m["D+"] = 1.5;
    m["D0"] = 1.0;
    m["F"]  = 0.0;


    double sum = 0;
    double cnt = 0;
    for(int i =0 ; i < 20; ++i){

        cin >> subject >> num >> grade;
        if (grade == "P") continue;

        cnt += stod(num);
        sum += stod(num) * m[grade];

    }

    cout.precision(10);
    cout << sum / cnt ;


    return 0;
}