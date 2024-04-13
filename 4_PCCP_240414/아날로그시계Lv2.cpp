
/*
    1. 혼자 못 풀었음.. 하 이거 Lv2 구현문제인데
    2. 풀이 참고
        A. 각도를 기준으로, 이전 스텝의 각도와 next 스텝의 각도가 시침/초침, 분침/초침간 교차가 일어나는지 체크
        B. double 타입의 값 비교, modulo 연산 (fmod) 에 대해서 확인해 볼 수 있었음
            - [모듈러연산_fmod](./모듈러연산_double타입.cpp)
        C. 아래 코드는 double 을 비교하는 것에 있어 등식 연산자를 사용하고 있으니, 좋은 코드는 아니고,
            - 오류가 있을 수 있는 코드임, 정확하게 하려면 tolerance 이내에 있으면 true, 아니면 false 식으로 값 비교를 수행해 주어야 함
*/

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    int startTime = h1 * 3600 + m1 * 60 + s1;
    int endTime   = h2 * 3600 + m2 * 60 + s2;
    if ((startTime == 0) || (startTime == 12 * 3600)) answer += 1;
    
    double hCurAngle, mCurAngle, sCurAngle;
    double hNextAngle, mNextAngle, sNextAngle;
    while (startTime < endTime){
        // 시침 -> 1초에 1/120도 이동
        // 분침 -> 1초에 1/10도 이동
        // 시침 -> 1초에 6도 이동
        hCurAngle = fmod((double)startTime / 120, 360);
        mCurAngle = fmod((double)startTime / 10 , 360);
        sCurAngle = fmod((double)startTime * 6  , 360);
        
        if ( fmod(((double)startTime + 1) / 120, 360) == 0) hNextAngle = 360;
        else hNextAngle = fmod(((double)startTime + 1) / 120 , 360);
        if ( fmod(((double)startTime +1) / 10, 360)== 0) mNextAngle = 360;
        else mNextAngle = fmod(((double)startTime +1) / 10 , 360);
        if ( fmod(((double)startTime+1) * 6 , 360) == 0) sNextAngle = 360;
        else sNextAngle = fmod(((double)startTime+1) * 6 ,360);
        
        if ( (sCurAngle < hCurAngle) && (sNextAngle >= hNextAngle) ) answer += 1;
        if ( (sCurAngle < mCurAngle) && (sNextAngle >= mNextAngle) ) answer += 1;
        if ((sNextAngle == hNextAngle) && (hNextAngle == mNextAngle)) answer -= 1;
        
        startTime +=1;
    }
    return answer;
}