#ifndef BULLET_H
#define BULLET_H
#include<QPixmap>
#include<QRect>
class bullet
{
public:
    bullet();
    void updatePosition();
    void weupdatePosition();
    void bossupdatePosition1();
    void bossupdatePosition2();
public:
    QPixmap m_bullet1;
    QPixmap m_bullet2;
    int m_x;
    int m_y;
    QRect m_Rect;
    bool m_free;
    int m_speed;
};

#endif // BULLET_H
