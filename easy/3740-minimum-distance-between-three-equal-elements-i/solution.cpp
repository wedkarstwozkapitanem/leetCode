/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<map>

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        std::map<int,int> liczby;
        for(const auto &i : nums) ++liczby[i];

        int min = INT_MAX;
        for(const auto &[a,b] : liczby) {
            std::vector<int> indeksy;
            if(b >= 3) {
                for(int i{};i<nums.size();++i) if(nums[i]==a) indeksy.push_back(i);
                
                if(indeksy.size() < 3) continue;
                for (int i = 0; i + 2 < indeksy.size(); ++i) {
                    int p = 2 * (indeksy[i + 2] - indeksy[i]);
                    min = std::min(min, p);
                }
                
    
            }
        }     
        return min == INT_MAX ? -1 : min;
    }
};