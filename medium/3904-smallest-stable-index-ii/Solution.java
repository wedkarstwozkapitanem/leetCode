/*
 * =========================== *
 *  Dominik Łempicki (kapitan) *
 * =========================== *
 */

class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] prefiksMax = new int[n];
        prefiksMax[0] = nums[0];
        for(int i = 1;i<n;++i) prefiksMax[i] = Math.max(prefiksMax[i-1],nums[i]);

        int min = Integer.MAX_VALUE;
        int wynik = -1;
        for(int i = n - 1;i>=0;--i) {
            min = Math.min(min,nums[i]);
            if(prefiksMax[i] - min <= k) wynik = i;         
        }
        return wynik;
    }
}
