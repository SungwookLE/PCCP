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

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    


    for(int i = 0 ; i < queries.size(); ++i){
        int generation = queries[i][0];
        int birth = queries[i][1]-1;
        stack<int> st;
      
        for(int i = 1; i < generation; ++i){
            st.push(birth%4);
            birth /= 4;
        }

        string trait = "Rr";
        while(!st.empty()){

            if (trait == "rr" || trait == "RR") break;

            if (st.top() == 0) trait = "RR";
            else if (st.top() == 3) trait = "rr";
            else trait = "Rr";
            st.pop();
        }

        answer.push_back(trait);

    }




    return answer;
}