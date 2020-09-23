#include <bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<int> min;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        min.assign(2 * size, INT_MAX);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            min[x] = v;
            return;
        }
        int m = (rx + lx) >> 1;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        min[x] = std::min(min[2 * x + 1], min[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if ( rx <=  l || lx >= r) return INT_MAX;
        else if ( l <= lx && rx <= r) return min[x];
        else{
            int m = (rx + lx) >> 1;
            int left = query(l, r, 2 * x + 1, lx, m);
            int right = query(l, r, 2 * x + 2, m, rx);
            return std::min(left, right);
        }
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

};
int main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    segtree st;
    st.init(n);

    int x;
    for(int i = 0; i < n; i++) { 
        cin >> x;
        st.set(i, x);
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 1){
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << "\n";
        }
    }

    return 0;
}