#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief swap for sort algorithm
 * 
 * @param a (uint8_t)
 * @param b (uint8_t)
 */
static void swap_u8(uint8_t *a , uint8_t *b){
    uint8_t temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief swap for sort algorithm
 * 
 * @param a (uint32_t)
 * @param b (uint32_t)
 */
static void swap_u32(uint32_t *a , uint32_t *b){
    uint32_t temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief swap for sort algorithm
 * 
 * @param a (int32_t)
 * @param b (int32_t)
 */
static void swap_s32(int32_t *a , int32_t *b){
    int32_t temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief insertionSort_u32, InsertionSort has stabilty and in-place
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

    for(uint8_t i =0 ; i < Size ; ++i){
        uint32_t key = Arr[i];
        uint8_t place = i;

        for (uint8_t j = i-1 ; j >=0 ; --j){
            if (isAscending == 1U){
                if (key < Arr[j]){
                    swap_u32(&Arr[j], &Arr[j+1]);
                    swap_u8(&Idx[j], &Idx[j+1]);
                    place = j;
                }
                else{
                    break;
                }
            }
            else{
                if (key > Arr[j]){
                    swap_u32(&Arr[j], &Arr[j+1]);
                    swap_u8(&Idx[j], &Idx[j+1]);
                    place = j;
                }
                else{
                    break;
                }
            }
        }
        Arr[place] = key;
        Idx[place] = i;
    }
    return;
}

/**
 * @brief insertionSort_s32, InsertionSort has stabilty and in-place
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

    for(uint8_t i =0 ; i < Size ; ++i){
        int32_t key = Arr[i];
        uint8_t place = i;
        for (uint8_t j = i-1 ; j >=0 ; --j){
            if (isAscending == 1U){
                if (key < Arr[j]){
                    swap_s32(&Arr[j], &Arr[j+1]);
                    swap_u8(&Idx[j], &Idx[j+1]);
                    place = j;
                }
                else{
                    break;
                }
            }
            else{
                if (key > Arr[j]){
                    swap_s32(&Arr[j], &Arr[j+1]);
                    swap_u8(&Idx[j], &Idx[j+1]);
                    place = j;
                }
                else{
                    break;
                }
            }
        }
        Arr[place] = key;
        Idx[place] = i;
    }
    return;
}

// TEST Function
int main(){
    int Size;
    cin >> Size;

    vector<int32_t> Arr(Size);
    vector<uint8_t> Idx(Size);

   
    for(int i = 0 ; i < Size ; ++i){
        cin >> Arr[i];
    }
    
    insertionSort_s32(&Arr[0], &Idx[0], Size, 1);

    for(int i =0 ; i <Size; ++i){
        cout << Arr[i];
    }
    cout << endl;

    for(int i =0 ; i <Size; ++i){
        cout << (int)Idx[i];
    }

    return 0;
}


