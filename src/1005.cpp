#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, int left, int right) {
    int pivot = a[left];
    int j = left;
    for (int i = left + 1; i <= right; ++i) {
        if (a[i] < pivot) {
            ++j;
            swap(a[i], a[j]);
        }
    }
    swap(a[left], a[j]);
    return j;
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

        int p = solve(a, 0, n - 1);

        if (p > 0) {
            solve(a, 0, p - 1);
        }
        if (p < n - 1) {
            solve(a, p + 1, n - 1);
        }

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}