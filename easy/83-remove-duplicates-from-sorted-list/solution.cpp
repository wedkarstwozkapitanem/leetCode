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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *poczotek = head;
        while(head != nullptr) {
            const int aktualny = head -> val;
            ListNode * ostatni = head;
            while(head != nullptr && head -> val == aktualny) head = head -> next;
            ostatni -> next = head;
        }

        return poczotek;
    }
};