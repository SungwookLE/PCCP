#include <bits/stdc++.h>

using namespace std;

class Type{
    private: 
    string str;

    public:
    Type(string s): str(s) {}

    string operator+(Type other){

        string str2 = other.str;
        int min1 = stoi(str.substr(0, str.find(":")));
        int sec1 = stoi(str.substr(str.find(":")+1));
 
        int min2 = stoi(str2.substr(0, str2.find(":")));
        int sec2 = stoi(str2.substr(str2.find(":")+1));


        int ret1 = min1+min2;
        int ret2 = sec1+sec2;

        return to_string(ret1)+":"+to_string(ret2);
    }
    
};

int main(){
    Type s1("10:22");
    Type s2("11:12");
    
    cout << s1+s2 << endl;


    return 0;
}