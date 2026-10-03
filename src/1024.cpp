#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

void solve(){
    int n;
    cin >> n ;

    vector<int> keys(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> keys[i];
    }

    vector<double> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<double> q(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> q[i];
    }

    vector<vector<double>> e(n + 2, vector<double>(n + 2, 0.0));
    vector<vector<double>> w(n + 2, vector<double>(n + 2, 0.0));
    vector<vector<int>> root(n + 2, vector<int>(n + 2, 0));

    for (int i = 1; i <= n + 1; ++i) {
        e[i][i - 1] = 0.0;      
        w[i][i - 1] = q[i - 1];   
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            e[i][j] = 1e9; 

            int r_start = (len == 1) ? i : root[i][j - 1];
            int r_end = (len == 1) ? j : root[i + 1][j];

            for (int r = r_start; r <= r_end; ++r) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("%.6f\n", e[1][n]) ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}