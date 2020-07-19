#ifndef WEPLANE_H
#define WEPLANE_H
#include<QPixmap>
#include<bullet.h>
#include<QRect>
class weplane
{
public:
    weplane();
    void updatePosition(int x,int y);
   public:
    QPixmap we_plane;
    bullet m_bullet[20];
    bullet m_bullet1[20];
    int m_x;
    int m_y;
    QRect m_Rect;

};

#endif // WEPLANE_H
