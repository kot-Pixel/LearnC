#include<stdio.h>
int maxProfit(int* prices, int pricesSize);

/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 */

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) {
        return 0;
    }
    if (pricesSize == 2) {
        const int profile = prices[1] - prices[0];
        if (profile > 0) {
            return profile;
        }
        return 0;
    }
    int maxProfile = 0;
    int minValue = 0;
    if (prices[1] > prices[0]) {
        minValue = prices[0];
        maxProfile = prices[1] - minValue;
    } else {
        minValue = prices[1];
    }
    for (int i = 2; i < pricesSize; i++) {
        if (prices[i] <= minValue) {
            minValue = prices[i];
        } else {
            const int tmp = prices[i] - minValue;
            if (tmp > maxProfile) {
                maxProfile = tmp;
            }
        }
    }
    return maxProfile;
}
