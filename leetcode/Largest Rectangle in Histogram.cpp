#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &height) {

    int ret = 0;
    height.push_back(0);
    // 未知的index栈
    // index存储的永远是比当前高度矮的柱子
    // 也就是说index具有存储矮柱子的能力
    // 高的柱子直接计算出来，并删掉
    // 矮的柱子需要存下来，以备后来需要
    vector<int> index;

    for(int i = 0; i < height.size(); i++)
    {
        while(index.size() > 0 && height[index.back()] >= height[i])
        {
            int h = height[index.back()];
            index.pop_back();

            int sidx = index.size() > 0 ? index.back() : -1;
            if(h * (i-sidx-1) > ret)
                ret = h * (i-sidx-1);
        }
        index.push_back(i);
    }

    return ret;
}

//int main() {
//    vector<int> height = {5,6,7,8,3};
//    int ret = largestRectangleArea(height);
//    return 0;
//}
