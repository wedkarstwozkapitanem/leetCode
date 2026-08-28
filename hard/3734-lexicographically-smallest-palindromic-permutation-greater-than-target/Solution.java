/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/


class Solution {
    public String lexPalindromicPermutation(String s, String target) {
        int n = s.length();
        if (n == 1) return (s.compareTo(target) > 0 ? s : "");

        int[] czestotliwosc = new int[26];
        for (int i = 0; i < s.length(); ++i) ++czestotliwosc[s.charAt(i) - 'a'];

        String samotnaLitera = "";

        for (int i = 0; i < 26; ++i) {
            if (czestotliwosc[i] % 2 == 1) {
                if (!samotnaLitera.isEmpty()) return "";
                samotnaLitera = String.valueOf((char) ('a' + i));
            }

            czestotliwosc[i] /= 2;
        }

        StringBuilder litery = new StringBuilder();

        for (int i = 0; i < n / 2; ++i) {
            boolean miejsce = false;

            for (int j = 0; j < 26; ++j) {
                if (czestotliwosc[j] == 0) continue;

                int[] kopia_czestotliwosc = czestotliwosc.clone();
                kopia_czestotliwosc[j]--;

                litery.append((char) (j + 'a'));

                StringBuilder lewe = new StringBuilder();

                for (int k = 25; k >= 0; --k) {
                    while (kopia_czestotliwosc[k] > 0) {
                        lewe.append((char) (k + 'a'));
                        --kopia_czestotliwosc[k];
                    }
                }

                String lewyKandydat = litery.toString() + lewe;

                String mozliwyWynik = lewyKandydat + samotnaLitera + new StringBuilder(lewyKandydat).reverse();

                if (mozliwyWynik.compareTo(target) > 0) {
                    miejsce = true;
                    czestotliwosc[j]--;
                    break;
                }

                litery.deleteCharAt(litery.length() - 1);
            }

            if (!miejsce) return "";
        }

        return litery.toString() + samotnaLitera+ new StringBuilder(litery).reverse();
    }
}
