/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
private:
    int proces(vector<int> nums, int curr, bool prawy = true) {

        while (curr < nums.size()) {
            if (nums[curr] == 0)
                curr += prawy ? 1 : -1;
            else if (nums[curr] > 0) {
                --nums[curr];
                prawy = !prawy;
                curr += prawy ? 1 : -1;
            }
            if (curr < 0 || curr >= nums.size())
                break;
        }
        for (const auto& i : nums) {
            if (i != 0)
                return false;
        }
        return true;
    }

public:
    int countValidSelections(vector<int>& nums) {
        int wynik{};
        for (size_t i{}; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                wynik += proces(nums, i) == 1 ? 1 : 0;
                wynik += proces(nums, i, false) == 1 ? 1 : 0;
                ;
            }
        }
        return wynik;
    }
};