#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> valid_pairs;
        
        string str_n = to_string(n);
        
        for (int a = 1; a <= 10000; ++a) {
            string s;
            for (int i = 0; i < a; ++i) {
                s += str_n;
            }
            
            for (int b = 1; b <= min(10000, a * n); ++b) {
                if (b >= s.length()) break;
                
                string modified_s = s.substr(0, s.length() - b);
                long long modified_s_value = modified_s.empty() ? 0 : stoll(modified_s);
                
                if (modified_s_value == (long long)(n * a) - b) {
                    valid_pairs.push_back({a, b});
                }
            }
        }
        
        cout << valid_pairs.size() << endl;
        for (auto &p : valid_pairs) {
            cout << p.first << " " << p.second << endl;
        }
    }
    
    return 0;
}

