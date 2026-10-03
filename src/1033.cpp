#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int n , fa[50003]; 

struct Node{
    int d, p ;
    bool operator<(const Node& other) const{
        if(p != other.p)return p > other.p ;
        return d < other.d ;
    }
}node[50003] ;

int find(int x){
    if(x == fa[x])return x ;
    return fa[x] = find(fa[x]) ;
}



void solve(){
    cin >> n ;
    int mx = n ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> node[i].d >> node[i].p ;
        mx = max(mx, node[i].d) ;
    }
    for(int i = 1 ; i <= mx ; i ++)
        fa[i] = i ;
    sort(node+1, node+1+n) ;
    
    ll ans = 0 ;
    
    for(int i = 1 ; i <= n ; i ++){
        int j = find(node[i].d) ;

        if(j > 0){
            ans += node[i].p ;
            fa[j] = j-1 ;
        }
    }

    cout << ans << endl ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}