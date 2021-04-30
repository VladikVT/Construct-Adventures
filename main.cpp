#include <iostream>

using namespace std;

int main()
{
	/* Map */
	int mapX = 5;
	int mapY = 5;

	string map[mapY][mapX] = {};
	/* Map */

	/* Player */
	int playerX = 2;
	int playerY = 2;
	/* Player */

	/* Skins */
	string groundSkin = "..";
	string playerSkin = "Pl";
	/* Skins */

	for (int y = 0; y < mapY; y++)
	{
		for (int x = 0; x < mapX; x++)
		{
			map[y][x] = groundSkin;
		}
	}

	map[playerY][playerX] = playerSkin;

	for (int y = 0; y < mapY; y++)
	{
		for (int x = 0; x < mapX; x++)
		{
			cout << map[y][x];
		}
		cout << "\n";
	}
	return 0;
}
