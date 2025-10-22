#include "Player.h"
#include "Field.h"
static const float Gravity = 0.2;
static const float V0 = -10.0;

Player::Player()
{
	hImage = LoadGraph("data/image/aoi.png");
	x = 200;
	y = 500;
	velocity = 0;
	onGround = false;
}

Player::Player(int sx, int sy)
{
	hImage = LoadGraph("data/image/aoi.png");
	x = sx;
	y = sy;
	velocity = 0;
	onGround = false;
}

Player::~Player()
{
}

void Player::Draw()
{
	Field* field = FindGameObject<Field>();
	int sc = field->GetScollX();
	DrawRectGraph(x - sc, y, 0, 0, 64, 64, hImage, 1);
}
void Player::Update()
{
}
