#include "Field.h"
#include <vector>
#include "Player.h"

using namespace std;

vector<vector<int>> maps = {
	{1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,9,0,0 },
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1 },
	{0,2,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1 },
	{1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1 },
	{1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1 },
};

Field::Field()
{
	hImage = LoadGraph("data/image/bgchar.png");
	x = 0;
	y = 600;
	scrollX = 0;
	for (int y = 0; y < maps.size(); y++) {
		for (int x = 0; x < maps[y].size(); x++) {
			if (maps[y][x] == 2) {
				new Player(x * 64, y * 64 + 400);
			}
		}
	}
}

Field::~Field()
{
}

void Field::Update()
{
	scrollX += 5; //‹­§ƒXƒNƒ[ƒ‹‚Ìê‡
}

void Field::Draw()
{
	for (int y = 0; y < maps.size(); y++) {
		for (int x = 0; x < maps[y].size(); x++) {
			if (maps[y][x] == 1) {
				DrawRectGraph(x * 64 - scrollX, y * 64 + 400, 0, 32, 64, 64, hImage, 1);
			}
		}
	}
}
