#include <bits/stdc++.h>
using namespace std;

bool vis[503] ;
vector <pair<long long, int>> edg[503] ;
long long dis[503] ;
void solve(){
    int n, e, st, ed ;
    cin >> n >> e >> st >> ed ;
    for(int i = 1 ; i <= n ; i ++){
        dis[i] = 1e9 , vis[i] = false ;
        edg[i].clear() ;
    }

    dis[st] = 0 ;

    for(int i = 0 ; i < e ; i ++){
        int u, v; long long w ;
        cin >> u >> v >> w ;
        edg[u].push_back({w, v}) ;
        edg[v].push_back({w, u}) ;
    }

    priority_queue <pair<long long,int>, vector<pair<long long, int>>, greater<>> q ;
    q.push({0, st}) ;
    while(!q.empty()){
        auto [val, u] = q.top() ; q.pop() ;
        if(vis[u]) continue ;
        vis[u] = true ;
        if(u == ed)break ;

        for(auto [v, to]: edg[u]){
            if(dis[to] > dis[u] + v){
                dis[to] = dis[u] + v ;
                q.push({dis[to], to}) ;
            }
        }
    }
    if(dis[ed] == 1e9)cout << -1 << endl ;
    else cout << dis[ed] << endl ;
}

int main(){
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    int n ; cin >> n ;
    while(n--)
        solve() ;
    return 0 ;
}