#include <iostream>
#include <algorithm>

using namespace std;

int n;
int GetDish(int* products, int number, int toFind, int accSum)
{
	if (n <= number) return 0;

	//get dish without adding this product
	int ret = GetDish(products, number + 1, toFind, accSum);

	//get dish with adding this product
	accSum += products[number];
	if (accSum > toFind) return ret;
	if (accSum == toFind) return ret + 1;

	ret +=  GetDish(products, number + 1, toFind, accSum);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i != t; i++)
	{
		cin >> n;
		int* products = new int[n];
		for (int j = 0; j != n; j++)
		{
			cin >> products[j];
		}
		int k;
		cin >> k;

		sort(products, products + n, [](int a, int b)->bool {return a > b; });

		cout << GetDish(products, 0, k, 0) << "\n";

		delete[] products;
	}

	return 0;
}