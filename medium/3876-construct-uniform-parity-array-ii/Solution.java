/*
 * =========================== *
 *  Dominik Łempicki (kapitan) *
 * =========================== *
 */

class Solution {
    public boolean uniformArray(int[] nums1) {
        int minimalnaNieparzysta = Integer.MAX_VALUE;
        boolean wszystkieParzyste = false;

        for(int i : nums1) {
            if(i % 2 == 0)
                wszystkieParzyste = true;
            else
                minimalnaNieparzysta = Math.min(minimalnaNieparzysta,i);
        }

        if(minimalnaNieparzysta == Integer.MAX_VALUE || !wszystkieParzyste) return true;

        for(int i : nums1) {
            if(i % 2 == 0 && i < minimalnaNieparzysta) return false;
        }

        return true;
    }
}