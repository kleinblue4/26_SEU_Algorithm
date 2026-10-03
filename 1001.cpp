#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n ;
    cin >> n ;
    getchar() ;
    vector <int> ans ;
    for(int i = 0 ; i < n ; i ++){
        string s ;
        getline(cin, s) ;
        int cnt = 0 ;
        for(auto c : s)
            if(c >= '0' && c <= '9')
                cnt ++ ;
        ans.emplace_back(cnt) ;
            }
    for(auto a : ans)
    cout << a << endl ;
    return 0;
}