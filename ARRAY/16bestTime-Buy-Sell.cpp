/*Best Time to Buy and Sell Stock*/

//tc-o(n) sc=o(1)  





#include<iostream>
#include <vector>
using namespace std;

int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    int maxRight = prices[n-1];
    int maxProfit = 0;
    
    for(int i = n - 2; i >= 0; i--){
        maxRight = std::max(prices[i], maxRight);
        maxProfit = std::max(maxProfit, maxRight - prices[i]);
    }
    
    return maxProfit;
}


int main() {
    
    std::vector<int> stockPrices = {7, 1, 5, 3, 6, 4};
    
    int result = maxProfit(stockPrices);
    
    std::cout << "Maximum Profit: " << result << std::endl;
    
    return 0;
}