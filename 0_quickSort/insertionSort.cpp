#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief insertionSort_u32, InsertionSort has stability and in-place
 * 
 * @param Arr Array to be sorted (uint32_t)
 * @param Idx Sorted Array Index starting zero (uint8_t) 
 * @param Size Array Size, It should be smaller than 255 (uint8_t)
 * @param isAscending Optional(default: Ascending 1), desending is set to be 0 (uint8_t)
 */
void insertionSort_u32(uint32_t* Arr, uint8_t* Idx, uint8_t Size, uint8_t isAscending = 1U){
   
    if (Arr == NULL || Idx == NULL){
        return;
    }

    for(uint8_t i = 0 ; i < Size; ++i){
        Idx[i] = i;
    }

    for(uint8_t i = 1; i < Size ; ++i){
        uint32_t key_val = Arr[i];
        uint8_t  key_idx = Idx[i];
        int16_t  j = i-1;

        while(j>=0 && ( (isAscending==1U && key_val < Arr[j]) || (isAscending==0U && key_val > Arr[j]) )){
            Arr[j+1] = Arr[j];
            Idx[j+1] = Idx[j];
            --j;
        }

        Arr[j+1] = key_val;
        Idx[j+1] = key_idx;
    }
    return;
}

/**
 * @brief insertionSort_s32, InsertionSort has stability and in-place
 * 
 * @param Arr Array to be sorted (int32_t)
 * @param Idx Sorted Array Index starting zero (uint8_t) 
 * @param Size Array Size, It should be smaller than 255 (uint8_t)
 * @param isAscending Optional(default: Ascending 1), desending is set to be 0 (uint8_t)
 */
void insertionSort_s32(int32_t* Arr, uint8_t* Idx, uint8_t Size, uint8_t isAscending = 1U){

    if (Arr == NULL || Idx == NULL){
        return;
    }

    for(uint8_t i = 0 ; i < Size; ++i){
        Idx[i] = i;
    }

    for(uint8_t i = 1; i < Size ; ++i){
        int32_t key_val = Arr[i];
        uint8_t key_idx = Idx[i];
        int16_t j = i-1;

        while(j>=0 && ( (isAscending==1U && key_val < Arr[j]) || (isAscending==0U && key_val > Arr[j]) )){
            Arr[j+1] = Arr[j];
            Idx[j+1] = Idx[j];
            --j;
        }

        Arr[j+1] = key_val;
        Idx[j+1] = key_idx;
    }
    return;
}

// TEST Function
int main(){
    string s;
    cin >> s;
    
    int Size;
    Size = s.size();

    vector<int32_t> Arr(Size);
    vector<uint8_t> Idx(Size);

    for(int i = 0; i < Size; ++i) Arr[i] = s[i]-'0';
    insertionSort_s32(&Arr[0], &Idx[0], Size, 1);

    for(int i =0 ; i <Size; ++i) cout << Arr[i];
    cout << endl;
    for(int i =0 ; i <Size; ++i) cout << (int)Idx[i];


    return 0;
}


