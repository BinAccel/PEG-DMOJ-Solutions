#include <bits/stdc++.h>
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;


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
        scan(t[i][0]);
    }
    for(int i=1, a, b, c;i<N;i++) {
        scan(a);
        scan(b);
        scan(c);
        adj[a].push_back({b, c});
    }
    dfs(1);
    for(int i=2;i<=N;i++) {
        if(t[i][0]>=C&&t[i][1]<=K) ans++;
    }
    printf("%d", ans);
    return 0;
}
