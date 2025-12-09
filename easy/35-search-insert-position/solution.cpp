/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(!nums.size()) return 0;

        int lewy{},prawy = nums.size() - 1,mid{};

        while(lewy <= prawy) {
            mid = (lewy+prawy) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) lewy = mid + 1;
            else prawy = mid - 1;
        }
        return lewy;
    }
};