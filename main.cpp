#include <iostream>

using namespace std;

struct a {
    long long b = 0;
    long long c = 0;
    long long d = 0;
};

void e(const int f[], int g) {
    for (int h = 0; h < g; ++h) {
        cout << f[h] << " ";
    }
    cout << endl;
}

void i(const int j[], int k[], int l) {
    for (int m = 0; m < l; ++m) {
        k[m] = j[m];
    }
}

bool n(const int o[], const int p[], int q) {
    if (q <= 0) return true;

    long long r = 0, s = 0;
    long long t = 0, u = 0;

    for (int v = 0; v < q; ++v) {
        r += o[v];
        t += (long long)o[v] * o[v];
        s += p[v];
        u += (long long)p[v] * p[v];
    }

    bool w = true;
    for (int x = 0; x < q - 1; ++x) {
        if (p[x] > p[x + 1]) {
            w = false;
            break;
        }
    }

    return w && (r == s) && (t == u);
}

int y(const int z[], int aa, int ab, int ac, a& ad) {
    int ae = aa;
    int af = ab;
    while (ae < af) {
        int ag = ae + (af - ae) / 2;
        ad.b++;
        if (z[ag] <= ac) {
            ae = ag + 1;
        }
        else {
            af = ag;
        }
    }
    return ae;
}

a ah(int ai[], int aj) {
    a ad;
    for (int ak = 1; ak < aj; ++ak) {
        int al = ai[ak];
        int am = y(ai, 0, ak, al, ad);

        for (int an = ak - 1; an >= am; --an) {
            ai[an + 1] = ai[an];
            ad.c++;
        }
        if (am != ak) {
            ai[am] = al;
            ad.c++;
        }
    }
    return ad;
}

a ao(int ap[], int aq) {
    a ad;
    for (int ar = 1; ar < aq; ++ar) {
        int as = ap[ar];
        ad.b++;
        int at = ar - 1;
        while (at >= 0) {
            ad.b++;
            if (ap[at] > as) {
                ap[at + 1] = ap[at];
                ad.c++;
                at--;
            }
            else {
                break;
            }
        }
        ap[at + 1] = as;
        ad.c++;
    }
    return ad;
}

a au(int av[], int aw) {
    a ad;
    int ax = 0;
    int ay = aw - 1;
    bool az = true;

    while (ax < ay && az) {
        az = false;
        ad.d++;

        for (int ba = ax; ba < ay; ++ba) {
            ad.b++;
            if (av[ba] > av[ba + 1]) {
                int bb = av[ba];
                av[ba] = av[ba + 1];
                av[ba + 1] = bb;
                ad.c += 3;
                az = true;
            }
        }
        ay--;

        if (!az) break;

        az = false;
        ad.d++;

        for (int ba = ay; ba > ax; --ba) {
            ad.b++;
            if (av[ba - 1] > av[ba]) {
                int bb = av[ba];
                av[ba] = av[ba - 1];
                av[ba - 1] = bb;
                ad.c += 3;
                az = true;
            }
        }
        ax++;
    }
    return ad;
}

a bc(int bd[], int be) {
    a ad;
    bool bf;
    for (int bg = 0; bg < be - 1; ++bg) {
        bf = false;
        for (int bh = 0; bh < be - bg - 1; ++bh) {
            ad.b++;
            if (bd[bh] > bd[bh + 1]) {
                int bi = bd[bh];
                bd[bh] = bd[bh + 1];
                bd[bh + 1] = bi;
                ad.c += 3;
                bf = true;
            }
        }
        ad.d++;
        if (!bf) break;
    }
    return ad;
}

int main() {
    const int bj = 12;
    int bk[bj] = { 20, 2, 29, 8, 16, 4, 25, 12, 1, 31, 6, 18 };
    int bl[bj];

    cout << " INDIVIDUAL VARIANT 5 " << endl;
    cout << "Initial array: ";
    e(bk, bj);
    cout << endl;

    i(bk, bl, bj);
    a bm = ah(bl, bj);
    bool bn = n(bk, bl, bj);
    cout << " Binary Insertion Sort " << endl;
    cout << "Sorted: "; e(bl, bj);
    cout << "Comparisons: " << bm.b << ", Moves: " << bm.c << endl;
    cout << "Verification status: " << (bn ? "SUCCESS" : "FAILED") << endl << endl;

    i(bk, bl, bj);
    a bo = au(bl, bj);
    bool bp = n(bk, bl, bj);
    cout << " Shaker Sort " << endl;
    cout << "Sorted: "; e(bl, bj);
    cout << "Comparisons: " << bo.b << ", Moves: " << bo.c << ", Passes: " << bo.d << endl;
    cout << "Verification status: " << (bp ? "SUCCESS" : "FAILED") << endl << endl;

    int bq[] = { 10, 100, 1000 };
    int br = 3;

    cout << " COMPARATIVE EXPERIMENTS ON DIFFERENT DATA SETS " << endl;

    for (int bs = 0; bs < br; ++bs) {
        int bt = bq[bs];
        int* bu = new int[bt];
        int* bv = new int[bt];
        int* bw = new int[bt];
        int* bx = new int[bt];

        for (int by = 0; by < bt; ++by) {
            bu[by] = by + 1;
            bv[by] = bt - by;
            bw[by] = by + 1;
            bx[by] = (by * 37) % 101;
        }
        for (int by = 0; by < bt; by += (bt > 10 ? bt / 5 : 2)) {
            if (by + 1 < bt) {
                int bz = bw[by];
                bw[by] = bw[by + 1];
                bw[by + 1] = bz;
            }
        }

        cout << "\n--- Array Size: " << bt << " ---" << endl;

        int* ca = new int[bt];

        cout << "[Ascending order]" << endl;
        i(bu, ca, bt);
        a cb = ao(ca, bt);
        i(bu, ca, bt);
        a cc = ah(ca, bt);
        cout << "  Standard Ins -> Comp: " << cb.b << " | Binary Ins -> Comp: " << cc.b << endl;

        i(bu, ca, bt);
        a cd = bc(ca, bt);
        i(bu, ca, bt);
        a ce = au(ca, bt);
        cout << "  Standard Bub -> Comp: " << cd.b << ", Passes: " << cd.d << " | Shaker -> Comp: " << ce.b << ", Passes: " << ce.d << endl;

        cout << "[Descending order]" << endl;
        i(bv, ca, bt);
        a cf = ao(ca, bt);
        i(bv, ca, bt);
        a cg = ah(ca, bt);
        cout << "  Standard Ins -> Comp: " << cf.b << " | Binary Ins -> Comp: " << cg.b << endl;

        i(bv, ca, bt);
        a ch = bc(ca, bt);
        i(bv, ca, bt);
        a ci = au(ca, bt);
        cout << "  Standard Bub -> Comp: " << ch.b << ", Passes: " << ch.d << " | Shaker -> Comp: " << ci.b << ", Passes: " << ci.d << endl;

        cout << "[Nearly sorted order]" << endl;
        i(bw, ca, bt);
        a cj = ao(ca, bt);
        i(bw, ca, bt);
        a ck = ah(ca, bt);
        cout << "  Standard Ins -> Comp: " << cj.b << " | Binary Ins -> Comp: " << ck.b << endl;

        i(bw, ca, bt);
        a cl = bc(ca, bt);
        i(bw, ca, bt);
        a cm = au(ca, bt);
        cout << "  Standard Bub -> Comp: " << cl.b << ", Passes: " << cl.d << " | Shaker -> Comp: " << cm.b << ", Passes: " << cm.d << endl;

        delete[] bu;
        delete[] bv;
        delete[] bw;
        delete[] bx;
        delete[] ca;
    }

    return 0;
}
