/*

*/

#include <bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<int> ones;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        ones.assign(2 * size, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            ones[x] = v;
            return;
        }
        int m = (rx + lx) >> 1;

        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        ones[x] = ones[2 * x + 1] + ones[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    void change(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            ones[x] = 0;
            return;
        }
        int m = (lx + rx) >> 1;

        if (i < m) change(i, 2 * x + 1, lx, m);
        else change(i, 2 * x + 2, m, rx);

        ones[x] = ones[2 * x + 1] + ones[2 * x + 2];
    }
    void change(int i) {
        change(i, 0, 0, size);
    }

    int  get(int n, int x, int lx, int rx) {
        if (rx - lx == 1) return lx;
        else {

            int left = 2 * x + 1;
            int right = 2 * x + 2;

            int m = (lx + rx) >> 1;

            if (n <= ones[left]) {
                return get(n, 2 * x + 1, lx, m);
            } else {
                return get(n - ones[left], 2 * x + 2, m, rx);
            }
        }
    
    }

    int get(int n) {
        if (ones[0] < n) return -1;
        return get(n, 0, 0, size) + 1;
    }
};

int main() {
    int A = 5;
    vector<vector<int>> B = {{0, 3}, {1, 4}, {0, 3}, {1, 5}};

    segtree st;
    st.init(A);

    for (int i = 0; i < A; i++) st.set(i, 1);

    // for(auto a: st.ones) cout << a << " ";

    for(auto q: B) {
        if (q[0] == 0) {
            st.change(q[1] - 1);
            // for(auto a: st.ones) cout << a << " ";
        }
        else {
            cout << st.get(q[1]) << endl;
        }
    }



    return 0;
}