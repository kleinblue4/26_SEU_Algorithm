#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

void solve(){
    int n, k ;
    cin >> n >> k ;
    
    vector <vector<ll>> dp(n+3, vector<ll>(k+3,0)) , sum(n+3, vector<ll>(n+3, 0));
    vector <ll> a(n+3) ;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i] ;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = i ; j <= n ; j ++){
            sum[i][j] = sum[i][j-1] + a[j] ;
        }
    }

    for(int i = 1 ; i <= n ; i ++){
        dp[i][0] = sum[1][i] ;
    }

    for(int j = 1 ; j <= k ; j ++){
        for(int i = j+1 ; i <= n ; i ++){
            for(int t = j ; t < i ; t ++){
                dp[i][j] = max(dp[i][j] , dp[t][j-1] * sum[t+1][i]) ;
            }
        }
    }
    cout << dp[n][k] << endl ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}