#pragma once

class Vec2
{
public:
#pragma region | Constructor
	/**
	 * @brief The default constructor
	 */
	Vec2();

	/**
	 * @brief The constructor of the vector
	 * @param _x The x value of the vector
	 * @param _y The y value of the vector
	 */
	Vec2(float _x, float _y);
#pragma endregion


#pragma region | Operators
	
	
	/**
	 * @brief Returns the sum between self and vector
	 * @param other The vector to sum to
	 * @return The sum of self and vector
	 */
	Vec2 operator+(const Vec2& other);
	
	/**
	 * @brief Returns the sum between self and float
	 * @param other The float to sum to
	 * @return The sum of self and float
	 */
	Vec2 operator+(const float& other);

	
	/**
	 * @brief Returns the rest between self and vector
	 * @param other The vector to rest to
	 * @return The difference between self and vector
	 */
	Vec2 operator-(const Vec2& other);
	
	/**
	 * @brief Returns the rest between self and float
	 * @param other The float to rest to
	 * @return The difference between self and float
	 */
	Vec2 operator-(const float& other);

	
	/**
	 * @brief Multiplies self with a float
	 * @param other The float to multiply
	 * @return The result of the multiplication
	 */
	Vec2 operator*(const float& other);

	
	/**
	 * @brief The dot product between two vectors
	 * @param other The other vector of the dot product
	 * @return The result of the dot product
	 */
	float dot(const Vec2& other);

	
	/**
	 * @brief The division between self and a float
	 * @param other The float to divide to
	 * @return The result of the division
	 */
	Vec2 operator/(const float& other);
#pragma endregion


	
	/**
	 * @brief Returns the absolute value of self
	 * @return A float representing the absolute value
	 */
	float absolute();
	

	/**
	 * @brief Returns the lenght of the vector
	 * @return A float representing the lenght of the vector
	 */
	float longitud();

	
	/**
	 * @brief Returns the normalized vector
	 * @return The normalized vector
	 */
	Vec2 normal();

	
	/**
	 * @brief Returns the angle between self and another vector
	 * @param other The other vector
	 * @return A float representing the angle between the vectors
	 */
	float angle(const Vec2& other) const;

	
	/**
	 * @brief Returns the distance between self and another vector
	 * @param other The other vector
	 * @return A float representing the distance
	 */
	float distance(const Vec2& other) const;

	
	/**
	 * @brief Rotates self given the angle and the origin of the rotation
	 * @param angle The angle of rotation
	 * @param fixedLen The origin
	 */
	void rotate(const float& angle, const float& fixedLen);

	/**
	 * @brief Rotates self given an angle
	 * @param angle The angle of rotation
	 */
	void rot2(const float& angle);


#pragma region | Variables
	/**
	 * @brief The x value of the  vector
	 */
	float x;

	/**
	 * @brief The y value of the vector
	 */
	float y;

	/**
	 * @brief The alpha angle of the vector
	 */
	float alpha;
#pragma endregion
};


