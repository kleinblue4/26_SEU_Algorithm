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
            if(j == s[i]){
                dp[j] = max(dp[j] , v[i]) ;
            }else{
                if(dp[j-s[i]] != 0)
                    dp[j] = max(dp[j] , dp[j-s[i]] + v[i]) ;
            }
        }
    }
    
    cout << dp[c] << endl ;
    
}

int main(){
    ios::sync_with_stdio(0) ;
    int n ; cin >> n ;
    while(n--)
        solve() ;
    return 0 ;
}