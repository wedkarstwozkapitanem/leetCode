/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums.size() <= 3) return false;
       // if(nums.size() == 3) return nums[1] > nums[0] && nums[2] < nums[1];

        int i{};
        while(i + 1 < nums.size() && nums[i+1] > nums[i]) ++i;
        if(i==0) return false;

        int i_tmp = i;
        while(i + 1 < nums.size() && nums[i+1] < nums[i]) ++i;
        
        i_tmp = i;
        while(i + 1 < nums.size() && nums[i+1] > nums[i]) ++i;
        if(i_tmp == i) return false;

        return i == nums.size() - 1;
    }
};