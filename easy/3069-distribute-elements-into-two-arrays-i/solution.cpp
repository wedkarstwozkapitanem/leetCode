/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        std::vector<int> arr1(1),arr2(1);

        arr1[0] = nums[0]; 
        arr2[0] = nums[1];

        for(int i{2};i<nums.size();++i) {
            if(arr1[arr1.size() - 1] > arr2[arr2.size() - 1]) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        
        int idx{};
        while(idx < arr1.size()) {
            nums[idx] = arr1[idx];
            ++idx;
        }
        const int ostatni = idx;
        idx = 0;
        while(idx < arr2.size()) {
            nums[ostatni + idx] = arr2[idx];
            ++idx;
        }

        return nums;
    }
};