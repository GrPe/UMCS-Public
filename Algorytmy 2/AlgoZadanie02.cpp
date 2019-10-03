#include <iostream>
#include <cstdint>
#include <vector>
#include <limits>
#include <queue>
#include <utility>
#include <iomanip>
#include <functional>
#include <cstdlib>

using namespace std;

using graph_t = vector<vector<pair<int, double>>>;

vector<double> Ford(graph_t& graph)
{
	//table of distances
	vector<double> distances(graph.size(), numeric_limits<float>::max());
	distances[0] = 0; //log(n) + O(1)

	//V-1
	for (int j = 0; j < graph.size() - 1; j++)
	{
		bool changed = false;

		for(int vertex = 0; vertex < graph.size(); vertex++)
		{
			for (auto v : graph[vertex])
			{
				if (distances[v.first] > distances[vertex] + v.second)
				{
					distances[v.first] = distances[vertex] + v.second;
					changed = true;
				}
			}
		}
		if (changed == false) return distances;
	}

	//V
	for (int vertex = 0; vertex < graph.size(); vertex++)
	{
		for (auto v : graph[vertex])
		{
			if (distances[v.first] > distances[vertex] + v.second)
			{
				cout << "DO DOMU!\n";
				exit(0);
			}
		}
	}

	return distances;
}

auto main() -> int
{
	ios::sync_with_stdio(false);

	uint32_t transitions, vertexs;
	cin >> vertexs >> transitions;
	graph_t graph(vertexs);
	graph_t reverseGraph(vertexs);


	int a, b, t0, t1, p0, p1;
	double l0, l1;
	for (auto i = 0; i < transitions; i++)
	{
		cin >> a >> b >> l0 >> t0 >> p0 >> l1 >> t1 >> p1;
		graph[a].push_back({ b, l0 * 0.49 + t0 * 0.18 - p0 });
		graph[b].push_back({ a, l1 * 0.49 + t1 * 0.18 - p1 });
		reverseGraph[b].push_back({ a, l0 * 0.49 + t0 * 0.18 - p0 });
		reverseGraph[a].push_back({ b, l1 * 0.49 + t1 * 0.18 - p1 });
	}

	uint32_t s;
	cin >> s;
	vector<uint32_t> shops(s);

	for (auto i = 0; i < s; i++)
		cin >> shops[i];

	//Dikstra #0
	auto distances = Ford(graph);

	double sum = 0;

	for (auto i : shops)
		sum += distances[i];

	//Dikstra #1

	distances = Ford(reverseGraph);

	for (auto i : shops)
		sum += distances[i];

	cout << fixed << showpoint;
	cout << setprecision(3) << sum / static_cast<double>(s) << "\n";

	return 0;
}