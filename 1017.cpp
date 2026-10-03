#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n , tree[200003], a[50003] ;

inline ll lowbit(ll x){return x & -x ;}

void add(int x , ll k){
    while(x <= n){
        tree[x] += k ;
        x += lowbit(x) ;
    }
}

ll query(int x){
    ll ans = 0 ;
    while(x){
        ans += tree[x] ;
        x -= lowbit(x) ;
    }
    return ans ;
}

void solve(){
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++)
        a[i] = 0 , tree[i] = 0 ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i] ;
        a[i] ++ ;
    }
    ll ans = 0 ;
    for(int i = n ; i >= 1 ; i --){
        ans += query(a[i]-1) ;
        add(a[i], 1) ;
    }
    cout << ans << endl ;
}

int main(){
    int t ; cin >> t ;
    while(t --)
        solve() ;
    return 0 ;
}