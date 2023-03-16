#include<iostream>
#include<vector>
using namespace std;
//Space complexity O(1) & Time Complexity O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int final_profit = 0;
        int profit = 0;
        int min = prices[0];
        int len = prices.size();
        for(int i = 1; i < len; i++){
            profit = prices[i] - min;
            final_profit = profit > final_profit ? profit : final_profit;
            min = prices[i] < min ? prices[i] : min;
        }
        return final_profit;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(7);
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    Solution s;
    cout<<s.maxProfit(v);
    return 0;
}
