/*
    Problem Description

        You are given an array A of size N consisting of integers.
        You have to process Q queries of two types on it:
        1. i x, change the i-th element of A to x.
        2. l r, find the maximum value of (A[i]+A[i+1]...A[j]) over all pairs (i,j) such that l <= i <= j <= r.


        Problem Constraints
        1 <= N,Q <= 105
        -1000 <= A[i] <= 1000 (for all i in [1...N])
        
        For query of the 1st type,
         1 <= i <= N
         -1000 <= x <= 1000
        
        For query of the 2nd type,
        1 <= l <= r <= N
*/
#include <bits/stdc++.h>
using namespace std;

struct item {
    int pre;
    int suf;
    int sum;
    int max_sum;
};

struct segtree {
    int size;
    vector<item> items;

    item DEFAULT_ITEM = {INT_MIN/2, INT_MIN/2, 0, INT_MIN/2};

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        items.assign(2 * size, DEFAULT_ITEM);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            items[x] = {v, v, v, v};
            return;
        }
        int m = (lx + rx) >> 1;

        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }

        item left = items[2 * x + 1];
        item right = items[2 * x + 2];
        item cur = DEFAULT_ITEM;

        // setting up the maximum prefix in the segment
        cur.pre = std::max(left.pre, left.sum + right.pre);

        // setting up the maximum suffix in the segment
        cur.suf = std::max(right.suf, right.sum + left.suf);

        // calculating max_sum in segment
        cur.max_sum = std::max(std::max(left.max_sum, right.max_sum), left.suf +right.pre);

        // calculating overall sum of the segment
        cur.sum = left.sum + right.sum;

        items[x] = cur;  
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    item max_sum(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return DEFAULT_ITEM;
        else if (l <= lx && rx <= r) return items[x];
        else {
            int m = (lx + rx) >> 1;
            item left = max_sum(l, r, 2 * x + 1, lx, m);
            item right = max_sum(l, r, 2 * x + 2, m, rx);

            item cur = DEFAULT_ITEM;
            
            // setting up the maximum prefix in the segment
            cur.pre = std::max(left.pre, left.sum + right.pre);

            // setting up the maximum suffix in the segment
            cur.suf = std::max(right.suf, right.sum + left.suf);

            // calculating max_sum in segment
            cur.max_sum = std::max(std::max(left.max_sum, right.max_sum), left.suf + right.pre);

            // calculating overall sum of the segment
            cur.sum = left.sum + right.sum;

            return cur;
        }
    }

    int max_sum(int l, int r) {
        return max_sum(l, r, 0, 0, size).max_sum;
    }
};

int main() {
    vector<int> A = {3, -1, 2, -9, -15};
    vector<vector<int>> B = {
        {2, 1, 4},
        {1, 3, 7},
        {2, 5, 5},
        {2, 1, 3}
    };

    int n = A.size();
    segtree st;
    st.init(n);

    for(int i = 0; i < n; i++) st.set(i, A[i]);

    for (auto q: B){
        if (q[0] == 1) {
            st.set(q[1] - 1, q[2]);
        } else {
            cout << st.max_sum(q[1] - 1, q[2]) << endl;
        }
    }

    return 0;
}