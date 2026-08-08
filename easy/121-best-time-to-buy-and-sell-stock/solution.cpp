/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int min{INT_MAX},zysk{};

        for(const auto &i : prices) {
            min = std::min(min,i);
            zysk = std::max(zysk,i - min);
        }
         
        return (zysk >= 0 ? zysk : 0);
    }
};