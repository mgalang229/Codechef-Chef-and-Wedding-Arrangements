#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> f(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> f[i];
		}
		vector<int> dp(n + 1);
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1] + k; // separate table for the i-th person
			map<int, int> mp;
			int arguments = 0;
			// try out all possible groupings that include the i-th person as the last person on the table
			for (int j = i; j >= 1; j--) {
				mp[f[j]]++;
				if (mp[f[j]] == 2) {
					arguments += 2;
				} else if (mp[f[j]] > 2) {
					arguments += 1;
				}
				// update dp[i] if a lower inefficiency value is calculated
				dp[i] = min(dp[i], dp[j - 1] + k + arguments);
			}
		}
		cout << dp[n] << '\n';
	}
	return 0;
}
