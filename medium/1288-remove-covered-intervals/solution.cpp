/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<algorithm>

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),intervals.end(),[&](const auto &a,const auto &b){
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });       
        //for(const auto &i : intervals) std::cout << '[' << i[0] << ',' << i[1] << ']' << ' ';

        int wynik = intervals.size();

        int ostatni = 0,maks = intervals[0][1];

        for(int i{1};i<intervals.size();++i) {
            if(intervals[i][0] == intervals[ostatni][1]) {
                --wynik;
                ostatni = i;
                maks = intervals[i][1];
                continue;
            }

            if(intervals[i][1] <= maks) {
                --wynik;
                continue;
            }

            ostatni = i;
            maks = intervals[i][1];
        }
        return wynik;     
    }
};