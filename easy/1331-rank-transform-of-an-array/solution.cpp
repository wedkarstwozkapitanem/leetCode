/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<algorithm>

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return {};
        
        std::vector<int> liczby(arr);
        std::sort(liczby.begin(),liczby.end());

        int ranga{1};
        std::unordered_map<int,int> rangi_liczb;
        rangi_liczb[liczby[0]] = ranga;
        for(int i{1};i<arr.size();++i) {
            if(liczby[i] > liczby[i-1]) ++ranga;
            rangi_liczb[liczby[i]] = ranga;
        }

        for(int i{};i<arr.size();++i) arr[i] = rangi_liczb[arr[i]];
        

        return arr;        
    }
};