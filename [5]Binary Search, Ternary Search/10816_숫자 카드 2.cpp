/* Binary Search, Ternary Seacrh
 * 10816 숫자 카드 2
 * 상근이는 숫자 카드 N개를 가지고 있다
 * 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 출력
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 500001
using namespace std;

/*int cards[MAX];

bool binarySearch(int left, int right, int x)
{
	if (left > right)
		return false;
	else {
		int mid = (left + right) / 2;

		if (x == arr[mid])
			return true;
		else if (x > arr[mid])
			return binarySearch(mid + 1, right, x);
		else
			return binarySearch(left, mid - 1, x);
	}
}*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	map<int, int> maps;
	cin >> n;
	vector<int> cards(n);

	for (int i = 0; i < n; i++) {
		cin >> cards[i];
		maps[cards[i]]++;
	}
	sort(cards.begin(), cards.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;

		int left = 0, right = n - 1;
		bool check = false;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (k == cards[mid]) {
				check = true;
				break;
			}
			else if (k > cards[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}

		if (check)
			cout << maps[k] << " ";
		else
			cout << 0 << " ";
	}

	return 0;
}