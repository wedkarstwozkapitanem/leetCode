/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        std::unordered_map<long long,short> zarezerwowane;

        for(const auto &i : reservedSeats) zarezerwowane[i[0] - 1] |= (1 << i[1]);
        
        int maks_grup = (n - zarezerwowane.size()) * 2;

        for(const auto &[wiersz,maska_siedzenie] : zarezerwowane) {
            std::array<bool,3> stany = {true,true,true};
            for(int i{2};i<=5;++i) if((maska_siedzenie & 1 << i)) stany[0] = false;
            for(int i{4};i<=7;++i) if((maska_siedzenie & 1 << i)) stany[1] = false;
            for(int i{6};i<=9;++i) if((maska_siedzenie & 1 << i)) stany[2] = false;
            if(stany[0] && stany[2]) maks_grup += 2;
            else if(stany[0] || stany[1] || stany[2]) ++maks_grup;
        }
        
        return maks_grup;
    }
};