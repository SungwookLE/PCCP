#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int prev = 0;
    int ret = 0;
    for(int station: stations){
        
        // 이렇게 유도한 수학공식으로 풀 수 있다.
        int a = (station - w - 1) - prev;
        int b = (int)ceil((double)a / (double)(w*2+1));
        ret += b;
        prev = station + w;
    }
    
    ret += (int)ceil((double)(n-prev) / (double)(w*2+1));

    return ret;
}