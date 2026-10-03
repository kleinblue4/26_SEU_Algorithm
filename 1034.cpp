#include <bits/stdc++.h>
using namespace std;

int n ;
vector <int> v[50003] ;
vector <array<int,2>> dp(50003, array<int,2>()) ;
vector <int> c(50003) ; // 黑 0  白 1

void dfs(int u, int fa){
    dp[u][0] = 1 ;
    dp[u][1] = 0 ;
    for(auto x : v[u]){
        if(x == fa)continue ;
        dfs(x, u) ;
        dp[u][0] += dp[x][1] ;
        dp[u][1] += max(dp[x][0], dp[x][1]) ;
    }
}

void solve(){
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++)
        v[i].clear(), dp[i][0] = dp[i][1] = 0 , c[i] = 0;
    
    for(int i = 1 ; i < n ; i ++){
        int a, b ;
        cin >> a >> b ;
        v[a].push_back(b) ;
        v[b].push_back(a) ;
    }
    dfs(1, 0) ;
    cout << max(dp[1][0] , dp[1][1]) << endl ;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0) ;
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}