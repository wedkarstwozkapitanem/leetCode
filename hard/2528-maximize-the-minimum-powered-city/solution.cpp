/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
private:
    bool czyMoznaZbudowac(long long minimalnaEnergia, std::vector<long long> &prefix, int n, int zasieg, long long iloscDodatkowych) {
        std::vector<long long> roznice = prefix;
        long long suma = 0;
        long long pozostale = iloscDodatkowych;

        for (int i = 0; i < n; ++i) {
            suma += roznice[i];
            if (suma < minimalnaEnergia) {
                long long potrzebne = minimalnaEnergia - suma;
                if (pozostale < potrzebne)
                    return false;
                pozostale -= potrzebne;
                int koniec = std::min(n, i + 2 * zasieg + 1);
                roznice[koniec] -= potrzebne;
                suma += potrzebne;
            }
        }
        return true;
    }

public:
    long long maxPower(std::vector<int> &stacje, int zasieg, int iloscDodatkowych) {
        int n = stacje.size();
        std::vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            int lewy = std::max(0, i - zasieg);
            int prawy = std::min(n, i + zasieg + 1);
            prefix[lewy] += stacje[i];
            prefix[prawy] -= stacje[i];
        }

        long long lewyZakres = *std::min_element(stacje.begin(), stacje.end());
        long long prawyZakres = std::accumulate(stacje.begin(), stacje.end(), 0LL) + iloscDodatkowych;
        long long wynik = 0;

        while (lewyZakres <= prawyZakres) {
            long long srodek = lewyZakres + (prawyZakres - lewyZakres) / 2;
            if (czyMoznaZbudowac(srodek, prefix, n, zasieg, iloscDodatkowych)) {
                wynik = srodek;
                lewyZakres = srodek + 1;
            } else prawyZakres = srodek - 1;
        }
        return wynik;
    }
};
