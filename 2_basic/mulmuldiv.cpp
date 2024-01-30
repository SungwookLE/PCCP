// multiply multiply and divide
// for precision operation
// using mul_mul_div

#include <iostream>
#include <iomanip>

using namespace std;

// 기존에 int32_MIN 값에 해당하는 값을 ABS 처리하는 과정에서 오버플로우가 날 수 있는 가능성이 있었음
// 따라서, int32_MIN에 해당하는 값을 uint32_t로 안전하게 절대값을 취하는 알고리즘이 필요함
uint32_t absoluteU32(int32_t signedIn)
{
    uint32_t signFlag;
    signFlag = ((uint32_t)signedIn >> 31); // + 부호면 0, - 부호면 1

    uint32_t unsignedOut;

    /*  1. 음수 Flag라면 모든 비트를 반전시킨 다음, signFlag(1)를 더한다.
         - 2^31 비트를 부호비트가 아닌 값 비트로 사용하여, 모든 int32_t 범위에 대한 uint32_t 변환을 보장하기 위함
        2. 양수 Flag라면 모든 비트를 유지한 채, signFlag(0)을 더한다.
    */
    unsignedOut = (uint32_t)((signedIn ^ (-(int32_t)signFlag)) + signFlag);
    return unsignedOut;
}
uint16_t absoluteU16(int16_t signedIn)
{
    uint16_t signFlag;
    signFlag = ((uint16_t)signedIn >> 15); // + 부호면 0, - 부호면 1

    uint16_t unsignedOut;

    /*  1. 음수 Flag라면 모든 비트를 반전시킨 다음, signFlag(1)를 더한다.
         - 2^31 비트를 부호비트가 아닌 값 비트로 사용하여, 모든 int32_t 범위에 대한 uint32_t 변환을 보장하기 위함
        2. 양수 Flag라면 모든 비트를 유지한 채, signFlag(0)을 더한다.
    */
    unsignedOut = (uint16_t)((signedIn ^ (-(int16_t)signFlag)) + signFlag);
    return unsignedOut;
}


// 정밀도를 확보하자니, 중간연산에서 오버플로우가 날 수 있고, 오버플로우를 막자니 정밀도가 떨어지는 문제가 많다.
// 아래 함수는 최종 연산값의 결과가 오버플로우 나지 않는 스케일을 보장한다면, 중간 연산에서 만큼은 정밀도 손실없이 계산할 수 있게 돕는다.
// 왠만한 경우엔 mul_mul_div 함수를 사용할 것

/*  Precondition: It must be ensured that '-2^31 <= sA x sB / sC < 2^31' */
int32_t mul_mul_div(int32_t sA, int32_t sB, int32_t sC)
{

    uint32_t signFlagA, signFlagB, signFlagC, signFlag;
    signFlagA = ((uint32_t)sA >> 31); // + 부호면 0, - 부호면 1
    signFlagB = ((uint32_t)sB >> 31);
    signFlagC = ((uint32_t)sC >> 31);

    // Save the sign of the operation
    signFlag = (signFlagA ^ signFlagB) ^ signFlagC;

    uint32_t uA, uB, uC;

    /*  1. 음수 Flag라면 모든 비트를 반전시킨 다음, signFlag(1)를 더한다.
         - 2^31 비트를 부호비트가 아닌 값 비트로 사용하여, 모든 int32_t 범위에 대한 uint32_t 변환을 보장하기 위함
        2. 양수 Flag라면 모든 비트를 유지한 채, signFlag(0)을 더한다.
    */
    uA = (uint32_t)((sA ^ (-(int32_t)signFlagA)) + signFlagA);
    uB = (uint32_t)((sB ^ (-(int32_t)signFlagB)) + signFlagB);
    uC = (uint32_t)((sC ^ (-(int32_t)signFlagC)) + signFlagC);

    /* Anti for divied by zero */
    if (uC == 0)
        uC = 1;

    /* For Precision: ensure 'uA<uB' */
    if (uA > uB)
    {
        uint32_t uTemp = uA;
        uA = uB;
        uB = uTemp;
    }

    /* For Precision: quotient and remainder of uB, uC */
    uint32_t quotient = uB / uC, remainder = uB - quotient * uC;
    if (uA == 0)
        quotient = 0, remainder = 0;

    /* For Precision: Binary long division algorithm of uA, uB, uC*/
    uint32_t finalQuotient = 0, finalReminder = 0;
    uint32_t Result = 0;

    while (uA > 1)
    {
        if (remainder >= uC)
        {
            quotient++;
            remainder -= uC;
        }
        if (uA & 0x01U)
        {
            finalQuotient += quotient;
            finalReminder += remainder;

            if (finalReminder >= uC)
            {
                finalQuotient++;
                finalReminder -= uC;
            }
        }

        uA >>= 1;
        quotient <<= 1;
        remainder <<= 1;
    }

    finalQuotient += quotient;
    finalReminder += remainder;
    Result = finalQuotient + finalReminder / uC;

    /* Resotre the signbit */
    if (signFlag == 1)
        return -(int32_t)Result;
    else
        return (int32_t)Result;
}

/*  Precondition: It must be ensured that '-2^31 <= sA x sB / sC < 2^31'
    For use in only divided by value that has 1EX(10^2, 10^3, ..., 10^X) scale
    And precision can be saturated in the value of uA*remainder
*/
int32_t mul_mul_div_1EX(int32_t sA, int32_t sB, int32_t sC)
{

    uint32_t signFlagA, signFlagB, signFlagC, signFlag;
    signFlagA = ((uint32_t)sA >> 31); // + 부호면 0, - 부호면 1
    signFlagB = ((uint32_t)sB >> 31);
    signFlagC = ((uint32_t)sC >> 31);

    // Save the sign of the operation
    signFlag = (signFlagA ^ signFlagB) ^ signFlagC;

    uint32_t uA, uB, uC;

    /*  1. 음수 Flag라면 모든 비트를 반전시킨 다음, signFlag(1)를 더한다.
         - 2^31 비트를 부호비트가 아닌 값 비트로 사용하여, 모든 int32_t 범위에 대한 uint32_t 변환을 보장하기 위함
        2. 양수 Flag라면 모든 비트를 유지한 채, signFlag(0)을 더한다.
    */
    uA = (uint32_t)((sA ^ (-(int32_t)signFlagA)) + signFlagA);
    uB = (uint32_t)((sB ^ (-(int32_t)signFlagB)) + signFlagB);
    uC = (uint32_t)((sC ^ (-(int32_t)signFlagC)) + signFlagC);

    /* Anti for divied by zero */
    if (uC == 0)
        uC = 1;

    /* For Precision: ensure 'uA<uB' */
    if (uA > uB)
    {
        uint32_t uTemp = uA;
        uA = uB;
        uB = uTemp;
    }

    /* For Precision: quotient and remainder of uB, uC */
    uint32_t quotient = uB / uC;
    uint32_t remainder = uB - quotient * uC;

    /* For Precision: quotient and remainder of uA, uB, uC
       !! Caution: 'uA * remainder' it value must be in 2^32
    */
    uint32_t Result = uA * quotient + (uA * remainder) / uC;

    /* Resotre the signbit */
    if (signFlag == 1)
        return -(int32_t)Result;
    else
        return (int32_t)Result;
}

int main()
{
    int sA, sB, sC;
    cin >> sA >> sB >> sC;

    cout << "absU32\t: " << absoluteU32(sA) << endl;
    cout << "absU16\t: " << absoluteU16(sB) << endl;

    cout << "true\t\t:" << setprecision(31) <<  double(sA)*(double(sB)/double(sC)) << endl;
    cout << "mulmuldiv\t:" << mul_mul_div(sA, sB, sC)
         << endl;

    cout << "mulmuldiv_10\t:" << mul_mul_div_1EX(sA, sB, sC)
         << endl;
    cout << "fixed\t\t:" << sA*(sB/sC) << endl;

    return 0;
}