#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& a, int l, int r, int depth, vector<int>& ans) {
    if (l == r) {
        if (depth == 3) {
            ans[l] = a[l];
        }
        return;
    }

    int mid = (l + r) / 2;

    solve(a, l, mid, depth + 1, ans);
    solve(a, mid + 1, r, depth + 1, ans);

    vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }

    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];

    for (int t = 0; t < k; ++t) {
        a[l + t] = tmp[t];
    }

    if (depth == 3) {
        for (int t = l; t <= r; ++t) {
            ans[t] = a[t];
        }
    }
}

int main() {
    int m;
    cin >> m;

    while (m--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> ans(n);

        solve(a, 0, n - 1, 1, ans);

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}