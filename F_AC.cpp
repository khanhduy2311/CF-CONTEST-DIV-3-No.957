#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define           f     first
#define           s     second
#define           pb    push_back
#define           ep    emplace
#define           eb    emplace_back
#define           lb    lower_bound
#define           ub    upper_bound
#define       all(x)    x.begin(), x.end()
#define      rall(x)    x.rbegin(), x.rend()
#define   uniquev(v)    sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define     mem(f,x)    memset(f , x , sizeof(f))
#define        sz(x)    (ll)(x).size()
#define  __lcm(a, b)    (1ll * ((a) / __gcd((a), (b))) * (b))
#define          mxx    *max_element
#define          mnn    *min_element
#define    cntbit(x)    __builtin_popcountll(x)
#define       len(x)    (int)(x.length())

const int N = 2e5 + 10;
int f[N], id[N], a[N];
ll dp[170], mod = 1e16 + 7;
vector <int> save;
int ss;

void add(int x) {
    if (x == 1)
        return;

    for (int i = ss; i >= 0; i--) {
        if (save[i] % x == 0) {
            dp[i] = (dp[id[save[i] / x]] + dp[i]) % mod;
        }
    }
}

void del(int x) {
    if (x == 1)
        return;

    for (int i = 0; i <= ss; i++) {
        if (save[i] % x == 0) {
            dp[i] = (dp[i] - dp[id[save[i] / x]] + mod) % mod; 
        }
    }
}

int solve() {
    save.clear();
    mem(dp, 0);
    dp[0] = 1;

    int n, x;
    cin >> n >> x;

    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            save.pb(i);
            if (i * i != x)
                save.pb(x / i);
        }
    }

    sort(all(save));
    ss = sz(save) - 1;

    for (int i = 0; i <= ss; i++) {
        id[save[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }


    int j = 1;

    deque <int> dq;
    dq.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (x % a[i] == 0)
            add(a[i]);

        while (dp[ss]) {
            if (x % a[j] == 0)
                del(a[j]);
            j++;
        }

        while (sz(dq) && dq.front() < j - 1)
            dq.pop_front();

        f[i] = f[dq.front()] + 1;
        while (sz(dq) && f[i] < f[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }


    return f[n];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--) {
        cout << solve() << '\n';
    }

    return 0;
}
//khanhduy2311

