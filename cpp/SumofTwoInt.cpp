#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
class SumofTwoInt
{
    public:
    static int getSum(int a, int b) {
        int sum = 0;

        while(b != 0)
        {
            sum = a ^ b;
            printf("sum <%x>\n", sum);
            b = (a & b) << 1;
            printf("b <%x>\n", b);           
            a = sum;
            printf("a <%x>\n", a);
        }

        return a;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        return (b == 0) ? a : getSum(a ^ b, (a&b)<<1);
    }
};

int main(int argn, char** argv)
{
    if(argn < 3)
    {
        cerr << "SumofTwoInt <num 1> <num 2>" << endl;
        return 0;
    }

    int a = stoi(argv[1], NULL , 10);
    int b = stoi(argv[2], NULL , 10);

    cout << SumofTwoInt::getSum(a, b) << endl;

    return 0;
}