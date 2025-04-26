#include "Sprite.h"
#include "Vec2.h"

#include "Engine/ENGINE.h"


Sprite::Sprite() {}

Sprite::Sprite(const std::string& file)
{
	fileName = file;
	texture = tigrLoadImage(fileName.c_str());


	if (!texture)
	{
		ENGINE::Log("Sprite", "Constructor", "Failed to load image!");
	}
}

Sprite::~Sprite()
{
	tigrFree(texture);
}



void Sprite::Draw(Tigr* window, int x, int y) const
{
	Vec2 dest = Vec2(x, y);
	Vec2 source = Vec2(0, 0);
	tigrBlitAlpha(window, texture, dest.x, dest.y, source.x, source.y, texture->w, texture->h, 1.0f);
}
void Sprite::Draw(Tigr* window) const
{
	Vec2 dest = Vec2(pos.x, pos.y);
	Vec2 source = Vec2(0, 0);
	tigrBlit(window, texture, dest.x, dest.y, source.x, source.y, texture->w, texture->h);
}

void Sprite::Update()
{
	if (!texture)
	{
		texture = tigrLoadImage(fileName.c_str());
	}
}