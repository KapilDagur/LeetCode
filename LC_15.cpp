#include<bits/stdc++.h>
using namespace std;

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, j, k,add,size = nums.size();;
        set<vector<int>> s;
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        while(i < size){
            j = i +1;
            k = size-1;
            while(j < k){
                add = nums[i] + nums[j] + nums[k];
                if(add == 0){
                    vector<int> val = {nums[i],nums[j],nums[k]};
                    s.insert(val);
                    j++;
                    k--;
                }
                else if(add < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
            i++;
        }

        for(auto ele : s){
            v.push_back(ele);
        }
        return v;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
