#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int n ; 

struct Node{
    int x , h ;
    bool operator <(const Node& other) const{
        if(x != other.x)return x < other.x ;
        return h < other.h ;
    }
};


void solve(){
    cin >> n ;
    vector <Node> v ;
    for(int i = 1 ; i <= n ; i ++){
        int a , b , h ;
        cin >> a >> b >> h ;
        v.push_back({a, -h}) ;
        v.push_back({b, h}) ;
    }

    sort(v.begin(), v.end()) ;
    multiset <int> se ;
    se.insert(0) ;
    int last = 0 ;
    for(auto node : v){
        if(node.h < 0){
            se.insert(-node.h) ;
        }else{
            se.erase(se.find(node.h)) ;
        }

        int now = *se.rbegin() ;
        if(now != last){
            cout << node.x << ' ' << now << endl; 
            last = now ;
        }
    }
}

int main(){
    // int t ; cin >> t ;
    // while(t --)solve() ;
    solve() ;
    return 0 ;
}