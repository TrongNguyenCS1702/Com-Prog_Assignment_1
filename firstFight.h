#ifndef firstFight_h
#define firstFight_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
int getReady(int& HP, const int& ID, int& M, const int& E1)
{
    if (HP > 1000) HP = 1000; if (HP < 0) HP = 0; if (M > 1000) M = 1000; if (M < 0) M = 0;
    if (100 <= E1 && E1 <= 199) {
        switch (ID) {
        case 1: {
            HP = HP + 75;
            if (HP > 1000) HP = 1000;
            return HP + M;
        }
        case 2: {
            return HP + M;
        }
        case 0: {
            int h, J;
            h = (E1 - 100) % 64;
            J = HP % 100;
            if (J > h) {
                if (HP >= 500 && M % 2 == 1) {
                    if (M >= 300) {
                        HP = HP + 50; M = M - 300;
                        if (HP > 1000) HP = 1000;
                        return HP + M;
                    }
                    else return HP + M;
                }
                else if (M % 2 == 0) {
                    if (M >= 200) {
                        HP = HP + 25; M = M - 200;
                        if (HP > 1000) HP = 1000;
                        return HP + M;
                    }
                    else return HP + M;
                }
                else return HP + M;
            }
            else return HP + M;
        }
        }
    }
    else  if (200 <= E1 && E1 <= 299) {
        if (ID == 0) {
            int x;
            x = E1 % 4 + 1;
            switch (x) {
            case 1: {
                if (M % 2 == 1) {
                    if (M >= 190) {
                        HP = HP + 5; M = M - 190;
                        if (HP > 1000) HP = 1000;
                        return HP + M;
                    }
                    else return HP + M;
                }
                else return HP + M;
            }
            case 2: {
                if (M % 2 == 0) {
                    if (M >= 195) {
                        HP = HP + 7; M = M - 195;
                        if (HP > 1000) HP = 1000;
                        return HP + M;
                    }
                    else return HP + M;
                }
                else return HP + M;
            }
            case 3: {
                if (M % 2 == 1) {
                    if (M >= 200) {
                        HP = HP + 9; M = M - 200;
                        if (HP > 1000) HP = 1000;
                        return HP + M;
                    }
                    else return HP + M;
                }
                else return HP + M;
            }
            case 4: {
                if (M % 2 == 0) {
                    if (M >= 205) {
                        HP = HP + 11; M = M - 205;
                        if (HP > 1000) HP = 1000;
                        return HP + M;
                    }
                    else return HP + M;
                }
                else return HP + M;
            }
            }
        }
        else if (ID == 2 || ID == 1)
        {
            int x;
            x = E1 % 4 + 1;
            switch (x)
            {
            case 1:
            {
                if (M >= 190)
                {
                    HP = HP + 5; M = M - 190;
                    if (HP > 1000) HP = 1000;
                    return HP + M;
                }
                else return HP + M;
            }
            case 2:
            {
                if (M >= 195)
                {
                    HP = HP + 7; M = M - 195;
                    if (HP > 1000) HP = 1000;
                    return HP + M;
                }
                else return HP + M;
            }
            case 3:
            {
                if (M >= 200)
                {
                    HP = HP + 9; M = M - 200;
                    if (HP > 1000) HP = 1000;
                    return HP + M;
                }
                else return HP + M;
            }
            case 4:
            {
                if (M >= 205)
                {
                    HP = HP + 11; M = M - 205;
                    if (HP > 1000) HP = 1000;
                    return HP + M;
                }
                else return HP + M;
            }
            }
        }
    }
    else if (300 <= E1 && E1 <= 399) {
        int hp = (HP % 100) % 10, e = (E1 % 100) % 10, a;
        if (e == 2 || e == 3 || e == 5 || e == 7) a = 2 * e; else a = 1;
        if (ID == 0 || ID == 2) {
            if (HP >= 600) {
                if (hp == 2 || hp == 3 || hp == 5 || hp == 7) {
                    if (M >= 500) {
                        HP = ceilf(HP * (100 + 2 * a) / 100.0); M = M - 500;
                        if (HP > 1000) HP = 1000;
                        return HP + M;
                    }
                    else return HP + M;
                }
                else {
                    if (M >= 300) {
                        HP = ceilf(HP * (100 + a) / 100.0); M = M - 300;
                        if (HP > 1000) HP = 1000;
                        return HP + M;
                    }
                    else return HP + M;
                }
            }
            else return HP + M;
        }
        else if (ID == 1) {
            if (HP >= 600) {
                if (hp == 2 || hp == 3 || hp == 5 || hp == 7) {
                    if (M >= 500) {
                        HP = HP + 200; M = M - 500;
                        if (HP > 1000) HP = 1000;
                        return HP + M;
                    }
                    else return HP + M;
                }
                else {
                    if (M >= 300)
                    {
                        HP = ceilf(HP * (100 + a) / 100.0); M = M - 300;
                        if (HP > 1000) HP = 1000;
                        return HP + M;
                    }
                    else return HP + M;
                }
            }
            else return HP + M;
        }
    }
    else if (400 <= E1 && E1 <= 499) {
        if (E1 % 5 == 0) {
            HP = ceilf(HP * 0.9);
            return HP + M;
        }
        else return HP + M;
    }
    else if (E1 == 500) {
        HP = ceilf(HP * 0.75); M = ceilf(M * 0.75);
        return HP + M;
    }
    else return -999;
    return -1;
}
int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2) {
    if (E2 < 100 || E2 >= 500) return -999;
    else {
        if (ID1 == 1 && ID2 == 2) {
            if (100 <= E2 && E2 <= 199) {
                HP1 = ceilf(HP1 * 1.1); if (HP1 > 1000) HP1 = 1000;
                HP2 = ceilf(HP2 * 1.3); if (HP2 > 1000) HP2 = 1000;
            }
            else if (200 <= E2 && E2 <= 299) {
                HP1 = ceilf(HP1 * 1.7); if (HP1 > 1000) HP1 = 1000;
                HP2 = ceilf(HP2 * 1.2); if (HP2 > 1000) HP2 = 1000;
            }
            else if (300 <= E2 && E2 <= 399) {
                if (E2 < 350) {
                    HP1 = HP1 + 30; if (HP1 > 1000) HP1 = 1000;
                }
                else {
                    int e2 = E2 % 100;
                    HP1 = HP1 + e2; if (HP1 > 1000) HP1 = 1000;
                }
            }
            else if (400 <= E2 && E2 <= 499) {
                HP1 = ceilf(HP1 * 1.3); if (HP1 > 1000) HP1 = 1000;
                HP2 = ceilf(HP2 * 0.8);
                HP1 = ceilf(HP1 * 0.5);
            }
            HP1 = ceilf(HP1 * 0.8);
            return 0;
        }
        else if (ID1 == 0 && ID2 == 2) {
            HP1 = 0;
            if (100 <= E2 && E2 <= 199) {
                HP2 = ceilf(HP2 * 1.3);
                if (HP2 > 1000) HP2 = 1000;
            }
            else if (200 <= E2 && E2 <= 299) {
                HP2 = ceilf(HP2 * 1.2);
                if (HP2 > 1000) HP2 = 1000;
            }
            else if (400 <= E2 && E2 <= 499) {
                HP2 = ceilf(HP2 * 0.8);
                if (HP2 > 1000) HP2 = 1000;
            }
            HP1 = ceilf(HP1 * 0.8);
            return -1;
        }
        else if (ID1 == 1 && ID2 == 0) {
            HP2 = 0;
            if (100 <= E2 && E2 <= 199) {
                HP1 = ceilf(HP1 * 1.1);
                if (HP1 > 1000) HP1 = 1000;
            }
            else if (200 <= E2 && E2 <= 299) {
                HP1 = ceilf(HP1 * 1.7);
                if (HP1 > 1000) HP1 = 1000;
            }
            else if (300 <= E2 && E2 <= 399)
            {
                if (E2 < 350) {
                    HP1 = HP1 + 30; if (HP1 > 1000) HP1 = 1000;
                }
                else {
                    int e2 = E2 % 100;
                    HP1 = HP1 + e2; if (HP1 > 1000) HP1 = 1000;
                }
            }
            else if (400 <= E2 && E2 <= 499) {
                HP1 = ceilf(HP1 * 1.3); if (HP1 > 1000) HP1 = 1000;
                HP1 = ceilf(HP1 * 0.5);
            }
            HP1 = ceilf(HP1 * 0.8);
            return 1;
        }
        else if (ID1 == 0 && ID2 == 0) {
            if (100 <= E2 && E2 <= 199) {
                HP1 = ceilf(HP1 * 1.1); if (HP1 > 1000) HP1 = 1000;
                HP2 = ceilf(HP2 * 1.3); if (HP2 > 1000) HP2 = 1000;
            }
            else if (200 <= E2 && E2 <= 299) {
                HP1 = ceilf(HP1 * 1.7); if (HP1 > 1000) HP1 = 1000;
                HP2 = ceilf(HP2 * 1.2); if (HP2 > 1000) HP2 = 1000;
            }
            else if (300 <= E2 && E2 <= 399) {
                if (E2 < 350) {
                    HP1 = HP1 + 30; if (HP1 > 1000) HP1 = 1000;
                }
                else {
                    int e2 = E2 % 100;
                    HP1 = HP1 + e2; if (HP1 > 1000) HP1 = 1000;
                }
            }
            else if (400 <= E2 && E2 <= 499) {
                HP1 = ceilf(HP1 * 1.3); if (HP1 > 1000) HP1 = 1000;
                HP2 = ceilf(HP2 * 0.8);
                HP1 = ceilf(HP1 * 0.5);
            }
            /*..............trung binh dieu hoa ...............*/
            int h1 = HP1, h2 = HP2;
            int ave = ceilf((2 * double(HP1) * double(HP2)) / (double(HP1) + double(HP2)));
            HP1 = h1 - abs(h2 - ave); if (HP1 < 0) HP1 = 0;
            HP2 = h2 - abs(h1 - ave); if (HP2 < 0) HP2 = 0;
            h1 = HP1;
            HP1 = ceilf(HP1 * 0.8);
            if (h1 > HP2) return 1;
            else if (h1 < HP2) return -1;
            else return 0;
            return -1;
        }
    }
    return -1;
}
int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3) {
    if (E3 < 100 || E3 >= 300) return -999;
    else {
        HP1 = ceilf(HP1 * 1.4); if (HP1 > 1000) HP1 = 1000;
        HP2 = ceilf(HP2 * 1.6); if (HP2 > 1000) HP2 = 1000;
        if (ID1 == 1) {
            HP1 = ceilf(HP1 * 2);
            if (HP1 > 1000) HP1 = 1000;
        }
        if (ID2 == 0) HP2 = ceilf(HP2 * 0.95);
        if (100 <= E3 && E3 <= 199) {
            if (ID1 == 1 && ID2 == 2) return 0;
            else if (ID1 == 0 && ID2 == 2) {
                return -1;
            }
            else if (ID1 == 1 && ID2 == 0) {
                HP2 = 0;
                return 1;
            }
            int h1 = HP1, h2 = HP2;
            int ave = ceilf((2 * double(HP1) * double(HP2)) / (double(HP1) + double(HP2)));
            HP1 = h1 - abs(h2 - ave); if (HP1 < 0) HP1 = 0;
            HP2 = h2 - abs(h1 - ave); if (HP2 < 0) HP2 = 0;
            if (HP1 > HP2) return 1;
            else if (HP1 < HP2)
            {
                HP1 = h1;
                return -1;
            }
            else return 0;
        }
        else if (200 <= E3 && E3 <= 299) return 0;

    }
    return -1;
}
int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4) {
    if (E4 < 100 || E4 >= 300) return -999;
    else {
        if (100 <= E4 && E4 <= 199) {
            if (ID2 == 0) HP2 = ceilf(HP2 * 0.1);
            else if (ID2 == 2)HP2 = ceilf(HP2 * 0.3);
            return 0;
        }
        else if (200 <= E4 && E4 <= 299) {
            HP2 = 0;
            return 1;
        }
        return -1;
    }
    //-------------------------------------------------
    return -1;
}
#endif 

