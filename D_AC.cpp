#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct State {
    int pos;
    int swim;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string river;
        cin >> river;

        vector<bool> visited(n + 2, false);
        queue<State> q;
        q.push({0, 0});
        visited[0] = true;
        bool canReach = false;
        while (!canReach && !q.empty()) {
            State current = q.front();
            q.pop();

            int pos = current.pos;
            int swim = current.swim;

            if (pos == 0 || river[pos - 1] == 'L') {
                for (int jump = 1; jump <= m; ++jump) {
                    int newPos = pos + jump;
                    if (newPos == n + 1) {
                        canReach = true;
                        break;
                    }
                    if (newPos <= n && river[newPos - 1] != 'C' && !visited[newPos]) {
                        visited[newPos] = true;
                        q.push({newPos, swim});
                    }
                }
            }

            if (pos > 0 && pos <= n && river[pos - 1] == 'W' && swim < k) {
                int newPos = pos + 1;
                if (newPos == n + 1) {
                    canReach = true;
                    break;
                }
                if (newPos <= n && river[newPos - 1] != 'C' && !visited[newPos]) {
                    visited[newPos] = true;
                    q.push({newPos, swim + 1});
                }
            }
        }

        cout << (canReach ? "YES" : "NO") << endl;
    }
    return 0;
}

