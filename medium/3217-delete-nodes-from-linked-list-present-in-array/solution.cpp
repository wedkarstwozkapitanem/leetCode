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

#include<set>

class Solution {
public:
    ListNode* modifiedList(const vector<int>& nums, ListNode* head) {
        std::set<int> liczby;
        for(const auto &i : nums) liczby.insert(i);
        ListNode* lista = head;
        ListNode* poprzedni = nullptr;
        while(lista != nullptr){
            if(liczby.find(lista->val) == liczby.end()) {
                poprzedni = lista;
                lista = lista -> next;
                continue;
            }
            if(poprzedni != nullptr) poprzedni -> next = lista -> next;
            else head = lista -> next;
            
            lista = lista -> next;
        }
        return head;
    }
};