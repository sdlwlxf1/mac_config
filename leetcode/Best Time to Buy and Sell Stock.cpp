//
//  Best Time to Buy and Sell Stock.cpp
//  leetcode
//
//  Created by tuyoo on 2016/11/3.
//  Copyright © 2016年 tuyoo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int minp = INT32_MAX, maxp = 0;
    for(int i = 0; i < prices.size(); i++)
    {
        if(minp > prices[i]) minp = prices[i];
        int p = prices[i] - minp;
        if(maxp < p) maxp = p;
    }
    return maxp;
}

int main(int argc, const char * argv[]) {
    vector<int> a = {1, 2, 4, 2, 1};
    int r = maxProfit(a);
    return 0;
}
