#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll get(string s, int l , int r){
    ll x = 0 ;
    l -- , r -- ;
    for(int i = l ; i <= r ; i ++){
        x = x * 10 + (s[i]-'0') ;
    }
    return x ;
}

void solve(){
    int n , k ;
    cin >> n >> k ;
    string s ; cin >> s ;
    vector <vector<int>> dp(k+3, vector<int>(n+3)) ;
    for(int i = 1 ; i <= n ; i ++){
        dp[0][i] = get(s, 1, i) ;
    }

    for(int i = 1 ; i <= k ; i ++){
        for(int j = i ; j <= n ; j ++){
            ll x = 0 ;
            for(int t = i ; t <= j ; t ++){
                x = max(x, dp[i-1][t] * get(s, t+1, j)) ;
            }
            dp[i][j] = x ;
        }
    }
    cout << dp[k][n] << endl ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}