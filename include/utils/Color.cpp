#include "Color.h"


Color::Color()
{
  m_uRed = 0x00;
  m_uGreen = 0x00;
  m_uBlue = 0x00;

  m_uColor = tigrRGB(m_uRed, m_uGreen, m_uBlue);
}

Color::~Color()
{
  m_uRed = 0x00;
  m_uGreen = 0x00;
  m_uBlue = 0x00;

  m_uColor = tigrRGB(m_uRed, m_uGreen, m_uBlue);
}

void Color::SetColor(unsigned char _r, unsigned char _g, unsigned char _b)
{
  m_uRed = _r;
  m_uGreen = _g;
  m_uBlue = _b;

  m_uColor = tigrRGB(m_uRed, m_uGreen, m_uBlue);
}

TPixel Color::GetColor() const
{
  return m_uColor;
}