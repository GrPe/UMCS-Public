#include <vector>
#include <utility>
#include <functional>

using namespace std;

template <typename T>
vector<T> CopyIfInAnyRange(const vector<T>& values, vector<pair<T, T>>& ranges, function<bool(T,T,T)> checker)
{
	vector<T> vec;
	for (auto x : values)
	{
		auto f = bind(checker, x, placeholders::_1, placeholders::_2); // bo czemu nie :p
		for (auto p : ranges)
		{
			if (f(p.first, p.second))
			{
				vec.push_back(x);
				break;
			}
		}
	}
	return vec;
}

int main()
{
	vector<int> vec{ 1,2,3,4,5 };
	vector<pair<int, int>> ranges{ pair<int,int>(2,4) };
	auto ret = CopyIfInAnyRange<int>(vec, ranges, [](int x, int a, int b)->bool
	{
		if (x >= a && x <= b) return true;
		return false;
	});

	return 0;
}