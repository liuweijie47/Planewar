#include "bullet.h"

bullet::bullet()
{
    m_bullet1.load("C:/Qt/Qt5.9.0/images/assisent1_2.png");
    m_bullet2.load("C:/Qt/Qt5.9.0/images/assisent1_4.png");
    m_x=0;
    m_y=0;
    m_free=true;
    m_speed=20;
    m_Rect.setWidth(m_bullet1.width());
    m_Rect.setHeight(m_bullet1.height());
    m_Rect.moveTo(m_x,m_y);
}

void bullet::weupdatePosition()
{
    if(m_free)
    {
         return;
    }

    m_y-=6;

    m_Rect.moveTo(m_x,m_y);
    if(m_y<=0)
    {
        m_free=true;
    }
}

void bullet::bossupdatePosition2()
{
    if(m_free)
        return;
    m_x-=2;
    m_y+=6;
    m_Rect.moveTo(m_x,m_y);
    if(m_y>=800)
    {
        m_free=true;
    }
    if(m_x<=0)
    {
        m_free=true;
    }
}

void bullet::bossupdatePosition1()
{
    if(m_free)
        return;
    m_x+=2;
    m_y+=6;
    m_Rect.moveTo(m_x,m_y);
    if(m_y>=800)
    {
        m_free=true;
    }
    if(m_x>=480)
    {
        m_free=true;
    }
}
void bullet::updatePosition()
{
    if(m_free)
    {
         return;
    }

    m_y+=6;

    m_Rect.moveTo(m_x,m_y);
    if(m_y>=800)
    {
        m_free=true;
    }
}
