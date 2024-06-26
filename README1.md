# PCCP Coding Test for '24

- 맥북 단축키 익히기

  - 코드 러너 단축키: `ctrl+opt+N`
  - 스크린샷: `shift+cmd+4`
  - 마크다운 이미지 붙여넣기: `opt+cmd+v`
  - 터미널 창 토글: ctrl+` (근데 이거 한글입력 상태일 땐 안되고, 영어입력 상태일때만 됨)

- 평일: 손코딩, 퇴근 후 1~3문제
- 주말: 최소 5문제 풀기
  - 1주일에 25문제
  - ![](img/2024-01-21-21-12-29.png)
  - ![](img/2024-01-21-21-12-55.png)

---

## 1. [인프런 강의1](https://www.inflearn.com/course/%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-%ED%98%BC%EC%9E%90-%EC%A0%95%EB%B3%B5/dashboard)

### 1-1. Dynamic Programming

- 수열을 떠올리자!

  - 수열은 초항(초기값)을 나타내는 값과,
  - 이 후, 어떠한 관계로 수열이 전개되는지 나타내는 점화식으로 구성된다.
  - ~= 동적프로그래밍 문제는 위 2개를 찾는 문제

- 풀이 방법

  - 점화식이 구해졌다면, 구하는 방식으로 2가지 (top-down / bottom-up)
  - top-down 방식은 재귀호출을 이용하여 프로그래밍
  - bottom-up 방식은 array 를 순차적으로 쌓아가는 방식으로 프로그래밍 하기 수월함

- 기본 문제

  - 어떤 수열의 점화식과 초항이 유도되어 졌다면 이를 구현하는 방법(bottom-up)
    - [점화식 동적프로그래밍](./1_dp/dp_reccurence.cpp)

- 연습 문제

  1. 금액을 지불하기 위한 동전의 최소 개수, 1차원

     - ![](img/2024-01-06-22-51-25.png)
     - [코드](./1_dp/dp_reccurence.cpp)

  2. 보석 배낭 채우기, 2차원

     - ![](img/2024-01-06-23-22-31.png)
     - [코드\_배열](./1_dp/dp_backpack.cpp)
     - [코드\_배열Transpose](./1_dp/dp_backpack_T.cpp)
       - 혼자 풀었을 때, 아이디어는 맞췄는데, 확신이 안서서 헤매었다. 점화식 유도를 클리어하게 하고 구현을 시작하자.
       - 배낭 무게를 늘려나가면서 순회를 하여야지, 보석을 무게 순으로 정렬할 필요가 없어진다.
       - 점화식 유도와 초기값을 잘 설정하는 것 2개 다 잘 정의하여야 한다.

  3. LCS(Longest Common Subsequence), 2차원
     - ![](img/2024-01-08-22-24-57.png)
     - ![](img/2024-01-08-22-25-26.png)
     - [코드](./1_dp/dp_LCS.cpp)

- 실전 문제 (프로그래머스)

  1. [N으로 표현](https://school.programmers.co.kr/learn/courses/30/lessons/42895)

     - 하.. 조건 하나를 못 주어서 끝내 못 풀고, 답지 보고 다시 품
       - 이거 어렵다...ㅎㅎ Lv3 인데..

     ```c++
         // 아래와 같이 N 하나로도 답이 될 수 도 있는데, N 하나 짜리는 trivial case 로 넣어야 했는데
         // 그렇지 못해 찾아지는 답이 2~8 사이만 나오게 되서 틀렸다 ㅎㅎ
        for(auto data: dp[1])
             if (data==number)
                 return 1;
     ```

     - [코드](./1_dp/N으로표현.cpp)

  2. [정수삼각형](https://school.programmers.co.kr/learn/courses/30/lessons/43105)

     - 이거는 한번에 풀었음 Lv3
     - 사실 한번 풀어봤던 문제라..
     - [코드](./1_dp/정수삼각형.cpp)

  3. [등굣길](https://school.programmers.co.kr/learn/courses/30/lessons/42898)

     - a_star의 변형 정도의 dp 문제인데 왜 8번 시간초과지... 흠흠..
     - a_star풀이가 틀렸나 해서 몇번 생각했는데, 그게 아니고 애초에 a_star처럼 복잡한 길찾기 문제가 아니었기 때문에 훨씬 간단한 dp 알고리즘으로 풀 수 있었던 문제였다. 여러번 종이에 스케치해보면서 혼자 힘으로 풀긴 하였음
     - [코드](./1_dp/등굣길.cpp) Lv3

  4. [사칙연산](https://school.programmers.co.kr/learn/courses/30/lessons/1843)

     - Lv4 `보통 효율성을 보는 문제는 DFS나 BFS는 거른다고 생각하면 편할 것이다.(항상 그런건 아님 -_-;;)`
     - 이거 어렵다.. ㅎㅎ;;
       - 해설 잘하네... https://school.programmers.co.kr/questions/35224
     - 점화식이 어려운 문제다..

       - 표로 표시하면 아래와 같다. 손으로 체크해보면 점화식을 이해할 수 있다.(처음보고 유도해낼 수 있을까?ㅎㅎ)

       |          | 연산자 | -     | +           | -                |
       | -------- | ------ | ----- | ----------- | ---------------- |
       | **숫자** | 1      | 3     | 5           | 8                |
       | 1        | 1      | (1-3) | (1-8, -2+5) | (1-0, -2+3, 3-8) |
       | 3        |        | 3     | (3+5)       | (3+3, 8-8)       |
       | 5        |        |       | 5           | (5-8)            |
       | 5        |        |       |             | 8                |

       - 점화식 유도

       ```c++
       for(int step = 0 ; step < n ; ++step){
           for(int i = 0 ; i < (n-step) ; ++i){
               int j = i + step;
               if (step == 0)
                   DP[i][i] = "초기값 숫자"
               else{
                   for (int k = i ; k < j ; ++k){
                       if ("k번째의 연산자" == "+" )
                           MAX_DP[i][j] = max(MAX_DP[i][j], MAX_DP[i][k] + MAX_DP[k+1][j])
                           ...
                   }
               }
           }
       }
       ```

     - [코드](./1_dp/사칙연산.cpp)

  5. [도둑질](https://school.programmers.co.kr/learn/courses/30/lessons/42897)
     - Lv4, 원형 배열의 1차원 DP 문제
     - 쉬운 문제 처럼 보였으나, 원형 배열의 형태여서 특별하게 고려해야 주어야 할 것이 있다.
       - **바로 1차원 배열 1개가 아닌, 2개가 사용해야 풀 수 있는 문제다.**
         1. 원형배열의 시작을 고려하되, 끝은 포함되지 않게끔
         2. 원형배열의 끝은 고려하되, 시작은 포함되지 않게끔
       - 그래야지만, 첫 집이 선택됬을 때, 마지막 집이 선택되지 않게끔 할 수 있다.
     - [코드](./1_dp/도둑질.cpp)
       - 정답을 거의 알려준거나 다름 없는 힌트를 보고 풀었다.
         - 해설 잘하시는 분이네 ... https://school.programmers.co.kr/questions/31576

- 백준 (DynamicProgramming)
  1. [타일링](https://www.acmicpc.net/problem/11726)
     - [코드](./1_dp/타일링.cpp)
  2. [타일링2](https://www.acmicpc.net/problem/11727)
     - [코드](./1_dp/타일링2.cpp)
  3. [이친수](https://www.acmicpc.net/problem/2193)
     - [코드](./1_dp/이친수.cpp)
     - 위의 3개 문제가 같은 것이다. 피보나치 수열
       - 이전까지 계산되어온 값 + 이전이전까지 계산되어온 값

### 1-2. Graph Search

- 그래프
  - Node(정점, Vertex)와 Edge(간선)으로 이루어져 있음
  - `G = (V, E)`
  - ![](img/2024-01-14-22-54-44.png)
- 탐색알고리즘(BFS너비우선탐색, DFS깊이우선탐색)
  - BFS는 `Queue: candidates`를 관리하고 순차적으로 방문하는 방식으로 구현
    1. 탐색 후 방문
    2. 큐(FIFO)의 역할: 탐색 노드(방문 예정 노드) 저장
  - DFS는 recursively하게 호출하는 형태로 구현하는 것이 간단하다.
    1. 즉시 방문
    2. 스택(LIFO)의 역할: 지금까지 방문한 노드 모두 저장(Trace)
       - 실제로 스택 자료구조를 사용할 수도 있지만, 재귀호출(recursively fcn call)로 구현하는 것이 구현에 있어 단순함
- 기본문제(길찾기)
  ![](img/2024-01-14-23-20-02.png)

  - 최소 이동 거리를 찾는 문제이므로 BFS로 접근
    - 미로의 자료구조를 그래프로 한다면 아래와 같이 표현할 수 있겠음
      ![](img/2024-01-14-23-53-37.png)
  - 직접 구현한 예제에서는 2차원 격자로 표현하였음 (보통은 2차원 격자로 풀 수 있게 주어진다)

    - [길찾기](./1_graph/길찾기_BFS.cpp)

  - DFS로도 풀어보자
    - [길찾기2](./1_graph/길찾기_DFS.cpp)
    - 설명만 듣고 풀었는데, 구현이 엉성한 듯함
    - 예전에 한번 들은 강의인데, 구현 디테일을 깜빡한듯..ㅠ

#### 1-2-1. BFS(너비우선탐색)

1. 장기문제

   - ![](img/2024-01-15-22-16-58.png)
   - [장기문제](./1_graph/장기문제_BFS.cpp)

2. 상한 귤
   - ![](img/2024-01-15-22-52-11.png)
   - ![](img/2024-01-15-22-53-40.png)
   - [상한귤](./1_graph/상한귤_BFS.cpp)

#### 1-3-1. DFS(깊이우선탐색)

- DFS 구현은 Stack 자료형을 직접 사용할 수도 있지만 재귀호출(호출 스택)을 이용해서 구현하는 것이 쉽다.
  - ![](img/2024-01-15-23-51-38.png)

1. 아파트 단지

   - ![](img/2024-01-15-23-27-10.png)
   - DFS는 함수를 호출하는 형태니까, 전역변수를 활용해서 구현하는 것이 함수의 프로토타입이 단순해서 좋을 듯 하다.
   - [아파트단지](./1_graph/아파트단지_DFS.cpp)

2. 욕심쟁이 조이
   - ![](img/2024-01-16-23-34-24.png)
   - 아래 코드 처럼 풀면 매번 모든 좌표마다 DFS를 실행하게 되는 것으로 엄청난 연산 횟수를 필요로 하게 된다.
     - [욕심쟁이 조이 Worst](./1_graph/욕심쟁이조이Worst_DFS.cpp)
   - ![](img/2024-01-17-00-08-31.png)
     - 연산 횟수를 줄일 수 있는 방법을 강구해야한다.
       - 어쩐지 DFS로만 구현하니까 이거 DP로도 풀 수 있을것 같은 느낌/비효율적일거같은 느낌이 들었다.
     - 다시 풀었는데, 오래 걸렸다. 호출 스택의 최상단 종료 시점과 최하단의 탈출 출력에 대해 고민했다.
       - [욕심쟁이 조이 한번 더](./1_graph/욕심쟁이조이Again.cpp)

