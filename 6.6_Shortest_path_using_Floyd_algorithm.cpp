#include <iostream>
#include <stack>
using namespace std;

int n, mtKe[21][21], trace[21][21], d[21][21];
int inf = 10000000;

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> mtKe[i][j];
            d[i][j] = mtKe[i][j];
            if(i != j && !mtKe[i][j]) d[i][j] = inf; 
            trace[i][j] = i;
        }
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i != j && d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    trace[i][j] = trace[k][j];
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << "K/c " << i << " -> " << j << " = " << d[i][j] << "; ";
            int u = i, v = j;
            cout << u;
            stack<int> res;
            while(v != u){
                res.push(v);
                v = trace[u][v];
            }
            while(!res.empty()){
                cout << " --> " << res.top();
                res.pop();
            }
            cout << '\n';
        }
        cout << '\n';
    }
}