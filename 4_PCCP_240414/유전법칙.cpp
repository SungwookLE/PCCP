/* 
풀다가.. 답지 찾아봄. 혼자 못 풀었음

<풀이>
현재 세대에서의 형제간의 순서를 구하는 것 -> birth%4
부모 세대의 부모의 순서를 구하는 것 -> birth/4
이거를 맨 꼭대기 세대에 도달할 때까지 반복하여 스택에 담아준 뒤
스택의 맨 위부터(top, 부모) 유전형질을 가지고서 자식세대의 유전형질을 구해낸다.

<틀린이유>
시간초과로 틀렸는데, 그냥 트리를 재귀호출로 싹 구한다음에,
트리 생성에서 백트래킹하면 시간이 단축될테니 할만하다고 생각했는데, 이거 재귀호출되면 4^N이라 당연히 시간초과임... 
*/

#include <bits/stdc++.h>

using namespace std;


string go(vector<int> query){
    int generation = query[0];
    int birth = query[1]-1;

    stack<int> stk;
    for(int i = generation; i >= 2 ; --i){
        stk.push(birth%4);
        birth /= 4;
    }

    string ret = "Rr";
    while(stk.size()){

        if (ret == "RR"){
            ret = "RR";
        }
        else if (ret == "rr"){
            ret = "rr";
        }
        else if (ret == "Rr"){
            if (stk.top() == 0)
                ret = "RR";
            else if (stk.top() == 1)
                ret = "Rr";
            else if (stk.top() == 2)
                ret = "Rr";
            else
                ret = "rr";
        }
        stk.pop();
    }

    return ret;
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;

    for(int i =0 ; i < queries.size(); ++i){
        answer.push_back(go(queries[i]));
    }

    return answer;
}