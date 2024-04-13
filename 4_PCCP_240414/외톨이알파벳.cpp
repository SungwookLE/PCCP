#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> mp;

string solution(string input_string) {
    string answer = "";


    char ret = input_string[0];
    for(int i =1 ; i < input_string.size(); ++i){

        if (input_string[i] == input_string[i-1]){
            ;
        }
        else{
            mp[ret]+=1;
            ret = input_string[i];
        }
    }

    mp[ret] +=1;

    for(auto it = mp.begin(); it != mp.end(); ++it){
        if (it->second >= 2) answer += it->first;
    }

    if (answer.empty()) answer = "N";

    return answer;
}