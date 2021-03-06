﻿#include "emeyplane.h"

emeyplane::emeyplane()
{
    m_enemy.load("C:/Qt/Qt5.9.0/images/enemy2.png");
    m_enemy1.load("C:/Qt/Qt5.9.0/images/enemy1_down1.png");
    m_x=0;
    m_y=0;
    m_free=true;
    m_speed=20;

    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_x,m_y);
}

void emeyplane::updatePosition()
{
    if(m_free)
    {
         return;
    }
    m_y+=3;
    m_Rect.moveTo(m_x,m_y);
    if(m_y>=800)
    {
        m_free=true;
    }
}

