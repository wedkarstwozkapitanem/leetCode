/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;
        int idxMin = 0;
        int idxMaks = 0;
        for(int i = 0;i<n;++i) {
            if(nums[i] < nums[idxMin]) idxMin = i;
            if(nums[i] > nums[idxMaks]) idxMaks = i;
        }

        int a = Math.min(idxMin,idxMaks);
        int b = Math.max(idxMin,idxMaks);

        int pierwszyPrzypadek = b + 1;
        int drugiPrzypadek = n - a;
        int trzeciPrzypadek = (a + 1) + (n - b);

        /*int mozliwyWynik = Math.min(idxMin + 1,n - idxMin) + Math.min(idxMaks + 1,n - idxMaks);
        mozliwyWynik = Math.min(mozliwyWynik, Math.abs(idxMaks - idxMin) + Math.min(idxMin,idxMaks) + 1);
        mozliwyWynik = Math.min(mozliwyWynik, Math.abs(n - idxMaks - idxMin) + Math.min(n - idxMin,n - idxMaks));*/
        return Math.min(pierwszyPrzypadek,Math.min(drugiPrzypadek,trzeciPrzypadek));
    }
}