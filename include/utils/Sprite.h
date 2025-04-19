#pragma once

#include <string>
#include <sstream>
#include <vector>

#include "libs/tigr.h"
#include "libs/pugixml.hpp"

#include "Vec2.h"


class Sprite
{
private:
	// serialized
	std::string fileName;
	// ----------




public:
	Tigr* texture = nullptr;
	Vec2 pos = Vec2();

#pragma region | Contructor/Destructor
	// Default constructor of class
	Sprite();
	// Receives a filename to load
	Sprite(const std::string& file);
	// Destructor
	~Sprite();
#pragma endregion



#pragma region | Load and Save
	/// Loads data from a xml data (string&) 
	/// @params: the object to load data into, the xml data string to retreive data from
	/// @return: returns the success of the method as bool
	static
		bool Load(Sprite& obj, const std::string& data)
	{
		try
		{
			pugi::xml_document doc;
			pugi::xml_parse_result res = doc.load_string(data.c_str());

			if (res)
			{
				std::string file = doc.child("sprite").attribute("fileName").value(); // loading the filename

				obj = Sprite(file); // we recreate the object

				obj.pos.x = atof(doc.child("sprite").attribute("x").value());
				obj.pos.y = atof(doc.child("sprite").attribute("y").value());

				return true;
			}
			return false;
		}
		catch (...)
		{
			return false;
		}
	}

	// Saves data into memory
	static
		bool Save(std::string& out, const Sprite& obj)
	{
		pugi::xml_document doc;
		pugi::xml_node node = doc.append_child("sprite");
		node.append_attribute("x").set_value(obj.pos.x);
		node.append_attribute("y").set_value(obj.pos.y);
		node.append_attribute("fileName").set_value(obj.fileName.c_str());

		try
		{
			std::stringstream ss;
			doc.save(ss);
			out = ss.str();
			return true;
		}
		catch (...)
		{
			return false;
		}
	}
#pragma endregion



	// Renders the texture into the window
	void Draw(Tigr* window, int x, int y) const;

	// Renders the texture into the window
	void Draw(Tigr* window) const;


	// Updates the texture
	void Update();
};
