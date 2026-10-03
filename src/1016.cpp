#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n , x ; cin >> n >> x;
    vector <int> v(n+1) ;
    set <int> se ;
    for(int i = 1 ; i <= n ; i++){
        cin >> v[i] ;
        se.insert(v[i]) ;
    }
    for(int i = 1 ; i <= n ; i ++){
        if(se.find(x-v[i]) != se.end()){
            cout << "yes\n" ;
            return ;
        }
    }
    cout << "no\n" ;
}

int main(){
    ios::sync_with_stdio(0) ;
    int n ; cin >> n ;
    while(n--)
        solve() ;
    return 0 ;
}