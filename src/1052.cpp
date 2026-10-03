#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007 ;

void solve(){
    int n, m, s;
    cin >> n >> m ;
    vector <int> a(n+1) , d(m+10, 0) ;
    for(int i = 1 ; i <= n ; i ++)
        cin >> a[i] ;
    
    int sum = 0 ;
    d[0] = 1 ;
    for(int i = 1 ; i <= n ; i ++){
        sum += a[i] ;
        for(int j = min(sum, m) ; j > 0 ; j --){
            for(int k = max(0, j-a[i]) ; k <= j-1  ; k ++){
                d[j] += d[k] ;
                d[j] = d[j] % mod ;
            }
        }
    }
    cout << d[m] % mod << endl ;
    
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}