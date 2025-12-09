/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<algorithm>

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        else if(intervals.size()==1) return 2;

        std::sort(intervals.begin(),intervals.end(),[&](const auto &a,const auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        }); 

        int wynik{}, a{-1},b{-1};

        for(size_t i{};i<intervals.size();++i){
            
            if(intervals[i][0] <= a) continue;

            else if(intervals[i][0] > b) {
                wynik += 2;
                b = intervals[i][1];
                a = intervals[i][1] - 1;
            } else {
                ++wynik;
                a = b;
                b = intervals[i][1];
            }

        } 

        return wynik;
    }
};