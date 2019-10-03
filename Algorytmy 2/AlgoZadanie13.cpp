#include <iostream>
#include <random>
#include <string>
#include <cmath>


using namespace std;

int Grazyna(int HH, int mm) {
	if (HH >= 8 && HH < 15) return 0;
	else if (HH >= 15 && HH < 22) return 1;
	return 2;
}


int main()
{
	ios::sync_with_stdio(false);
	int h1, h2, m1, m2, room;

	scanf("%2d:%2d", &h1, &m1);
	scanf("%2d:%2d", &h2, &m2);
	scanf("%d", &room);


	std::default_random_engine generator;

	std::uniform_int_distribution<int> dist(h1*60 + m1, h2*60 + m2);
	
	constexpr int iteration = 800000;

	int rooms[6] = {};

	for (int i = 0; i < iteration; i++)
	{
		int x = dist(generator);
		//cout << x / 60 << " " << x % 60 << endl;
		
		rooms[Grazyna(x/60, x%60)]++;
	}

	printf("%.2f", (double)rooms[room] / (double)iteration);




	return 0;
}
