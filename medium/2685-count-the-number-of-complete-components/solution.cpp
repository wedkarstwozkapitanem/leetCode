/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
private:
    int find_(std::vector<int> &graf,int v) {
        if(graf[v] == v) return v;
        return graf[v] = find_(graf,graf[v]);
    }
    
    void union_(std::vector<int> &graf,int a,int b) {
        a = find_(graf,a), b = find_(graf,b);
        graf[a] = b;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        std::vector<int> komponenty(n);
        for(int i{};i<n;++i) komponenty[i] = i;

        std::unordered_map<int,int> wierzcholki_w_komponencie, krawedzie_w_komponencie;
        for(int i{};i<edges.size();++i) {
            const int a = edges[i][0], b = edges[i][1];
            this->union_(komponenty,a,b);
        }

        for(const auto &i : edges) {
            const int a = i[0],b = i[1];
            ++krawedzie_w_komponencie[this->find_(komponenty,a)];
        }

        for(int i{};i < n;++i) ++wierzcholki_w_komponencie[this->find_(komponenty,i)];
        
        int wynik{};
        for(const auto &[i,ilosc_wierzcholkow] : wierzcholki_w_komponencie) {
            int ilosc_krawedzi = krawedzie_w_komponencie[i];
            if(ilosc_krawedzi == (ilosc_wierzcholkow * (ilosc_wierzcholkow - 1)) / 2) ++wynik;
        }
        
        return wynik;
    }
};