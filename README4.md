## 삼수생..

### 1. 핵심필기
1. combination 조합 만들기
- 기계적으로 사용할 수 있게 숙달되어야 함
```c++
void make_combi(int start, vector<int>C){
    if (C.size() == r){
        comb.push_back(C);
        return;
    }
    for(int i = start+1; i < 9; ++i){
        C.push_back(i);
        make_combi(i, C);
        C.pop_back();
    }

}
```
- 순열(permutation)같은 경우엔, 재귀적으로도 구할 수 있겠고, 아니면 `next_permutation(V.begin(), V.end())`를 이용해서 구할 수도 있겠음

2. 띄어쓰기를 포함한 입력받기
- `getline(cin, S)`

3. 문자열 자르기
- 특정 문자 위치 찾기: `int npos = str.find('*');`
- 문자열 자르기: `str.substr(npos+1)`
- 문자열 -> 숫자: `stoi(str)`

4. 모듈러 연산 
- 나머지 계산(`%`)은 곱셈의 성질과 마찬가지로 분배법칙이 성립하므로, 어떤 자리수가 커지는 연산에 대해 나머지 연산만을 수행하면 되는 경우, 중간 중간 나머지(`%`) 연산을 해줄 것

### 2. 문제풀이 기록
#### 1주차
- #1159, #2559, #2979, #9996, #10808, #10988, #11655
- #1213, #1620, #1940
- #1629. #3986, #4375

#### 2주차
- go