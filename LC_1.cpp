#include<bits/stdc++.h>
using namespace std;

//Input : [2,7,11,15] , target = 9
//Output : [2,7]


class Solution {
public:

    // TC (n^2) : SC O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pair = {0,0};
        int len = nums.size();
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                if(nums[i] + nums[j] == target){
                    pair[0] = i;
                    pair[1] = j;
                    break;
                }
            }
        }
        return pair;
    }

    // TC O(n) : SC O(n)
  vector<int> two_sum(vector<int>& nums, int target) {
    unordered_map<int, int> numToIndex;
    for (int i = 0; i < nums.size(); ++i) {
        const auto it = numToIndex.find(target - nums[i]);
        if (it != cend(numToIndex)){
            return {it->second, i};
        }
        numToIndex[nums[i]] = i;
    }

    throw;
  }

};

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);
    Solution s;
    vector<int> ans = s.two_sum(v,9);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}
