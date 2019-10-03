#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define ALL(container) begin(container), end(container)

using namespace std;

int k;
int lampCounter = 0;

inline int GetLeftLeaf(int root) noexcept
{
	return root * 2 + 1;
}

inline int GetRightLeaf(int root) noexcept
{
	return root * 2 + 2;
}

vector<int> HangTheLamps(vector<int>& tree, int node)
{
	vector<int> left, right;
	int l = GetLeftLeaf(node);
	int r = GetRightLeaf(node);

	if (l < tree.size())
	{
		left = HangTheLamps(tree, l);
	}
	if (r < tree.size())
	{
		right = HangTheLamps(tree, r);
	}
	if (r >= tree.size() && l >= tree.size())
	{
		if (tree[node] == k)
		{
			lampCounter++;
			return vector<int>();
		}
		vector<int> s;
		s.emplace_back(tree[node]);
		return s;
	}

	//concatenate results
	vector<int> concat;
	for (auto x : left)
	{
		concat.emplace_back(x + tree[node]);
	}

	for (auto x : right)
	{
		concat.emplace_back(x + tree[node]);
	}
	
	for (auto x : left)
	{
		for (auto y : right)
		{
			if (x + y == k) lampCounter++;
		}
	}

	concat.emplace_back(tree[node]);

	sort(ALL(concat));

	vector<int> ret;
	for (auto x : concat)
	{
		if (x == k) lampCounter++;
		if (x > k) break;
		if( x < k ) ret.emplace_back(x);
	}
	return ret;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i != t; i++)
	{
		int n;
		cin >> n >> k;
		++n;
		vector<int> tree(n);
		lampCounter = 0;

		tree[0] = 0;

		for (int j = 1; j != n; j++)
		{
			cin >> tree[j];
		}

		HangTheLamps(tree, 0);

		cout << lampCounter << "\n";

	}

	return 0;
}