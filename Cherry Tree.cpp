#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, C, K, ans, t[100004][2];
vector<pii>adj[100004];

void dfs(int src) {
    for(pii p:adj[src]) {
        dfs(p.first);
        t[src][0]+=t[p.first][0];
        t[p.first][1]+=p.second;
        t[src][1]+=t[p.first][1];
    }
}

int main() {
    scanf("%d %d %d", &N, &C, &K);
    for(int i=1;i<=N;i++) {
        scanf("%d", &t[i][0]);
    }
    for(int i=1, a, b, c;i<N;i++) {
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({b, c});
    }
    dfs(1);
    for(int i=2;i<=N;i++) {
        if(t[i][0]>=C&&t[i][1]<=K) ans++;
    }
    printf("%d", ans);
    return 0;
}
