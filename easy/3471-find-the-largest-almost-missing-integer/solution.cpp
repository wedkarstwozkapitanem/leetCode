/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<algorithm>
#include<set>

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k == nums.size())  return *max_element(nums.begin(),nums.end());

        std::unordered_map<int,int> czestotliwosc;
        for(const auto &i : nums) ++czestotliwosc[i];

        if(k == 1) {
            int maks{-1};
            for(const auto &i : czestotliwosc) {
                if(i.second == 1)  maks = std::max(maks,i.first);
            }

            return maks;
        }
        
        if(czestotliwosc[nums[0]] == 1 && czestotliwosc[nums[nums.size() - 1]] == 1) return  std::max(nums[0],nums[nums.size()-1]);
        else if(czestotliwosc[nums[0]] == 1) return nums[0];
        else if(czestotliwosc[nums[nums.size() - 1]] == 1) return nums[nums.size() - 1];
        return -1;
    }
};