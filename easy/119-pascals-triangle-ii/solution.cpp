/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<int> getRow(const int &rowIndex) {
        std::vector<int> trojkot_pascala_th(rowIndex+1,1);
        
        for(int i{2};i<=rowIndex;++i) {
            for(int j{i-1};j>0;--j) trojkot_pascala_th[j] +=  trojkot_pascala_th[j-1];
        }
        return trojkot_pascala_th;
    }
};