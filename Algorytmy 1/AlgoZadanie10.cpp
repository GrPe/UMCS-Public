#include <iostream>
#include <vector>

using namespace std;

using graph_t = vector<vector<int>>;
int endPoint, packageNumber;

int findPath(graph_t& graph, graph_t& matrix, int vertex, int currentLenght)
{
	int sum = 0;

	if (vertex == endPoint && currentLenght == packageNumber)
	{
		matrix[vertex][currentLenght] = 1;
		return 1;
	}

	if (currentLenght >= packageNumber)
	{
		matrix[vertex][currentLenght] = 0;
		return 0;
	}

	for (auto v : graph[vertex])
	{
		if (matrix[v][currentLenght + 1] != -1)
		{
			sum += matrix[v][currentLenght + 1];
		}
		else
		{
			int tmp = findPath(graph, matrix, v, currentLenght + 1);
			sum += tmp;
		}
	}
	matrix[vertex][currentLenght] = sum;
	return sum;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i != t; i++)
	{
		int n, connections;
		cin >> n >> connections >> endPoint >> packageNumber;

		graph_t graph(n);
		for (int j = 0; j != connections; j++)
		{
			int x, y;
			cin >> x >> y;
			graph[x].emplace_back(y);
		}

		graph_t matrix(n, vector<int>(packageNumber + 1, -1));

		cout << findPath(graph, matrix, 0, 0) << "\n";
	}
	return 0;
}