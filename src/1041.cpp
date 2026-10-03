#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;



void solve(){
    int n , m ;
    cin >> n >> m ;
    vector <int> a(n+m+1) ;
    for(int i = 1 ; i <= n+m ; i ++)
        cin >> a[i] ;
    sort(a.begin()+1, a.begin()+1+n+m) ;
    if((n+m) & 1){
        printf("%.5f\n", 1.0f * a[(n+m+1)/2]) ;
    }else{
        printf("%.5f\n", 1.0f * (a[(n+m)/2] + a[(n+m)/2+1]) / 2.0f) ;
    }
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}