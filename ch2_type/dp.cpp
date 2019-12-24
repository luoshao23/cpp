#include <iostream>
int main() {
	int num;
	int f(int n);
	std::cin >> num;
	std::cout << f(num) << std::endl;

	return 0;
}

int f(int n) {
	if (n <= 1) 
		return n;
	int dp[n+1];

	dp[0] = 1;
	dp[1] = 1;

	for (int i=2; i<=n; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}
