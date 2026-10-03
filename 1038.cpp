#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 ;

int match[505] ;
bool vis[505] ;
int n , m , match[103] , va[103], vb[103] , pre[103];
int la[103], lb[103], w[103][103], d[103] ;

void bfs(int u){
    int x, y=0, yy, delta ;
    memset(pre, 0, sizeof(pre)) ;
    for(int i = 1 ; i <= n ; i ++)
        d[i] = INF ;
    match[y] = u ;
    while(1){
        x = match[y], delta = INF, vb[y] = 1 ;
        for(int i = 1 ; i <= n ; i ++){
            if(vb[i])continue ;
            if(d[i] > la[x]+lb[i]-w[x][i]){
                d[i] = la[x]+lb[i]-w[x][i] ;
                pre[i] = y ;
            }
            if(d[i] < delta){
                delta = d[i], yy = i ;
            }
        }
        for(int i = 0 ; i <= n ; i ++){
            if(vb[i])
                la[match[i]] -= delta, lb[i] += delta ;
            else
                d[i] -= delta ;
        }
        y = yy ;
        if(match[y] == -1)break ;
    }
    while(y){
        match[y] = match[pre[y]] ;
        y = pre[y] ;
    }
}

int KM(){
    memset(match, -1, sizeof(match)) ;
    for(int i = 1 ; i <= n ; i ++){
        memset(vb, 0, sizeof(vb)) ;
        bfs(i) ;
    }
    int res = 0 ;
    for(int i = 1 ; i <= n ; i ++)
        res += w[match[i]][i] ;
    return res ;
}

void solve(){
    cin >> n >> m ;
    for(int i = 1 ; i <= m ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            w[i][j] = w[j][i] = INF ;
        }
    }
    for(int i = 1 ; i <= m ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            cin >> w[j][i] ;
            w[i][j] = w[j][i] ;
        }
    }
    for()
    cout << KM() << endl ;

}

int main(){
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    int t ; cin >> t ;
    while(t--)
        solve() ;
    return 0 ;
}