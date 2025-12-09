/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:

    std::string liczba(ListNode *l) {
        if(!(l->next)) return std::to_string(l->val);
        return liczba(l->next) + std::to_string(l->val); 
    }
 
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ileDodac{};
        ListNode *wynik = new ListNode;
        ListNode *w = wynik;

        while(l1 != nullptr || l2 != nullptr){
            int cyfra1{},cyfra2{};
            if(l1) cyfra1 = l1 -> val;
            if(l2) cyfra2 = l2 -> val;

            int suma = (cyfra1 + cyfra2 + ileDodac);
            ileDodac = suma / 10;
            suma %= 10;
            ListNode *liczba = new ListNode(suma);
            wynik -> next = liczba;
            wynik = wynik -> next;
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        if(ileDodac) {
            ListNode *liczba = new ListNode(ileDodac);
            wynik -> next = liczba;
        }
        return w -> next;
    }
};