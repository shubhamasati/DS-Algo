#include <bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<int> min;
    vector<int> number;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        min.assign(2 * size, INT_MAX);
        number.assign(2 * size, 1);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            min[x] = v;
            return;
        }
        int m = (rx + lx) >> 1;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        int left = min[2 * x + 1];
        int right = min[2 * x + 2];
        
        if (left < right) {
            number[x] = number[2 * x + 1];
        } else if (right < left) {
            number[x] = number[2 * x + 2];
        } else {
            number[x] = number[2 * x + 1] + number[2 * x + 2];
        }
        min[x] = std::min(left, right);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    pair<int, int> query(int l, int r, int x, int lx, int rx) {
        if ( rx <=  l || lx >= r) return {INT_MAX, 0};
        else if ( l <= lx && rx <= r) return {min[x], number[x]};
        else{
            int m = (rx + lx) >> 1;
            pair<int, int> left = query(l, r, 2 * x + 1, lx, m);
            pair<int, int> right = query(l, r, 2 * x + 2, m, rx);
            
            if ( left.first < right.first ) {
                return {std::min(left.first, right.first), left.second};
            } else if ( right.first < left.first ) {
                return {std::min(left.first, right.first), right.second};
            } else {
                return {std::min(left.first, right.first), left.second + right.second};
            }

        }
    }

    pair<int, int> query(int l, int r) {
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
            pair<int, int> ans = st.query(l, r);
            cout << ans.first << " " << ans.second << "\n";
        }
    }

    return 0;
}