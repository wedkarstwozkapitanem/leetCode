/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

#include<stack>

class Solution {
public:

    char para(char nawias) {
        switch(nawias){
            case '(':
                return ')';
                break;
            case '{':
                return '}';
                break;
            case '[':
                return ']';
                break;
        }
        return ' ';
    }

    bool isValid(string s) {
        std::stack<char> poczotki;

        for(const auto &i : s){
            char znak{' '};
            if(!poczotki.empty()) {
                znak = poczotki.top();
                if(para(znak) == i) {
                    poczotki.pop();
                    continue;
                } else if(para(i) != ' ')  poczotki.push(i);
                 else return false;
            } else {
                if(para(i) != ' ') poczotki.push(i);
                else return false;
                continue;
            }
        }
        if(poczotki.empty()) return true;
        return false;
    }
};