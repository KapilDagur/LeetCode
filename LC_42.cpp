#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int pMax[height.size()];
        int sMax[height.size()];
        int size = height.size();
        int i;

        pMax[0] = height[0];
        for(i = 1; i < size; i++){
            pMax[i] = height[i] > pMax[i-1] ? height[i] : pMax[i-1];
        }

        sMax[size - 1] = height[size - 1];
        for(i = size - 2; i >= 0; i--){
            sMax[i] = height[i] > sMax[i-1] ? height[i] : pMax[i-1];
        }

        
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(v);
    return 0;
}
