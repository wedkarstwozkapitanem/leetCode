/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::vector<int> wynik;

        for(int i{1};i<9;++i) {
            int liczba{i};
            for(int cyfra{i+1};cyfra <= 9;++cyfra) {
                liczba *= 10;
                liczba += cyfra;
                if(liczba >= low && liczba <= high) wynik.push_back(liczba);
                else if(liczba > high) break;
            }
        }
       
        std::sort(wynik.begin(),wynik.end());
        /*int aktualny = int(std::to_string(low)[0]) - '0';
        if(aktualny == 9) aktualny = 1;
        

        for(int i{aktualny + 1};i<10;++i) {
            if(aktualny >= low) break;
            aktualny *= 10;
            aktualny += i;
        }

        if(aktualny >= low && aktualny <= high) wynik.push_back(aktualny);
    
        bool przeskok{false};
        while(aktualny <= high) {
            int pierwsza_cyfra = int(std::to_string(aktualny)[0]) - '0' + 1;
            if(pierwsza_cyfra == 9 || przeskok) {
                pierwsza_cyfra = 1;
                przeskok = false;
            }
            int liczba = pierwsza_cyfra;
           
            for(int i{pierwsza_cyfra + 1};i<10;++i) {
                if(liczba > aktualny) break;
                liczba *= 10;
                liczba += i;
                if(i == 9) przeskok = true;
            }
            if(liczba >= low && liczba <= high) wynik.push_back(liczba);
            else break;
            aktualny = liczba;
        }
        //std::cout << aktualny;*/


        return wynik;
    }
};