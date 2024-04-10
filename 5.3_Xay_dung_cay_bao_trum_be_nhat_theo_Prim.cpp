#include <iostream>
#include <vector>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, st, mtKe[14][14], vst[14];
int inf = 1000;

void solve(){
    vector<pii> canh;
    int ts = 0;
    vst[st] = 1;
    while(canh.size() < n - 1){
        int cur = inf, x ,y;
        for(int i = 1; i <= n; ++i){
            if(vst[i]){
                for(int j = 1; j <= n; ++j){
                    if(!vst[j] && mtKe[i][j] && mtKe[i][j] < cur){
                        cur = mtKe[i][j];
                        x = i; y = j;
                    }
                }
            }
        }
        vst[x] = vst[y] = 1;
        ts += cur;
        canh.push_back({min(x, y), max(x, y)});
    }
    cout << "dH = " << ts << '\n';
    for(auto x : canh) cout << x.fi << ' ' << x.se << '\n';
}

int main(){
    cin >> n >> st;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cin >> mtKe[i][j];
    }
    solve();
}