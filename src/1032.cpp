#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;



void solve(){
    int n ; cin >> n ;
    double ans = 1.0f;
    for(int i = 1 ; i < n ; i ++){
        double x ; cin >> x ;
        ans += 1.0f * x / 100.f ;
    }
    printf("%.6f\n", ans) ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}