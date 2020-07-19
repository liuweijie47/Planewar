#include "weplane.h"

weplane::weplane()
{

    we_plane.load("C:/Qt/Qt5.9.0/images/plane0a.png");
    m_y=700;
    m_Rect.setWidth(we_plane.width()*0.75);
    m_x=240-m_Rect.width()*0.5;
    m_Rect.setHeight(we_plane.height()*0.75);
    m_Rect.moveTo(m_x+35,m_y+45);
}

void weplane::updatePosition(int x,int y)
{

        m_x=x;
        m_y=y;
        m_Rect.moveTo(m_x+35,m_y+45);

}
