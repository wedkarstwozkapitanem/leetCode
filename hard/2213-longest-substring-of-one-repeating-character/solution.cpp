class Solution {
public:
    struct Wezel {
        char lewy;
        char prawy;
        int pref;
        int suf;
        int maks;
        int dlugosc;
    };

    vector<Wezel> drzewo;

    Wezel polacz(Wezel a, Wezel b) {
        Wezel wynik;

        wynik.lewy = a.lewy;
        wynik.prawy = b.prawy;
        wynik.dlugosc = a.dlugosc + b.dlugosc;

        wynik.pref = a.pref;

        if (a.pref == a.dlugosc && a.prawy == b.lewy) wynik.pref = a.dlugosc + b.pref;

        wynik.suf = b.suf;

        if (b.suf == b.dlugosc && a.prawy == b.lewy) wynik.suf = b.dlugosc + a.suf;

        wynik.maks = max(a.maks, b.maks);

        if (a.prawy == b.lewy) wynik.maks = max(wynik.maks, a.suf + b.pref);

        return wynik;
    }

    void zbuduj(int v, int l, int r, string& s) {
        if (l == r) {
            drzewo[v] = {s[l],s[l],1,1,1,1};
            return;
        }

        const int m = (l + r) / 2;

        zbuduj(v * 2, l, m, s);
        zbuduj(v * 2 + 1, m + 1, r, s);

        drzewo[v] = polacz(drzewo[v * 2], drzewo[v * 2 + 1]);
    }

    void zmien(int v, int l, int r, int indeks, char znak) {
        if (l == r) {
            drzewo[v] = {znak,znak,1,1,1,1};
            return;
        }

        int m = (l + r) / 2;

        if (indeks <= m) zmien(v * 2, l, m, indeks, znak);
        else  zmien(v * 2 + 1, m + 1, r, indeks, znak);

        drzewo[v] = polacz(drzewo[v * 2], drzewo[v * 2 + 1]);
    }

    std::vector<int> longestRepeating(
        std::string s,
        std::string queryCharacters,
        std::vector<int>& queryIndices
    ) {
        int n = s.size();

        drzewo.resize(4 * n);

        zbuduj(1, 0, n - 1, s);

        std::vector<int> odpowiedz;

        for (int i = 0; i < queryCharacters.size(); i++) {
            zmien(1,0,n - 1,queryIndices[i],queryCharacters[i] );

            odpowiedz.push_back(drzewo[1].maks);
        }

        return odpowiedz;
    }
};