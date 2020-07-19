#include "wuqi.h"

wuqi::wuqi()
{
    m_wuqi.load("C:/Qt/Qt5.9.0/images/bomb_supply.png");
    m_x=0;
    m_y=0;
     m_free=false;
     m_speed=10;
    m_Rect.setWidth(m_wuqi.width());
    m_Rect.setHeight(m_wuqi.height());
    m_Rect.moveTo(m_x,m_y);
}

void wuqi::updatePosition()
{
    if(m_free==false)
    {
         return;
    }
    m_y+=1;
    m_Rect.moveTo(m_x,m_y);
    if(m_y>=800)
    {
        m_free=false;
    }
}
