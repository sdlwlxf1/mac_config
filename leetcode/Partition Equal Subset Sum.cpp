#include <iostream>
#include <vector>
#include <bitset>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums) {
    const int MAX_NUM = 100;
    const int MAX_ARRAY_SIZE = 200;
    bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
    int sum = 0;
    for (auto n : nums) {
        sum += n;
        bits |= bits << n;
    }
    return !(sum % 2) && bits[sum / 2];
}

void print_2(int val2)
{
    unsigned char *p = (unsigned char*)&val2 + 3; //从低位到高位,低端字节计算机
    for(int k = 0; k <= 3; k++)
    {
        int val2 = *(p-k);
        for (int i = 7; i >= 0; i--)
        {
            if(val2 & (1 << i))
                printf("1");
            else
                printf("0");
        }
        printf(" ");
    }
}

vector<int> singleNumber(vector<int>& nums)
{
    // Pass 1 :
    // Get the XOR of the two numbers we need to find
    int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    print_2(diff);
    cout << endl;
    print_2(-diff);
    cout << endl;
    // Get its last set bit
    diff &= -diff;
    print_2(diff);
    cout << endl;
    // Pass 2 :
    vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
    for (int num : nums)
    {
        if ((num & diff) == 0) // the bit is not set
        {
            rets[0] ^= num;
        }
        else // the bit is set
        {
            rets[1] ^= num;
        }
    }
    return rets;
}

//int main() {
//    vector<int> nums = {1, 1, 5, 5, 2, 10};
////    bool res = canPartition(nums);
//    vector<int> ret = singleNumber(nums);
//    return 0;
//}
