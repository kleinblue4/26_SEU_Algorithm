#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ; cin >> n ;
    vector <int> v(n+1) ;
    for(int i = 1 ; i <= n ; i++){
        cin >> v[i] ;
    }
    int ans = v[1] , pre = v[1] ;
    for(int i = 2 ; i <= n ; i ++){
        pre = max(pre+v[i], v[i]) ;
        ans = max(ans, pre) ;
    }
    cout << ans << endl ;
}

int main(){
    ios::sync_with_stdio(0) ;
    int n ; cin >> n ;
    while(n--)
        solve() ;
    return 0 ;
}