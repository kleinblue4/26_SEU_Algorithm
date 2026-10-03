#include <bits/stdc++.h>
using namespace std;
int n , tree[200010] , a[50003] , b[50003] ;
inline int lowbit(int x){return x & -x ;}

void add(int x, int k){
    while(x <= n){
        tree[x] += k ;
        x += lowbit(x) ;
    }
}

int query(int x){
    int ans = 0 ;
    while(x){
        ans += tree[x] ;
        x -= lowbit(x) ;
    }
    return ans ;
}

void change(){
    map <int,int> mp ;
    sort(b+1, b+1+n) ;
    for(int i = 1 ; i <= n ; i ++)
        mp[b[i]] = i ;
    for(int i = 1 ; i <= n ; i ++)
        a[i] = mp[a[i]] ;
}

void solve(){
    cin >> n ;
    map <int,int> mp ;
    for(int i = 1 ; i <= n ; i ++)
        tree[i] = 0 ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i] ;
        b[i] = a[i] ;
    }
    change() ;
    
    int ans = 0 ;
    for(int i = n ; i >= 1 ; i --){
        ans += query(a[i]-1) ;
        add(a[i], 1) ;
    }
    cout << ans << endl ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}