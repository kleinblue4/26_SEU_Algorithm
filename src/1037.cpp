#include <bits/stdc++.h>
using namespace std;

int match[505] ;
bool vis[505] ;
vector <int> v[505] ;
int n , m ;

int dfs(int u){
    for(auto x : v[u]){
        if(vis[x])continue ;
        vis[x] = true ;
        if(match[x] == -1 || dfs(match[x])){
            match[x] = u ;
            return 1 ;
        }
    }
    return 0 ;
}

void solve(){
    cin >> n >> m ;
    for(int i = 1 ; i <= max(n,m) ; i ++){
        v[i].clear() ;
        match[i] = -1 ;
    }
    for(int i = 1 ; i <= n ; i ++){
        int k ; cin >> k ;
        while(k --){
            int x ; cin >> x ;
            v[i].push_back(x) ;
        }
    }
    int ans = 0 ;
    for(int i = 1 ; i <= n ; i ++){
        memset(vis, false, sizeof(vis)) ;
        if(dfs(i))ans ++ ;
    }
    cout << ans << endl ;
}

int main(){
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    int t ; cin >> t ;
    while(t--)
        solve() ;
    return 0 ;
}