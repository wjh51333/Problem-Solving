#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = N; i > 0; i--) {
		for (int j = N; j > i; j--)
			cout << " ";

		for (int j = 1; j <= 2 * i - 1; j++)
			cout << "*";

		cout << "\n";
	}

	for (int i = 2; i <= N; i++) {
		for (int j = i; j < N; j++)
			cout << " ";

		for (int j = 1; j <= 2 * i - 1; j++)
			cout << "*";

		cout << "\n";
	}

	return 0;
}