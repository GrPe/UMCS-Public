#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

struct Vertex
{
	int color;
	vector<int> neigbor;
};

struct Connection
{
	int from;
	int to;
	int cost;

	Connection(int from, int to, int cost) : from(from), to(to), cost(cost)
	{}
};

int main()
{
	ios::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;

	vector<int> toVisit(v);

	for (int i = 0; i < v; i++)
		cin >> toVisit[i];

	int a, b, c;

	//create set of connections
	vector<Connection> graph; 

	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		if (toVisit[a] == 1 && toVisit[b] == 1)
		{
			graph.push_back(Connection{ a, b, c });
		}
	}

	sort(graph.begin(), graph.end(), [](const Connection& con1, const Connection& con2) -> bool {return con1.cost < con2.cost; });

	//create forest
	vector<Vertex> forest(v);
	for (int i = 0; i < v; i++) { forest[i].color = i; }


	//create trees
	int result = 0;
	for (auto x : graph)
	{
		//if they have different colors
		if (forest[x.from].color != forest[x.to].color)
		{
			//add cost
			result += x.cost;

			//connect it
			forest[x.from].neigbor.push_back(x.to);
			forest[x.to].neigbor.push_back(x.from);

			//repaint trees
			forest[x.to].color = forest[x.from].color;

			queue<int> vertexs;
			vertexs.push(x.to);
			while (!vertexs.empty())
			{
				int vertex = vertexs.front();
				vertexs.pop();

				for (auto y : forest[vertex].neigbor)
				{
					if (forest[y].color != forest[x.from].color)
					{
						forest[y].color = forest[x.from].color;
						vertexs.push(y);
					}
				}
			}
		}
	}

	cout << result << endl;


	return 0;
}