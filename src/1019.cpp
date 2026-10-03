#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n , c ;
    cin >> n >> c ;
    vector <int> s(n+1), v(n+1) ;
    vector <int> dp(103, 0) ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> s[i] >> v[i] ;
    }
    for(int i = 1 ; i <= n ; i ++){
        for(int j = c ; j >= s[i] ; j --){
            dp[j] = max(dp[j], dp[j-s[i]] + v[i]) ;
        }
    }
    int ans = 0 ;
    for(int i = 0 ; i <= c ; i ++)
        ans = max(ans , dp[i]) ;
    cout << ans << endl ;
}

int main(){
    ios::sync_with_stdio(0) ;
    int n ; cin >> n ;
    while(n--)
        solve() ;
    return 0 ;
}