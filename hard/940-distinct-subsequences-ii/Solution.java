/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
    public int distinctSubseqII(String s) {
        long MOD = 1000000000 + 7;
        long[] ostatnia = new long[26];
        long dp = 1;
        for(char i : s.toCharArray()) {
            int r = i - 'a';
            long nowy_dp = (2 * dp - ostatnia[r] + MOD) % MOD;
            ostatnia[r] = dp;
            dp = nowy_dp;
        }
        return (int)((dp - 1 + MOD) % MOD);
    }
}