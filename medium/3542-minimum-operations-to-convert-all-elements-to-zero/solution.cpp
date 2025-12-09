/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<stack>

class Solution {
public:
    int minOperations(vector<int>& nums) {
        const size_t n = nums.size();
        std::stack<int> liczby;
        int wynik{};

        for(const auto &i : nums) {
            while(!liczby.empty() && i < liczby.top()) liczby.pop();
            if(!i) continue;
            if(liczby.empty() || i > liczby.top()) {
                ++wynik;
                 liczby.push(i);
            }
        }        

        return wynik;
    }
};