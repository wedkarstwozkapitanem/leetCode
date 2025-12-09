/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<unordered_map>
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        std::vector<int> wynik;
        for(int i{};i<=nums.size() - k;++i) {
            std::unordered_map<int,int> wystopienia;
            for(int j = i;j<i+k;++j) ++wystopienia[nums[j]];
            std::vector<std::pair<int,int>> liczby(wystopienia.begin(),wystopienia.end());
            std::sort(liczby.begin(),liczby.end(),[&](const auto &a,const auto &b){
                if(a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
            int sum{};
            int limit = std::min(x,(int)liczby.size());
            for(int p{};p<limit;++p) sum += liczby[p].first * liczby[p].second;

            wynik.push_back(sum);
        }
        return wynik;
    }
};