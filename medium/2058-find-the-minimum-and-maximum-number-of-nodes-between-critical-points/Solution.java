
/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] minMaks = {Integer.MAX_VALUE, -1};

        int idxPierwszegoEkstrema = -1;
        int poprzedni = -1; 
        int poprzedniWartosc = head.val;

        head = head.next;
        int idx = 1;

        while (head != null) {
            if (head.next == null) break;

            int aktualny = head.val;
            int nastepny = head.next.val;

            if ((aktualny > poprzedniWartosc && aktualny > nastepny) ||
                (aktualny < poprzedniWartosc && aktualny < nastepny)) {

                if (idxPierwszegoEkstrema == -1)
                    idxPierwszegoEkstrema = idx;

                if (poprzedni != -1) 
                    minMaks[0] = Math.min(minMaks[0], idx - poprzedni);

                poprzedni = idx;
                if(idx != idxPierwszegoEkstrema)
                    minMaks[1] = Math.max(minMaks[1],idx - idxPierwszegoEkstrema);
            }

            poprzedniWartosc = aktualny;

            head = head.next;
            ++idx;
        }

        if (minMaks[0] == Integer.MAX_VALUE)
            minMaks[0] = -1;

        return minMaks;
    }
}

