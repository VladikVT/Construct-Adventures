#include <iostream>
#include <fstream>
#include <string>

#include "ConAdvLib.h"
#include "Player.h"

using namespace std;

void errorMSG(string path, int errCode);
void successMSG(string path, int scsCode);
ifstream openFile(string path);

int main()
{
    CurHide;
         
    int dataElements = 11;
    string dataArray[dataElements] = {};

    string pathToConfig = "config/config.txt";

    ifstream config = openFile(pathToConfig);

    for (int i = 0; i < dataElements; i++)
    {
        string line;

        getline(config, line, ':');

        config >> dataArray[i];

        config >> ws;

        if (!config) break;
    }
    
    config.close();

	/* Map */
	int mapX = stoi(dataArray[3]);
	int mapY = stoi(dataArray[4]);

    string mapSHADOW[mapY][mapX] = {};
	string mapMAIN[mapY][mapX] = {};
	string mapSOLID[mapY][mapX] = {};

    string map[mapY][mapX] = {};
    /* Map */

	/* Player */
    Player player;

	int playerX = 2;
	int playerY = 3;
	
    player.setPos(playerX, playerY);
    
    player.getInfo();
    /* Player */

	/* Config Skins (DONT CHANGE THIS) */
	string nothingConfSkin = "nf";
    string solidConfSkin = "sld"; 
    
    string groundConfSkin = "g";
	string playerConfSkin = "Pl";
    string wallConfSkin = "wl";
    string buttonConfSkin = "btn"; 

    string CSkinsArray[] = {nothingConfSkin, solidConfSkin, groundConfSkin, playerConfSkin, wallConfSkin, buttonConfSkin};
	/* Config Skins (DONT CHANGE THIS) */

	/* Skins */
    string nothingSkin = dataArray[5];
    string solidSkin = dataArray[6];

	string groundSkin = dataArray[7];
	string playerSkin = dataArray[8];
    string wallSkin = dataArray[9];
    string buttonSkin = dataArray[10];
	string SkinsArray[] = {nothingSkin, solidSkin, groundSkin, playerSkin, wallSkin, buttonSkin};
	/* Skins */
    
    string pathToMapSHADOW = dataArray[0];
    string pathToMapMAIN = dataArray[1];
    string pathToMapSOLID = dataArray[2];
    
    string confMapSHADOW[mapY][mapX] = {};
    string confMapMAIN[mapY][mapX] = {};
    string confMapSOLID[mapY][mapX] = {};

    ifstream fmapSHDW = openFile(pathToMapSHADOW);
    ifstream fmapMAIN = openFile(pathToMapMAIN);
    ifstream fmapSLD = openFile(pathToMapSOLID);

    for (int i = 0; i < mapY; ++i)
    {
        for (int j = 0; j < mapX; j++)
        {
            fmapSHDW >> confMapSHADOW[i][j];
            fmapMAIN >> confMapMAIN[i][j];
            fmapSLD >> confMapSOLID[i][j];
        }
    }
    

    fmapSHDW.close();
    fmapMAIN.close();
    fmapSLD.close();

    for (int y = 0; y < mapY; y++)
    {
        for (int x = 0; x < mapX; x++)
        {
            for (int i = 0; i < 6; i++)
            {
                if (confMapSHADOW[y][x] == CSkinsArray[i])
                {
                    mapSHADOW[y][x] = SkinsArray[i];
                } 
                if (confMapMAIN[y][x] == CSkinsArray[i])
                {
                    mapMAIN[y][x] = SkinsArray[i];
                }
                if (confMapSOLID[y][x] == CSkinsArray[i])
                {
                    mapSOLID[y][x] = SkinsArray[i];
                }
            }
            if (mapMAIN[y][x] == "nf")
            {
                map[y][x] = mapSHADOW[y][x];
            }
            else
            {
                map[y][x] = mapMAIN[y][x];
            }

            cout << map[y][x];
        }
        cout << endl;
    }
    
    CurShow;

	while (true)
	{
		string moveKey;
		cin >> moveKey;
        player.move(moveKey);
        player.getInfo();
	}

	return 0;
}

void errorMSG(string path, int errCode)
{
    if (errCode == 1)
    {
        cout << "Error: can`t open file - " << path << endl;
    }
}

void successMSG(string path, int scsCode)
{
    if (scsCode == 1)
    {
        cout << "Success: file - " << path << " open" << endl;
    }
}

ifstream openFile(string path)
{
    ifstream file;

    file.open(path);

    if (!file.is_open())
    {
        errorMSG(path, 1);
    }
    else
    {
        successMSG(path, 1);
    }

    return file;
}
