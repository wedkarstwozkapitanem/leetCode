/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {

    public String lexGreaterPermutation(String s, String target) {
        int[] wystopienia = new int[26];
        for (char i : s.toCharArray())
            ++wystopienia[i - 'a'];

        StringBuilder wynik = new StringBuilder();
        int idx = 0;

        while (idx < target.length()) {
            int znak = (int) target.charAt(idx) - 'a';
            if (wystopienia[znak] == 0)
                break;

            wynik.append((char) (znak + 'a'));
            --wystopienia[znak];
            ++idx;
        }

        if (idx == target.length()) {
            --idx;

            char usunieta = wynik.charAt(wynik.length() - 1);
            ++wystopienia[usunieta - 'a'];
            wynik.setLength(wynik.length() - 1);
        }

        while (idx >= 0 && idx < target.length()) {
            int poczotek = (int) target.charAt(idx) - 'a' + 1;
            for (int i = poczotek; i < 26; ++i) {
                if (wystopienia[i] > 0) {
                    wynik.append((char) (i + 'a'));
                    --wystopienia[i];
                    for (int p = 0; p < 26; ++p) {
                        while (wystopienia[p] > 0) {
                            wynik.append((char) (p + 'a'));
                            --wystopienia[p];
                        }
                    }
                    return wynik.toString();
                }
            }
            if (idx == 0)
                break;
            --idx;
            wystopienia[wynik.charAt(wynik.length() - 1) - 'a']++;

            wynik.setLength(wynik.length() - 1);
        }

        return "";
    }
}