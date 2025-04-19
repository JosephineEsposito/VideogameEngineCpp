#include "Sprite.h"
#include "Vec2.h"


Sprite::Sprite() {}

Sprite::Sprite(const std::string& file)
{
	fileName = file;
	texture = tigrLoadImage(fileName.c_str());
}

Sprite::~Sprite()
{
	tigrFree(texture);
}



void Sprite::Draw(Tigr* window, int x, int y) const
{
	Vec2 dest = Vec2(x, y);
	Vec2 source = Vec2(0, 0);
	tigrBlit(window, texture, dest.x, dest.y, source.x, source.y, texture->w, texture->h);
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