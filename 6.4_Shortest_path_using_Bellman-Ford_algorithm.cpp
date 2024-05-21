#include <iostream>
#include <vector>
using namespace std;

int n, st, mtKe[21][21], trace[21], d[21];
vector<pair<int, pair<int, int>>> canh;
int inf = 10000000;

int main(){
    cin >> n >> st;
    for(int i = 1l; i <= n; ++i) d[i] = inf;
    d[st] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> mtKe[i][j];
            if(mtKe[i][j]) canh.push_back({mtKe[i][j], {i, j}});
        }
    }

    int u, v, w;
    for(int i = 1; i < n; ++i){
        for(auto x : canh){
            u = x.second.first;
            v = x.second.second;
            w = x.first;
            if(d[u] != inf && d[v] > d[u] + w){
                d[v] = d[u] + w;
                trace[v] = u;
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << "K/c " << st << " -> " << i << " = " << ((d[i] == inf) ? "INF" : to_string(d[i]));
        cout << "; ";
        if(d[i] != inf){
            int v = i;
            while(v != st){
                cout << v << " <- ";
                v = trace[v];
            }
            if(i == st) cout << i << " <- ";
            cout << st;
        }
        cout << '\n';
    }
}