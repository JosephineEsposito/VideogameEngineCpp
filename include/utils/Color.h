/*********************************************************
* The color component
**********************************************************/
#pragma once

#include "libs/tigr.h"

class Color
{
public:
  Color();
  ~Color();

  void setColor(unsigned char _r, unsigned char _g, unsigned char _b);

  TPixel getColor() const;

  TPixel m_uColor;

private:
  unsigned char m_uRed;

  unsigned char m_uGreen;

  unsigned char m_uBlue;
};

