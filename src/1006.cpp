#include <bits/stdc++.h>
using namespace std;

void siftDown(vector<int>& a, int n, int i) {
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int s = i;

        if (l < n && a[l] < a[s]) 
            s = l;
        if (r < n && a[r] < a[s]) 
            s = r;

        if (s == i) break;
        swap(a[i], a[s]);
        i = s;
    }
}

int main() {
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0 ; i < n ; i ++) 
            cin >> a[i];

        for (int i = n / 2 - 1 ; i >= 0 ; i --) 
            siftDown(a, n, i);
        
        for (int i = 0 ; i < n ; i ++) 
            cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}