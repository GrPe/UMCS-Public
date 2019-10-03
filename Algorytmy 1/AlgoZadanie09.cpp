#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define RALL(container) rbegin(container), rend(container)
#define ALL(container) begin(container), end(container)

using namespace std;

auto main() -> int
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i != t; i++)
	{
		//read data
		int n, d, c;
		cin >> n >> c >> d;
		vector<int> time1(n);
		vector<int> time2(n);

		int cost = 0;

		for (auto j = 0; j != n; j++)
		{
			cin >> time1[j] >> time2[j];
			cost += (c + d * (time2[j] - time1[j]));
		}

		//sort table
		sort(ALL(time1));
		sort(RALL(time2));

		//Nie wiem dlaczego; to nie powinno sie zdarzyc;
		int acceptableCost;
		if (d != 0)
		{
			acceptableCost = c / d;
		}
		else acceptableCost = INT_MAX;

		//reduce cost
		auto iter{ time2.begin() };

		while (iter != time2.end())
		{
			auto start = lower_bound(ALL(time1), *iter + 1);
			if (start != time1.end())
			{
				auto diff = *start - *iter;
				if (diff <= acceptableCost && (c - d * diff) > 0)
				{
					cost -= (c - d * diff);
					time1.erase(start);
				}
			}
			iter++;
		}

		cout << cost << "\n";
	}

	return 0;
}