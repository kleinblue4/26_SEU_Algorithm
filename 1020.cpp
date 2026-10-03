#include <bits/stdc++.h>
using namespace std;
vector <long long> r(503), s(503) ;
vector <vector<long long>> dp(503, vector<long long>(503, 0)) ;

void solve(){
    long long n ; cin >> n ;

    for(int i = 1 ; i <= n ; i ++)
        cin >> r[i] >> s[i] ;

    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            if(i==j)dp[i][j] = 0 ;
            else dp[i][j] = 1e9 ;
        }
    }

    for(int i = 1 ; i <= n-1 ; i ++){
        for(int j = 1 ; j <= n-i ; j ++){
            for(int k = j ; k < i+j ; k ++){
                // 
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + r[j] * s[k] * s[i+j]) ;
                // printf("i+j: %d, k+1: %d\n",i+j, k+1) ;
            }
        }
    }
    cout << dp[1][n] << endl ;

}

int main(){
    ios::sync_with_stdio(0) ;
    int n ; cin >> n ;
    while(n--)
        solve() ;
    return 0 ;
}