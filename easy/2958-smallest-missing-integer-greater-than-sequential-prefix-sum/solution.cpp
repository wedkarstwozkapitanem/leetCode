/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int idx{1},ostatni = nums[0],suma_prefiksu = nums[0];

        while(idx < nums.size()) {
            if(nums[idx] != ostatni + 1) break;
            suma_prefiksu += nums[idx];
            ostatni = nums[idx++];
        }

        std::sort(nums.begin(),nums.end());

        while(std::binary_search(nums.begin(),nums.end(),suma_prefiksu)) ++suma_prefiksu;
        
        return suma_prefiksu;
    }
};