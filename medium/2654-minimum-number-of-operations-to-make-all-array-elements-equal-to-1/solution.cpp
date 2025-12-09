/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
int nwd(int a,int b) {
    while(b) std::swap(a%=b,b);
    
    return a;
}
public:
    int minOperations(vector<int>& nums) {
        int liczbaoperacji{},gcd{},liczba1{};
        for(int i{};i<nums.size();++i) {
            gcd = nwd(nums[i],gcd);
            if(nums[i] == 1) ++liczba1; 
        }
        if(gcd != 1) return -1;
        if(liczba1 > 0) return nums.size() - liczba1;

        int najlepszy = INT_MAX;

        for(int i{};i<nums.size();++i) {
            int g = 0;
            for(int j = i;j<nums.size();++j) {
                g = nwd(g,nums[j]);
                if(g ==  1) {
                    najlepszy = std::min(najlepszy,j-i);
                    break;
                }
            }
        }

        return najlepszy + nums.size() - 1;
    }
};