#include <bits/stdc++.h>
using namespace std;

int fa[603] ;

int find(int x){
    if(fa[x] == x)return x ;
    return fa[x] = find(fa[x]) ;
}

void unionl(int x , int y){
    int fx = find(x) ;
    int fy = find(y) ;
    fa[fx] = fy ;
}

struct Node{
    long long w ;
    int u, v;
}node[200003] ;

bool cmp(Node a, Node b){
    return a.w < b.w ;
}


void solve(){

    int n , e , cnt = 0;
    cin >> n >> e ;
    for(int i = 1 ; i <= n ; i ++)
        fa[i] = i ;
    for(int i = 1 ; i <= e ; i ++){
        int u, v ;
        long long w ;
        cin >> u >> v >> w ;
        node[i].w = w ;
        node[i].u = u ;
        node[i].v = v ;
    }

    long long ans = 0 , fn = 0 ;
    sort(node+1, node+e+1, cmp) ;
    for(int i = 1 ; i <= e ; i ++){
        int u = node[i].u , v = node[i].v ;
        long long val = node[i].w ;
        int fu = find(u), fv = find(v) ;
        if(fu == fv)continue ;
        ans += val ;
        unionl(fu, fv) ;
        fn ++ ;
        if(fn == n-1)break ;
    }
    if(fn != n-1)
        cout << -1 << endl ;
    else
        cout << ans << endl ;
}

int main(){
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    int n ; cin >> n ;
    while(n--)
        solve() ;
    return 0 ;
}