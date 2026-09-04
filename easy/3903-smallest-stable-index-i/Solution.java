/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] minima = new int[n];
        minima[n - 1] = nums[n-1];

        for(int i = n - 2;i>=0;--i) minima[i] = Math.min(minima[i+1],nums[i]);
        int maks = 0;
        for(int i = 0;i<n;++i) {
            maks = Math.max(maks,nums[i]);
            if(maks - minima[i] <= k) return i;
        }
        return -1;
    }
}