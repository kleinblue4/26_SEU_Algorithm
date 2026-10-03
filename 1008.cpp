#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ; cin >> n ;
    vector <int> v(n+2) , g(30003, 0) ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> v[i] ;
    }
    int cnt = 0 ;

    for(int i = 1 ; i <= n ; i ++){
        int l = 1 , r = cnt+1 , k = 1;
        while(l < r){
            int mid = (l+r) >> 1 ;
            if(g[mid] >= v[i])
                l = mid+1 , k = mid+1;
            else
                r = mid ;
        }

        if(k > cnt)
            g[++cnt] = v[i];
        else    
            g[k] = v[i] ;
    }

    cout << cnt << ' ' ;

    cnt = 0 ;
    for(int i = 1 ; i <= n ; i ++){
        int l = 1 , r = cnt+1 , k = 1 ;
        while(l < r){
            int mid = (l+r) >> 1 ;
            if(g[mid] < v[i])
                l = mid+1 , k = mid+1 ;
            else
                r = mid ;
        }

        if(k > cnt)
            g[++cnt] = v[i] ;
        else
            g[k] = v[i] ;
    }
    cout << cnt << endl ;
}

int main(){
    ios::sync_with_stdio(0) ;
    int n ; cin >> n ;
    while(n--)
        solve() ;
    
}