## 삼수생..

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

