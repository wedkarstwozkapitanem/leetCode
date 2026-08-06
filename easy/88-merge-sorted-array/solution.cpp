/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int num1 = m - 1, num2 = n - 1, idx = n + m - 1;
        while(num1 >= 0 && num2 >= 0) {
            if(nums1[num1] > nums2[num2]) nums1[idx--] = nums1[num1--];
            else nums1[idx--] = nums2[num2--];
        }
        while(num2 >= 0) nums1[idx--] = nums2[num2--];
    }
};