#include<iostream>
#include<algorithm>
using namespace std;
void solve()
{
	int n,k;
	cin >> n >> k;
	int a[k+1];
	for (int i=1; i<=k ;i++) cin >> a[i];
	sort(a+1,a+k+1,less<int>());
	int s = 0;
	for (int i=1;i<=k-1;i++) 
	{
		s+=2*a[i]-1;
	}
	cout << s << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--) 
		solve();
	return 0;
}
