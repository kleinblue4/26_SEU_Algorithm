#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;


void solve(){
    int n ; cin >> n ;
    vector <ll> c(n+3), y(n+3) ;
    for(int i = 1 ; i <= n ; i ++)
        cin >> c[i] ;
    for(int i = 1 ; i <= n ; i ++)
        cin >> y[i] ;
    ll ans = 0 ;
    ll p = 0 ;
    for(int i = 1 ; i <= n ; i ++){
        if(i == 1){
            p = c[i] ;
        }else{
            p = min(p+1, c[i]) ;
        }
        ans += p * y[i] ;
    }
    cout << ans << endl ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}