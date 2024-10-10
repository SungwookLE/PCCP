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

5. 그래프와 트리
- 그래프: Vertex(Note)와 Edge로 이루어진 집합을 그래프
- 트리: 부모노드(Predecessor), 자식노드(Sucesor)를 갖는 계층적 구조로, 무방향 "그래프"의 일종이자, 사이클이 없는 자료구조
    - 이진트리: 자식노드의 수가 2이하인 것
    - 균형이진트리(balanced binary tree): 모든 노드의 왼쪽 하위트리와 오른쪽 하위트리의 차이가 1이하인 트리. map, set을 구성하는 레드블랙트리는 균형이진트리 중 하나임

- 그래프 또는 트리를 구현하기 위해 인접행렬(adjacency matrix) 또는 인접리스트(adjacency list)를 사용하게 됨
    - 인접행렬: 정점과 간선의 관계를 나타나는 `bool`타입의 정사각형 2차원 배열 (노드끼리 연결되어 있으면 `T`)
        - adj[from][to]
        ```
    (N)  0   1   2   3
        0   T   T   F   F
        1   T   T   T   T
        2   F   T   T   F
        3   F   T   F   T
        ```
        - 공간복잡도 O(V^2) 
        - 시간복잡도<간선 하나 찾기> O(1)
        - 시간복잡도<간선 모두 탐색> O(V^2)

    - 인접리스트: 연결리스트를 여러개 두어서 그래프를 표현
        - adj[Node] = { 연결된 정점들 }
        ```
        adj[1].push_back(2); ...
        ```
        - 공간복잡도 O(V+E) 
        - 시간복잡도<간선 하나 찾기> O(V)
        - 시간복잡도<간선 모두 탐색> O(V+E)

    - #9(DFS), #10(BFS) 부터 듣기 (10/10~)

### 2. 문제풀이 기록 
#### 1주차
- #1159, #2559, #2979, #9996, #10808, #10988, #11655
- #1213, #1620, #1940
- #1629. #3986, #4375

#### 2주차
- 
● 2 - A : 2178 – http://boj.kr/2f0e1a0d5eab489dac865b3ee7e0fa80
● 2 - B : 1012 - http://boj.kr/c2c09d04946f4cc6844f295e38553ca6
● 2 - C : 2468 - http://boj.kr/cf2c8a947f5041b69efd55961657526c
● 2 - D : 2583 - http://boj.kr/e94fb8e43b714794a0950505c0091594
● 2 - E : 1992 - http://boj.kr/f833f244536f48fa960ea96f9b5a35fb
● 2 - F : 2828 - http://boj.kr/fdee73d789cf421db0e71ad9d332cb4a
● 2 - G : 2910 - http://boj.kr/5ab43b14d0489aac5c48a0a717c1a8
● 2 - H : 4659 - http://boj.kr/e531e15e4f3b4d828f8295934feafd07
● 2 - I : 2870 - http://boj.kr/ae47352b83d04d0c9fa5f5e88d697682
● 2 - J : 10709 - http://boj.kr/2e4e57d962ef41a9bb4bc8f670ac158c
● 2 - K : 3474 - http://boj.kr/89fea6fe8f9241b1980f0fac22342679
● 2 - L : 2852 - http://boj.kr/5d5e7e5459524080abec73ee77de2fbe
● 2 - M : 1436 - http://boj.kr/20f8f3ad94314cc8ab21a004bf75dbf6
● 2 - N : 9012 - http://boj.kr/fd0a8a36c94f49b59150c93831c29243
● 2 - O : 4949 -http://boj.kr/5802422930814efeb41969fdf2b6d4d2
● 2 - P : 14502 - http://boj.kr/2812582f10eb41dfa63761279266e42f
● 2 - Q : 2636 - http://boj.kr/57cf7a485eb44c4fb1e37887e94c0ee4
● 2 - R : 1068 - http://boj.kr/ce4d012c085a44918188cb28f01032b0
● 2 - S : 1325 - http://boj.kr/fe8da028da1d44b59514bc4b8231fce8
● 2 - T : 17298 - http://boj.kr/14db359b008e4b2a9c3658689579f13e
