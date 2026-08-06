/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        const double godzinastopien = 30; //ile ma stopni 1 godzina
        const double minutastopien = 6; // 1 minuta ma 6*

        const double ilestopniagodzina = hour * godzinastopien + minutes * 0.5;
        const double ilestopniaminuta = minutes * minutastopien;
        const double kot = std::abs(ilestopniagodzina - ilestopniaminuta);
        return std::min(360 - kot,kot);
    }
};