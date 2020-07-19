#ifndef EMEYPLANE_H
#define EMEYPLANE_H
#include<QPixmap>
#include<QRect>
#include"bullet.h"
class emeyplane
{
public:
    emeyplane();
    void updatePosition();
   public:
    QPixmap m_enemy;
    QPixmap m_enemy1;
    bullet m_bullet[20];
    int m_x;
    int m_y;
    QRect m_Rect;
    bool m_free;
    int m_speed;

};

#endif // EMEYPLANE_H
