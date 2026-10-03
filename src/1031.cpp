#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int n ;
double d ;

struct Node{
    double x, y ;
    double x1, x2 ;
    bool operator <(const Node& other) const{
        return x2 < other.x2 ;
    }
}node[10003] ;



void solve(){
    cin >> n >> d ;
    for(int i = 1 ; i <= n ; i ++){
        cin >> node[i].x >> node[i].y ;

        double dd = sqrt(d*d - node[i].y * node[i].y) ;
        node[i].x1 = node[i].x - dd ;
        node[i].x2 = node[i].x + dd ;
    }

    sort(node+1, node+1+n) ;
    int ans = 1 ;
    double cur = node[1].x2 ;
    for(int i = 2 ; i <= n ; i ++){
        double dis = (node[i].x - cur) * (node[i].x - cur) + node[i].y * node[i].y;
        if(dis - d*d <= 1e-10)
            continue ;
        else{
            ans ++ ;
            cur = node[i].x2 ;
        }
    }
    cout << ans << endl ;
}

int main(){
    int t ; cin >> t ;
    while(t --)solve() ;
    return 0 ;
}