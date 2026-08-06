/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
private:
    int find(std::vector<int> &rodzice,const int v) {
        if(rodzice[v] != v) rodzice[v] = find(rodzice,rodzice[v]);
        return rodzice[v];
    }

    void polocz(std::vector<int> &rodzice,int a, int b,std::vector<int> &glebokosc) {
        a = find(rodzice,a);
        b = find(rodzice,b);
        if(a != b) {
            if(glebokosc[a] < glebokosc[b]) std::swap(a,b);
            rodzice[b] = a;
            glebokosc[a] += glebokosc[b];
        }

    }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        std::vector<int> rodzic(n+1);
        std::vector<int> glebokosc(n+1,1);

        for(int i{};i<rodzic.size();++i) rodzic[i] = i;
        

        for(int i{1};i<nums.size();++i) {
            if(nums[i] - nums[i-1] <= maxDiff) this -> polocz(rodzic,i,i-1,glebokosc);
        }

        std::vector<bool> wynik(queries.size());
        for(int i{};i < queries.size();++i) {
            auto u = queries[i][0],v = queries[i][1];
            wynik[i] = (this->find(rodzic,u) == this->find(rodzic,v));
        }

        return wynik;
    }
};