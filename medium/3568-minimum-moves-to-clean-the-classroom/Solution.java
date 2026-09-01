/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

class Solution {
    private int BFS(String[] classroom, int energiaMax) {
        int n = classroom.length;
        int m = classroom[0].length();

        int[][] idSmiecia = new int[n][m];
        int liczbaSmieci = 0;

        int startX = -1;
        int startY = -1;

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                char c = classroom[y].charAt(x);

                if (c == 'S') {
                    startX = x;
                    startY = y;
                }

                if (c == 'L')
                    idSmiecia[y][x] = 1 << liczbaSmieci++;
                
            }
        }

        int szukanaMaska = (1 << liczbaSmieci) - 1;

        if (szukanaMaska == 0)
            return 0;

        record Stan(int x, int y, int maska, int energia, int kroki) {}

        Queue<Stan> kolejka = new ArrayDeque<>();

        kolejka.add(
            new Stan(startX, startY, 0, energiaMax, 0)
        );

        boolean[][][][] visited =
            new boolean[n][m][1 << liczbaSmieci][energiaMax + 1];

        visited[startY][startX][0][energiaMax] = true;

        int[][] kierunki = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
        };

        while (!kolejka.isEmpty()) {
            Stan aktualny = kolejka.poll();

            for (int[] kierunek : kierunki) {
                int x = aktualny.x() + kierunek[0];
                int y = aktualny.y() + kierunek[1];

                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;

                if (classroom[y].charAt(x) == 'X')
                    continue;

                if (aktualny.energia() == 0)
                    continue;

                int nowaEnergia = aktualny.energia() - 1;
                int nowaMaska = aktualny.maska();

                if (classroom[y].charAt(x) == 'L')  nowaMaska |= idSmiecia[y][x];
                

                if (classroom[y].charAt(x) == 'R') nowaEnergia = energiaMax;
                

                int noweKroki = aktualny.kroki() + 1;

                if (nowaMaska == szukanaMaska) return noweKroki;
                

                if (!visited[y][x][nowaMaska][nowaEnergia]) {
                    visited[y][x][nowaMaska][nowaEnergia] = true;

                    kolejka.add(
                        new Stan(
                            x,
                            y,
                            nowaMaska,
                            nowaEnergia,
                            noweKroki
                        )
                    );
                }
            }
        }

        return -1;
    }

    public int minMoves(String[] classroom, int energy) {
        return BFS(classroom, energy);
    }
}