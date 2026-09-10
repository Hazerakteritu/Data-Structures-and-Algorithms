//for maximum

#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

int tree[MAX] = {0};  // Segment tree array
int lazy[MAX] = {0};  // Lazy array

// Function to handle range updates with lazy propagation
void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff) {
    if (lazy[si] != 0) {
        tree[si] += lazy[si];
        if (ss != se) {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }

    if (ss > se || ss > ue || se < us)
        return;

    if (ss >= us && se <= ue) {
        tree[si] += diff;
        if (ss != se) {
            lazy[si * 2 + 1] += diff;
            lazy[si * 2 + 2] += diff;
        }
        return;
    }

    int mid = (ss + se) / 2;
    updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
    updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);

    tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]);
}

void updateRange(int n, int us, int ue, int diff) {
    updateRangeUtil(0, 0, n - 1, us, ue, diff);
}

// Function to handle range maximum queries with lazy propagation
int getMaxUtil(int ss, int se, int qs, int qe, int si) {
    if (lazy[si] != 0) {
        tree[si] += lazy[si];
        if (ss != se) {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }

    if (ss > se || ss > qe || se < qs)
        return INT_MIN;

    if (ss >= qs && se <= qe)
        return tree[si];

    int mid = (ss + se) / 2;
    return max(getMaxUtil(ss, mid, qs, qe, 2 * si + 1),
               getMaxUtil(mid + 1, se, qs, qe, 2 * si + 2));
}

int getMax(int n, int qs, int qe) {
    return getMaxUtil(0, n - 1, qs, qe, 0);
}

// Function to construct the segment tree
void constructST(int si, int ss, int se, int arr[]) {
    if (ss > se)
        return;

    if (ss == se) {
        tree[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;
    constructST(si * 2 + 1, ss, mid, arr);
    constructST(si * 2 + 2, mid+1, se, arr);

    tree[si] = max(tree[si * 2 + 1], tree[si * 2 + 2]);
}


// Driver code
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n,q;
        cin >> n>>q;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        constructST(0, 0, n-1, arr);

        while (q--) {
            int type;
            cin >> type;

            if (type == 1) {
                int l, r;
                cin >> l >> r;
                l--, r--; // Convert to 0-based indexing
                cout << getMax(n, l, r) << endl;
            } else if (type == 2) {
                int l, r, x;
                cin >> l >> r >> x;
                l--, r--; // Convert to 0-based indexing
                updateRange(n, l, r, x);
            } else {
                cout << "Invalid query type!\n";
            }
        }
    }

    return 0;
}
