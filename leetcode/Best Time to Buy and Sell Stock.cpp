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

//int maxProfit(vector<int>& prices) {
//    int minp = INT32_MAX, maxp = 0;
//    for(int i = 0; i < prices.size(); i++)
//    {
//        if(minp > prices[i]) minp = prices[i];
//        int p = prices[i] - minp;
//        if(maxp < p) maxp = p;
//    }
//    return maxp;
//}

//int maxProfit(vector<int>& prices) {
//    int onemax = 0, twomax = 0;
//    for(int i = 1; i < prices.size(); i++)
//    {
//        while(i < prices.size() && prices[i] < prices[i-1])
//            i++;
//        int low = prices[i-1];
//        while(i < prices.size() && prices[i] > prices[i-1])
//            i++;
//        int high = prices[i-1];
//        int profit = high - low;
//        if(profit > onemax) {
//            twomax = onemax;
//            onemax = profit;
//        } else if(profit > twomax) {
//            twomax = profit;
//        }
//    }
//    return onemax + twomax;
//}

int maxProfit(vector<int> &prices) {
    // f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions.
    // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
    //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
    // f[0, ii] = 0; 0 times transation makes 0 profit
    // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
    if (prices.size() <= 1) return 0;
    else {
        int K = 2; // number of max transation allowed
        int maxProf = 0;
        vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
        for (int kk = 1; kk <= K; kk++) {
            int tmpMax = f[kk-1][0] - prices[0];
            for (int ii = 1; ii < prices.size(); ii++) {
                f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
                tmpMax = max(tmpMax, f[kk-1][ii] - prices[ii]);
                maxProf = max(f[kk][ii], maxProf);
            }
        }
        return maxProf;
    }
}

//int main(int argc, const char * argv[]) {
//    vector<int> a = {1,2,4,2,5,7,2,4,9,0};
//    int r = maxProfit(a);
//    return 0;
//}
