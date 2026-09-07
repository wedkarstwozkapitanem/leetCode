/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
    public int numDistinct(String s, String t) {
        int[] dp = new int[t.length() + 1];
        dp[0] = 1;

        for(char i : s.toCharArray()) {
            for(int j = t.length();j>0;--j) {
                if(i == t.charAt(j-1)) dp[j] += dp[j-1];
            }
        }

        return dp[t.length()];
    }
}