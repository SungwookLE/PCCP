#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, string delimeter){
    vector<string> ret;
    string token = "";
    long long pos = 0;

    while ((pos = input.find(delimeter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    ret.push_back(input);
    return ret;
}

int main()
{

    vector<string> ret;
    string token = "";
    long long pos = 0;

    string input;
    cin >> input;

    auto v = split(input, ",");
    for(auto s : v){
        cout << s << " ";
    }
    cout << endl;

    return 0;
}