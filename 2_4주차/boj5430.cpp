#include <bits/stdc++.h>

using namespace std;

int T;
string s;
int len;
string arr;

int main(){
    cin >> T;

    for(int i = 0 ; i < T ; ++i){
        cin >> s;
        cin >> len;
        cin >> arr;

        arr.pop_back();
        arr.erase(arr.begin());

        deque<int> nums;

        stringstream g(arr);
        string token;  
        while( getline(g, token, ',') ){
            nums.push_back(stoi(token));
        }




        bool out = false;
        bool isReverse = false;
        for(int j = 0; j < s.size(); ++j){

            if (s[j] == 'R') isReverse = !isReverse; // 실제로 뒤집는 건 할 필요가 없다.

            else if (s[j] == 'D'){

                if (nums.empty()){
                    out = true;
                    break;
                }

                else{
                    if (isReverse) nums.pop_back();
                    else nums.pop_front();
                    
                }
            }

        }

        if (out) cout << "error\n";
        else{

            if (isReverse) reverse(nums.begin(), nums.end());

            string ret = "[";
            for(auto nn : nums){
                ret += (to_string(nn)+",");
            }
            if (ret.size() > 1) ret.pop_back();
            ret += "]";

            cout << ret << "\n";
        }


    }


    return 0;
}