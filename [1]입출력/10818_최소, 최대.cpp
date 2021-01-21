#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> num(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	auto ans = minmax_element(num.begin(), num.end());
	cout << *ans.first << " " << *ans.second << endl;

	return 0;
}