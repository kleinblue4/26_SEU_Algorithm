#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007 ;

vector <vector<int>> dp(10003, vector<int>(103, 0)) ;

void solve(){
    int k, n ;
    
    cin >> k >> n ;
    
    
    for(int i = 1 ; i <= n ; i ++)
        dp[i][1] = i ;
    for(int i = 1 ; i <= k ; i ++)
        dp[1][i] = 1 ;

    for(int i = 2 ; i <= n ; i ++){
        for(int j = 2 ; j <= k ; j ++){
            dp[i][j] = dp[i][j-1] ;
            // for(int w = 1 ; w <= i ; w ++){
            //     dp[i][j] = min(dp[i][j] , max(dp[w-1][j-1] , dp[i-w][j])+1) ;
            // }
            int l = 0 , r = i ;
            while(l < r){
                int mid = (l+r) >> 1 ;
                int a = dp[mid-1][j-1] ;
                int b = dp[i-mid][j] ;
                if(a > b){
                    r = mid ;
                    dp[i][j] = min(dp[i][j] , a+1) ;
                }else{
                    l = mid+1 ;
                    dp[i][j] = min(dp[i][j] , b+1) ;
                }
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