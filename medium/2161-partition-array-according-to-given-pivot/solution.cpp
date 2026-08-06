/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<algorithm>
#include<vector>

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        std::vector<int> a,b,p;         
        a.reserve(nums.size());
        b.reserve(nums.size());
        p.reserve(nums.size());

        for(int i{};i<nums.size();++i) {
            if(nums[i] < pivot) a.push_back(nums[i]);
            else if(nums[i] > pivot) b.push_back(nums[i]);
            else p.push_back(nums[i]);
         }

         int idx{};
         for(auto &i : a) nums[idx++] = i;
         for(auto &i : p) nums[idx++] = i;
         for(auto &i : b) nums[idx++] = i;
         return nums;
    }
};