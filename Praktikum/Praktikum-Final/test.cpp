#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, T;
    long long HP_start, K;
    long long D_realm, D_sword;
    
    if (!(cin >> N >> T)) return 0;
    cin >> HP_start >> K;
    cin >> D_realm >> D_sword;
    
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }
    
    // BFS untuk komponen yang terhubung dari (0,0) - 8 arah
    vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int, int>> q;
    unordered_set<int> rows_in_comp, cols_in_comp;
    
    // Asumsikan (0,0) adalah lantai sesuai batasan
    if (grid[0][0] == '.') {
        visited[0][0] = true;
        q.push({0, 0});
    }
    
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        rows_in_comp.insert(r);
        cols_in_comp.insert(c);
        for (int dir = 0; dir < 8; ++dir) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc] && grid[nr][nc] == '.') {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    
    vector<pair<int, int>> attacks(T); // (tipe, parameter)
    for (int i = 0; i < T; ++i) {
        int type;
        cin >> type;
        int param = -1;
        if (type == 3 || type == 4) {
            cin >> param;
            --param; // Ubah ke 0-indexed
        }
        attacks[i] = {type, param};
    }
    
    // Pre-komputasi kerusakan
    vector<long long> damage_f(T), damage_a(T);
    for (int i = 0; i < T; ++i) {
        auto [type, param] = attacks[i];
        long long forced_sword = 0;
        
        if (type == 3) { // Row Slash
            bool row_contains_target = rows_in_comp.count(param);
            bool component_is_single_row = rows_in_comp.size() == 1;
            if (row_contains_target && component_is_single_row) {
                forced_sword = D_sword;
            }
        } else if (type == 4) { // Column Slash
            bool col_contains_target = cols_in_comp.count(param);
            bool component_is_single_col = cols_in_comp.size() == 1;
            if (col_contains_target && component_is_single_col) {
                forced_sword = D_sword;
            }
        }
        
        if (type == 1) {
            damage_f[i] = D_realm + forced_sword;
            damage_a[i] = 0 + forced_sword;
        } else if (type == 2) {
            damage_f[i] = 0 + forced_sword;
            damage_a[i] = D_realm + forced_sword;
        } else { // type 3 or 4
            damage_f[i] = forced_sword;
            damage_a[i] = forced_sword;
        }
    }
    
    // DP
    const long long NEG_INF = -4e18;
    long long dp_f = HP_start;
    long long dp_a = NEG_INF;
    
    for (int i = 0; i < T; ++i) {
        long long new_dp_f = max(dp_f, dp_a - K) - damage_f[i];
        long long new_dp_a = max(dp_a, dp_f - K) - damage_a[i];
        dp_f = new_dp_f;
        dp_a = new_dp_a;
    }
    
    long long ans = max(dp_f, dp_a);
    
    if (ans <= 0) {
        cout << "Insignificant...You were never a threat to my eternity.\n";
    } else {
        cout << "The barrier is down and I still hold " << ans << "HP.Your reign ends this instant.\n";
    }
    
    return 0;
}
