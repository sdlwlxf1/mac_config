#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int max = nums[0], sum = nums[0];
    int len = nums.size();
    for(int i = 1; i < len; i++)
    {
        if(sum + nums[i] >= 0 && sum > 0)
            sum += nums[i];
        else
            sum = nums[i];
        
        if(sum > max)
            max = sum;
    }
    return max;
}

//int main() {
//    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//    int re = maxSubArray(nums);
//    return 0;
//}
