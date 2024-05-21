#include <iostream>
#include <stack>
using namespace std;

int n, st, mtKe[21][21], trace[21], d[21], vst[21];
int inf = 10000000;

int main(){
    cin >> n >> st;
    for(int i = 1l; i <= n; ++i) d[i] = inf;
    d[st] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> mtKe[i][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        int u;
        int Max = inf;
        for(int j = 1; j <= n; ++j){
            if(!vst[j] && d[j] < Max){
                u = j;
                Max = d[j];
            }
        }

        vst[u] = 1;
        for(int j = 1; j <= n; ++j){
            if(mtKe[u][j] && d[j] > d[u] + mtKe[u][j]){
                d[j] = d[u] + mtKe[u][j];
                trace[j] = u;
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