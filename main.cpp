#include <iostream>
#include <fstream>
#include <string>

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

	/* Config Skins (DONT CHANGE THIS) */
	string groundConfSkin = "g";
	string playerConfSkin = "Pl";
	/* Config Skins (DONT CHANGE THIS) */

	/* Skins */
	string groundSkin = "..";
	string playerSkin = "Pl";
	/* Skins */

    string path = "config/mapLayerMAIN.txt";
    string confMap[mapY][mapX] = {};

    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
    {
        cout << "Error: Can`t open file" << endl;
    }
    else
    {
        cout << "Success: file open" << endl;

        for (int i = 0; i < mapY; ++i)
        {
            for (int j = 0; j < mapX; j++)
            {
                fin >> confMap[i][j];
            }
        }
    }

    fin.close();

    for (int y = 0; y < mapY; y++)
    {
        for (int x = 0; x < mapX; x++)
        {
            if (confMap[y][x] == groundConfSkin)
            {
                map[y][x] = groundSkin;
            }
            else if (confMap[y][x] == playerConfSkin)
            {
                map[y][x] = playerSkin;
            }
            else 
            {
                cout << "Error: Configeration skin not found";
            }

            cout << map[y][x];
        }
        cout << endl;
    }

	while (true)
	{
		char moveKey;
		cin >> moveKey;
		moveKey = tolower(moveKey);
		if (moveKey == 'a')
		{
			playerX--;
		}
	}

	return 0;
}
