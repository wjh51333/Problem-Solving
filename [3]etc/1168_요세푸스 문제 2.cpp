/* etc
 * 1168 요세푸스 문제 2
 * 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(<= N)가 주어진다
 * 이제 순서대로 K번째 사람을 제거한다
 * 한 사람이 제거되면 남은 사람들로 이루어진 월을 따라 이 과정을 계속해 나간다
 * 이 과정은 N명의 사람이 모두 제거될 떄까지 계속된다
 * 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다
 * ex) (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>
 * N과 K가 주어지면 (N, K)-요세푸스 순열 출력
 */

#include <iostream>
using namespace std;

int N, K;
int a, b;
int tree[(1 << 18)];

// 세그먼트 트리 초기화 (루트노드, 시작, 끝)
int init(int node, int start, int end)
{
	// start와 end의 위치가 일치하면 1을 넣어준다
	if (start == end)
		return tree[node] = 1;

	int mid = (start + end) / 2;
	return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

// 세그먼트 트리 정보 수정 (루트노드, 시작, 끝, 제거번호)
int update(int node, int start, int end, int del)
{
	tree[node]--;
	if (start == end)
		return 0;
	else {
		int mid = (start + end) / 2;
		
		if (del <= mid)
			return update(2 * node, start, mid, del);
		else
			return update(2 * node + 1, mid + 1, end, del);
	}
}

// 다음 순서에 해당하는 번호 받아오기 (현재노드, 시작, 끝, 순서)
int query(int node, int start, int end, int order)
{
	// start와 end의 위치가 일치하면 번호를 반환
	if (start == end)
		return start;

	int mid = (start + end) / 2;

	if (order <= tree[2 * node])
		return query(2 * node, start, mid, order);
	else
		return query(2 * node + 1, mid + 1, end, order - tree[2 * node]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	init(1, 1, N);

	int index = 1;

	cout << "<";
	for (int i = 0; i < N; i++) {
		// 다음 순서 구하기
		int size = N - i; // 사람 수
		index += K - 1;

		if (index % size == 0) index = size;
		else if (index > size) index %= size;

		// 다음 순서에 해당하는 번호 받아오기
		int num = query(1, 1, N, index);

		// 해당 번호 제거
		update(1, 1, N, num);

		if (i == N - 1) cout << num;
		else cout << num << ", ";
	}
	cout << ">";

	return 0;
}