#include <bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    int last_index;

    vector<int> sums;
    vector<int> deletes;

    void init(int n) {
        size = 1;
        last_index = 0;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0);
        deletes.assign(2 * size, 0);
    }

    void balance(int x, int lx, int rx) {
        if (rx - lx == 1) return;
        else {
            int m = (lx + rx) >> 1;
            balance(2 * x + 1, lx, m);
            balance(2 * x + 2, m, rx);

            sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
            deletes[x] = deletes[2 * x + 1] + deletes[2 * x + 2];
        }
    }

    void add(int v) {
        if (last_index == size) {
            size *= 2;
            sums.resize(size, 0);
            deletes.resize(size, 0);
        }
        sums[last_index] = v;
        balance(0, 0, size);
    }

    int get_deletes(int r, int x, int lx, int rx) {

    }

    int sum(int l, int r) {
        
    }
};

int main() {

    return 0;
}