#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	int N, n;
	cin >> N;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%1d", &n);
		sum += n;
	}
	cout << sum << endl;

	return 0;
}