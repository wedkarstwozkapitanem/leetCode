/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<queue>
#include<vector>


class Solution {
private:
    int bfs(const std::vector<std::vector<bool>>& plansza,int x,int y,const short kierunek,std::vector<std::vector<bool>>& odwiedzone) {
       int wynik{};
       if(kierunek == 1) {
            for(int i = x + 1;i<plansza.size();++i) {
                if(plansza[i][y]) break;
                if(!odwiedzone[i][y]) ++wynik;
                odwiedzone[i][y] = true;
            }
       } else if(kierunek == 2) {
            for(int i = y + 1;i<plansza[0].size();++i) {
                if(plansza[x][i]) break;
                if(!odwiedzone[x][i]) ++wynik;
                 odwiedzone[x][i] = true;
            }
       } else  if(kierunek == 3) {
            for(int i = x - 1;i>=0;--i) {
                if(plansza[i][y]) break;
                if(!odwiedzone[i][y]) ++wynik;
                 odwiedzone[i][y] = true;
            }
       } 
       
       else if(kierunek == 4) {
            for(int i = y - 1;i>=0;--i) {
                if(plansza[x][i]) break;
                if(!odwiedzone[x][i]) ++wynik;
                odwiedzone[x][i] = true;
            }
       }
       return wynik;
    }
public:
    int countUnguarded(const int m,const int n,const vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int wynik{};
        std::vector<std::vector<bool>> plansza(m,std::vector<bool>(n,false)), odwiedzone(m,std::vector<bool>(n,false));

        int gs = guards.size(),ws = walls.size();
        for(int i{};i<std::max(ws,gs);++i) {
            if(i<ws) plansza[walls[i][0]][walls[i][1]] = true;
            if(i<gs) plansza[guards[i][0]][guards[i][1]] = true;
        }

        for(const auto &i : guards) {
            wynik += bfs(plansza,i[0],i[1],1,odwiedzone);
            wynik += bfs(plansza,i[0],i[1],2,odwiedzone);
            wynik += bfs(plansza,i[0],i[1],3,odwiedzone);
            wynik += bfs(plansza,i[0],i[1],4,odwiedzone);
        }
       return (m * n) - walls.size() - guards.size() - wynik;

    }
};