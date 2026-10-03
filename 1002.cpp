#include <bits/stdc++.h>
using namespace std ;


int main(){
    int n ; 
    cin >> n ;
    for(int i = 0 ; i < n ; i ++){
        int m ;
        cin >> m ;
        vector <int> v ;
        for(int j = 0 ; j < m ; j ++){
            int x ; cin >> x ;
            v.emplace_back(x) ;
        }
        sort(v.begin() , v.end()) ;
        cout << v[1] << endl ;
    }
    return 0 ;
}