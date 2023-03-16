#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double const c_eps = 0.0001;
    static double DAt(vector<int> const & a, int di) {
        return di % 2 == 0 ? a[di / 2] : (double(a[di / 2]) + a[di / 2 + 1]) / 2;
    }
    enum { c_range = 3, c_extra = 3 };
    #define n1lower(i) (max(int(0), int(n1.size() + n2.size()) / 2 - (i + 1)))
    #define n1upper(i) (min(int(n1.size() - 1), int(n1.size() + n2.size() + 1) / 2 - (i)))
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()){ 
            return 0;
        }
        vector<int> & n1 = nums1.size() >= nums2.size() ? nums1 : nums2;
        vector<int> & n2 = nums1.size()  < nums2.size() ? nums1 : nums2;
        if (n2.empty()){
            return n1.size() % 2 == 1 ? n1[n1.size() / 2] : (double(n1[n1.size() / 2 - 1]) + n1[n1.size() / 2]) / 2;
        }
        int l = 0, r = n2.size() - 1;
        do {
            int dm2 = (l + r), dm1 = int(n1.size() + n2.size()) - 2 - dm2;
            if (fabs(DAt(n1, dm1) - DAt(n2, dm2)) < c_eps) return DAt(n1, dm1);
            else if (DAt(n2, dm2) > DAt(n1, dm1)) r = (dm2 + 1) / 2; else l = dm2 / 2;
        } while (r - l + 1 > c_range);
        vector<int> final;
        for (int i = n1lower(r + c_extra); i <= n1upper(l - c_extra); ++i){
            final.push_back(n1[i]);
        }
        for (int i = max(0, l - c_extra); i <= min(int(n2.size() - 1), r + c_extra); ++i){
            final.push_back(n2[i]);
        }
        sort(final.begin(), final.end());
        int before = n1lower(r + c_extra) + max(0, l - c_extra), dsb = n1.size() + n2.size() - 1 - before * 2;
        return dsb % 2 == 0 ? final[dsb / 2] : (double(final[dsb / 2]) + final[dsb / 2 + 1]) / 2;
    }
};