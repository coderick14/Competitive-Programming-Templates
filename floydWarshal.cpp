#include <bits/stdc++.h>
#define INF INT_MAX
#define ll long long
#define N 100
using namespace std;

ll dist[N][N], path[N][N];

void printPath(ll i, ll j) {
    //cout<<"Printing path from "<<i<<" to "<<j<<endl;
    stack<ll> stk;
    stk.push(j);
    while(path[i][j] != i && path[i][j] != -1) {
        stk.push(path[i][j]);
        j = path[i][j];
    }
    if(path[i][j] == -1) {
        cout<<"No path exists\n";
    }
    else {
        stk.push(i);
        while(!stk.empty()) {
            cout<<stk.top()<<" ";
            stk.pop();
        }
        cout<<"\n";
    }
}

int main() {
    ll i,j,k,n,e,u,v,w;
    cin>>n>>e;
    for(i=0; i<=n; i++) {
        for(j=0; j<=n; j++) {
            if(i==j) {
                dist[i][j] = 0;
                path[i][j] = i;
            }
            else {
                dist[i][j] = INF;
                path[i][j] = -1;

            }
        }
    }

    for(i=0; i<e; i++) {
        cin>>u>>v>>w;
        dist[u][v] = w;
        //dist[v][u] = w; //uncomment for undirected graph
        path[u][v] = u;
    }

    for(k=1; k<=n; k++) {
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                    //cout<<i<<" ---> "<<k<<" ---> "<<j<<" dist = "<<dist[i][j]<<endl;
                }
            }
        }
    }

    cout<<"Distance Matrix\n";
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            if(dist[i][j] == INF)
                cout<<"INF ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Path Matrix\n";
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++)
            printPath(i,j);
    }
    return 0;
}
