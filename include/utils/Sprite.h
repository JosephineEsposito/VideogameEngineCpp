#pragma once

#include <string>
#include <sstream>
#include <vector>

#include "libs/tigr.h"
#include "libs/pugixml.hpp"

#include "Vec2.h"


class Sprite
{
public:
#pragma region | Contructor/Destructor
	/**
	 * @brief The default constructor
	 */
	Sprite();

	/**
	 * @brief The constructor of the class
	 * @param file The name of the file to load as sprite
	 */
	Sprite(const std::string& file);

	/**
	 * @brief The default destructor
	 */
	~Sprite();
#pragma endregion


	/**
	 * @brief Renders the texture into the window
	 * @param window A reference to the window
	 */
	void Draw(Tigr* window) const;


	/**
	 * @brief Renders the texture into the window
	 * @param window A reference to the window
	 * @param x The x coordinate
	 * @param y The y coordinate
	 */
	void Draw(Tigr* window, int x, int y) const;



	/**
	 * @brief Updates the texture
	 */
	void Update();

	/**
	 * @brief A pointer to the texture
	 */
	Tigr* texture = nullptr;

	/**
	 * @brief The position of the sprite
	 */
	Vec2 pos = Vec2();

private:
	/**
	 * @brief The name of the file of the sprite
	 */
	std::string fileName;
};
