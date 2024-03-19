#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, st, mtKe[15][15];

void solve(){
    vector<int> res;
    stack<int> s;
    s.push(st);
    while(!s.empty()){
        int u = s.top();
        int ok = 1;
        for(int i = 1; i <= n; ++i){
            if(mtKe[u][i]){
                s.push(i);
                mtKe[u][i] = mtKe[i][u] = 0;
                ok = 0;
                break;
            }
        }
        if(ok){
            s.pop();
            res.push_back(u);
        }
    }
    reverse(begin(res), end(res));
    for(int x : res) cout << x << ' ';
}

int main(){
    cin >> n >> st;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    solve();
}