#include <iostream>
#include <fstream>
#include <string>

#include "ConAdvLib.h"

using namespace std;

void errorMSG(string path);
void successMSG(string path);

int main()
{
//    CurHide;
    
    int dataElements = 5;
    string dataArray[dataElements] = {};

    string pathToConfig = "config/config.txt";

    ifstream config;

    config.open(pathToConfig);

    if (!config.is_open())
    {
        errorMSG(pathToConfig);

        return 1;
    }
    else
    {
        successMSG(pathToConfig);
    }

    for (int i = 0; i < dataElements; i++)
    {
        string line;

        getline(config, line, ':');

        config >> dataArray[i];

        config >> ws;

        if (!config) break;
    }

	/* Map */
	int mapX = stoi(dataArray[1]);
	int mapY = stoi(dataArray[2]);

	string map[mapY][mapX] = {};
	/* Map */

	/* Player */
	int playerX;
	int playerY;
	/* Player */

	/* Config Skins (DONT CHANGE THIS) */
	string groundConfSkin = "g";
	string playerConfSkin = "Pl";
	/* Config Skins (DONT CHANGE THIS) */

	/* Skins */
	string groundSkin = dataArray[3];
	string playerSkin = dataArray[4];
	/* Skins */

    string pathToConfMap = dataArray[0];
    string confMap[mapY][mapX] = {};

    ifstream fin;
    fin.open(pathToConfMap);

    if (!fin.is_open())
    {
        errorMSG(pathToConfMap);

        return 1;
    }
    else
    {
        successMSG(pathToConfMap);

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
                playerY = y;
                playerX = x;
            }
            else 
            {
                cout << "Error: Configuration skin not found";
                
                return 1;
            }

            cout << map[y][x];
        }
        cout << endl;
    }
    
    CurShow;

	while (true)
	{
		char moveKey;
		cin >> moveKey;
		moveKey = tolower(moveKey);
	}

	return 0;
}

void errorMSG(string path)
{
    cout << "Error: can`t open file - " << path << endl;
}

void successMSG(string path)
{
    cout << "Success: file - " << path << " open" << endl;
}
