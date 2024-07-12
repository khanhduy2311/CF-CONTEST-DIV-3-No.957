#include <iostream>
#include <algorithm>
using namespace std;
void solve()
{
	int a, b, c;
        cin >> a >> b >> c;
        
        int maxBananas = a * b * c;
        
        for (int i = 0; i <= 5; ++i) {
            for (int j = 0; j <= 5 - i; ++j) {
                int k = 5 - i - j;
                int new_a = a + i;
                int new_b = b + j;
                int new_c = c + k;
                maxBananas = max(maxBananas, new_a * new_b * new_c);
            }
        }
        
        cout << maxBananas << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

