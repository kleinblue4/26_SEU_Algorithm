#include <bits/stdc++.h>
using namespace std;


void solve(){
    int m ; cin >> m ;
    vector <int> a(m+3) , cost(3) ;
    vector <int> dp(m+3) ;
    // vector <int> dp(m+3) ;
    for(int i = 1 ; i <= m ; i ++)
        cin >> a[i] ;
    for(int i = 0 ; i < 3 ; i ++)
        cin >> cost[i] ;
    
    for(int i = 1 ; i <= m ; i ++){
        int c[3] = {0} ;
        c[0] = dp[i-1] + cost[0] ;

        int k = i-1 ;
        while(k > 0 && a[i]-a[k]+1 <= 7){
            k -- ;
        }
        c[1] = dp[k] + cost[1] ;

        while(k > 0 && a[i]-a[k]+1 <= 30)
            k -- ;
        c[2] = dp[k] + cost[2] ;

        dp[i] = min(c[0], min(c[1], c[2])) ;
    }
    cout << dp[m] << endl ;
}

int main(){
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    int n ; cin >> n ;
    while(n--)
        solve() ;
    return 0 ;
}


