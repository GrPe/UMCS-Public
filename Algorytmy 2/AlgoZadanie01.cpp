#include <iostream>
#include <cstdint>
#include <vector>
#include <limits>
#include <queue>
#include <utility>
#include <iomanip>
#include <functional>

using namespace std;

using graph_t = vector<vector<pair<bool, double>>>;

vector<double> Dikstra(graph_t& graph)
{
	//table of distances
	vector<double> distances(graph.size(), numeric_limits<float>::max());
	vector<bool> visited(graph.size(), false);

	//priority queue + comparator
	function < bool(const pair<int, double>&, pair<int, double>&)> comp = [](const pair<int, double>& a, pair<int, double>& b) -> bool {return a.second > b.second; };
	priority_queue < pair<int, double>, vector<pair<int, double>>, decltype(comp)> toVisit(comp);

	toVisit.push({ 0,0 }); //log(n) + O(1)
	distances[0] = 0; //log(n) + O(1)

	int visitedElements = 0;

	while (!toVisit.empty())
	{
		int vertex = toVisit.top().first;
		toVisit.pop();
		if (visited[vertex]) continue;
		visited[vertex] = true;

		for (size_t  i = 0; i< graph[vertex].size(); i++)
		{
			if (graph[vertex][i].first)
			{
				if (distances[i] > distances[vertex] + graph[vertex][i].second)
				{
					distances[i] = distances[vertex] + graph[vertex][i].second;
					toVisit.push(pair<int,double>(i,distances[i]));
				}
			}
		}
	}

	return distances;
}

//to samo co wyzej copy-paste
vector<double> ReverseDikstra(graph_t& graph)
{
	//table of distances
	vector<double> distances(graph.size(), numeric_limits<float>::max());
	vector<bool> visited(graph.size(), false);

	//priority queue + comparator
	function < bool(const pair<int, double>&, pair<int, double>&)> comp = [](const pair<int, double>& a, pair<int, double>& b) -> bool {return a.second > b.second; };
	priority_queue < pair<int, double>, vector<pair<int, double>>, decltype(comp)> toVisit(comp);

	toVisit.push({ 0,0 });
	distances[0] = 0;

	int visitedElements = 0;

	while (!toVisit.empty())
	{
		int vertex = toVisit.top().first;
		toVisit.pop();
		if (visited[vertex]) continue;
		visited[vertex] = true;

		for (size_t i = 0; i < graph[vertex].size(); i++)
		{
			if (graph[vertex][i].first)
			{
				if (distances[i] > distances[vertex] + graph[i][vertex].second) // zamiast [vertex][i]
				{
					distances[i] = distances[vertex] + graph[i][vertex].second;
					toVisit.push(pair<int, double>(i, distances[i]));
				}
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
	graph_t graph(vertexs, vector<pair<bool, double>>(vertexs, { false, numeric_limits<double>::max() }));


	int a, b, t0, t1;
	double l0, l1;
	for (auto i = 0; i < transitions; i++)
	{
		cin >> a >> b >> l0 >> t0 >> l1 >> t1;
		graph[a][b] = { true, l0 * 0.49 + t0 * 0.18 };
		graph[b][a] = { true, l1 * 0.49 + t1 * 0.18 };
	}

	uint32_t s;
	cin >> s;
	vector<uint32_t> shops(s);

	for (auto i = 0; i < s; i++)
		cin >> shops[i];


	//Dikstra #0
	auto distances = Dikstra(graph);

	double sum = 0;

	for (auto i : shops)
		sum += distances[i];

	//Dikstra #1

	distances = ReverseDikstra(graph);

	for (auto i : shops)
		sum += distances[i];

	cout << fixed << showpoint;
	cout << setprecision(3) << sum / static_cast<double>(s) << "\n";

	return 0;
}