/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        Integer[] indeksy = new Integer[n];
        for(int i=0;i<n;++i) indeksy[i] = i;

        Arrays.sort(indeksy,(a,b)->Integer.compare(nums[a],nums[b]));

        int[] wynik = nums.clone();

        int i = 0;

        while(i < n) {
            int koniec = i;
            while(koniec + 1 < n && nums[indeksy[koniec + 1]] - nums[indeksy[koniec]] <= limit) koniec++;
            Integer[] grupa = Arrays.copyOfRange(indeksy,i,koniec + 1);
            Arrays.sort(grupa);
            for(int p=0;p<grupa.length;++p) wynik[grupa[p]] = nums[indeksy[i + p]];
            i = koniec + 1;
        }

        return wynik;
    }
}