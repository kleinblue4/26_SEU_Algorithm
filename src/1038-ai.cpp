#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev, cap;
    long long cost;
};

class MCMF {
    int N;
    vector<vector<Edge>> g;
    vector<long long> dist;
    vector<int> prevv, preve;
    const long long INF = (1LL << 60);

public:
    MCMF(int n) : N(n), g(n), dist(n), prevv(n), preve(n) {}

    void addEdge(int from, int to, int cap, long long cost) {
        Edge a{to, (int)g[to].size(), cap, cost};
        Edge b{from, (int)g[from].size(), 0, -cost};
        g[from].push_back(a);
        g[to].push_back(b);
    }

    pair<int, long long> minCostMaxFlow(int s, int t) {
        int flow = 0;
        long long cost = 0;

        while (true) {
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;

            vector<bool> inq(N, false);
            queue<int> q;
            q.push(s);
            inq[s] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                inq[u] = false;

                for (int i = 0; i < (int)g[u].size(); i++) {
                    Edge &e = g[u][i];
                    if (e.cap > 0 && dist[e.to] > dist[u] + e.cost) {
                        dist[e.to] = dist[u] + e.cost;
                        prevv[e.to] = u;
                        preve[e.to] = i;
                        if (!inq[e.to]) {
                            q.push(e.to);
                            inq[e.to] = true;
                        }
                    }
                }
            }

            if (dist[t] == INF) break;

            int add = INT_MAX;
            for (int v = t; v != s; v = prevv[v]) {
                Edge &e = g[prevv[v]][preve[v]];
                add = min(add, e.cap);
            }

            flow += add;
            cost += 1LL * add * dist[t];

            for (int v = t; v != s; v = prevv[v]) {
                Edge &e = g[prevv[v]][preve[v]];
                e.cap -= add;
                g[v][e.rev].cap += add;
            }
        }

        return {flow, cost};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }

        int S = 0;
        int T = n + m + 1;

        MCMF mcmf(T + 1);

        for (int j = 1; j <= n; j++) {
            mcmf.addEdge(S, j, 1, 0);
        }

        for (int i = 1; i <= m; i++) {
            mcmf.addEdge(n + i, T, 1, 0);
        }

        for (int j = 1; j <= n; j++) {
            int k;
            cin >> k;

            for (int x = 0; x < k; x++) {
                int woman;
                cin >> woman;

                mcmf.addEdge(j, n + woman, 1, a[woman][j]);
            }
        }

        auto result = mcmf.minCostMaxFlow(S, T);

        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}