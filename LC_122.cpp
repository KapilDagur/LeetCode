#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int max_profit = 0;
        for(int i = 1; i < size; i++){
            while (i < size && prices[i] >= prices[i-1])
            {
                max_profit += (prices[i] - prices[i-1]);
                i++;
            }
            
        }
        return max_profit;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> x = {7,1,5,3,6,4};
    cout<<s.maxProfit(x);
    return 0;
}
