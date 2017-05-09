#include <iostream>
#include <string>

using namespace std;

/**
Set union A | B
Set intersection A & B
Set subtraction A & ~B
Set negation ALL_BITS ^ A or ~A
Set bit A |= 1 << bit
Clear bit A &= ~(1 << bit)
Test bit (A & 1 << bit) != 0
Extract last bit A&-A or A&~(A-1) or x^(x&(x-1))
Remove last bit A&(A-1)
Get all 1-bits ~0
*/


// calculate sum of two int, operator + & - are not acceptable
class SumTwoInt{
    public:
    static int getSum(int a, int b) {
        return (0 == b)? a : getSum(a ^ b, (a&b) << 1);
    }
};

// count number of ones
class CountOne {
    public:
    static int getOnes(int a) {
        int count = 0;
        while(0 != a)
        {
            a = a & (a - 1);
            ++count;
        }
        return count;
    }
};

// check number is power of two
class IsPowerFour {
    public:
    static bool CheckisPowerFour(int a) {
        return (!(a & (a - 1)) && (a & 0x55555555));
    }
};

// [0,1,3] return 2
class MissingNumber {
    static int GetMissingNumber(vector<int>& arr)
    {
        int loop = 0;
        int ret = 0;
        for(loop = 0l loop < arr.size(); ++loop)
        {
            ret ^= loop;
            ret ^= arr[loop];
        }
        ret ^= arr.size();
        return ret;
    }
}

class largestPowerOfTwo{
    public:
    static long get_largest_power_of_two(long num) {
        num = num | (num >> 1);
        num = num | (num >> 2);
        num = num | (num >> 4);
        num = num | (num >> 8);
        num = num | (num >> 16);
        return (num + 1) >> 1;
    }
}

class LongReverseBits{
    public:
    static long long_reverse_bits(long num) {
        num = ((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1);
        num = ((num & 0xcccccccc) >> 2) | ((num & 0x33333333) << 2);
        num = ((num & 0xf0f0f0f0) >> 4) | ((num & 0x0f0f0f0f) << 4);
        num = ((num & 0xff00ff00) >> 8) | ((num & 0x00ff00ff) << 8);
        num = ((num & 0xffff0000) >> 16) | ((num & 0x0000ffff) << 16);
        return num;
    }
}

int main(int argn, char** argv)
{
    if(argn < 3) {
        return 0;
    }
    
    int a = stoi(argv[1], NULL, 10);
    int b = stoi(argv[2], NULL, 10);

    cout << "sum " << a << " + " << b << " = " << SumTwoInt::getSum(a, b) << endl;

    cout << "Count Ones of a: " << a << " = " << CountOne::getOnes(a) << endl;
    cout << "a: " << a << " is power of four? " << IsPowerFour::CheckisPowerFour(a) << endl;

    return 0;
}