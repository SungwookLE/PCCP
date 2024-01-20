#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    
    
    vector<int> dp1, dp2;
    dp1 = money;
    dp1.insert(dp1.begin(), 0);
    dp1.pop_back(); // 끝을  지운 dp
    
    dp2 = money;
    dp2.erase(dp2.begin());
    dp2.insert(dp2.begin(), 0); // 시작을 지운 dp
    
    
    for(int i = 2 ; i < money.size(); ++i){
        
        dp1[i] = max(dp1[i-1], dp1[i]+dp1[i-2]);
        dp2[i] = max(dp2[i-1], dp2[i]+dp2[i-2]);
        
    }
    
    if (dp1.back() > dp2.back())
        answer = dp1.back();
    else
        answer = dp2.back();
    
    return answer;
}