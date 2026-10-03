#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007 ;

void solve(){
    int n , k ;
    cin >> n >> k ;
    vector <int> l(k+1), p(k+1) ;
    vector <int> dp(n+10) ;
    for(int i = 1 ; i <= k ; i ++)
        cin >> l[i] >> p[i] ;
    for(int i = 1 ; i <= k ; i ++){
        if(l[i] > n)continue ;
        for(int j = l[i] ; j <= n ; j ++){
            dp[j] = max(dp[j], dp[j-l[i]]+p[i]) ;
        }
    }
    cout << dp[n] << endl ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}