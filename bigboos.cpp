#include "bigboos.h"

bigboos::bigboos()
{

     m_bigboss.load("C:/Qt/Qt5.9.0/images/enemy3_n2.png");
     m_free=true;
     m_Rect.setWidth(m_bigboss.width());
     m_Rect.setHeight(m_bigboss.height());
     m_Rect.moveTo(240-m_Rect.width()*0.5,0);
}
