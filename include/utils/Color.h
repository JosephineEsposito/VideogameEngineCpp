/*********************************************************
* A class to handle colors
**********************************************************/
#pragma once

#include "libs/tigr.h"

class Color
{
public:
  /**
   * @brief The default constructor
   */
  Color();

  /**
   * @brief The default destructor
   */
  ~Color();

  /**
   * @brief Sets the color
   * @param _r The hex red value
   * @param _g The hex green value
   * @param _b The hex blue value
   */
  void SetColor(const unsigned char _r, const unsigned char _g, const unsigned char _b);

  /**
   * @brief Returns the color
   * @return A TPixel representing the color
   */
  TPixel GetColor() const;

  /**
   * @brief The TPixel color
   */
  TPixel m_uColor;

private:
  /**
   * @brief The hex red value of the color
   */
  unsigned char m_uRed;

  /**
   * @brief The hex green value of the color
   */
  unsigned char m_uGreen;

  /**
   * @brief The hex blue value of the color
   */
  unsigned char m_uBlue;
};

