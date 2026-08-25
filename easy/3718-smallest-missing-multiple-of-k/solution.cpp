/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#define MAX 100

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        for(int i{k};i<= MAX + k;i+=k) {
            const auto it  = std::lower_bound(nums.begin(),nums.end(),i);
            if(it == nums.end() || *it != i) return i;
        }
        return 0;
    }
};