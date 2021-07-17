#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T; cin >> T;

    for (int tt = 1; tt <= T; tt++) {
        vector<int> graph[100001];
        queue<int> q;
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            int input; cin >> input;
            if (i + input > n) continue;
            graph[i].push_back(i + input);
            graph[i + input].push_back(i);
        }

        int cnt = 0;
        bool visit[100001];

        for (int i = 1; i <= n; i++)
            visit[i] = false;

        for (int i = 1; i <= n; i++) {
            if (visit[i] != true) {
                cnt++;
                visit[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    for (int e = 0; e < graph[t].size(); e++) {
                        int d = graph[t][e];
                        if (visit[d] != true) {
                            visit[d] = true;
                            q.push(d);
                        }
                    }
                }
            }
        }
        cout << "Case #" << tt << "\n";
        cout << cnt << "\n";
    }
}