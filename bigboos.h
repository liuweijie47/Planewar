#ifndef BIGBOOS_H
#define BIGBOOS_H
#include<QPixmap>
#include<QRect>
#include"bullet.h"

class bigboos
{
public:
    bigboos();
    void updatePosition();
   public:
    QPixmap m_bigboss;
    bullet m_bullet[20];
    bullet m_bullet1[20];
    bullet m_bullet2[20];
    QRect m_Rect;
    bool m_free;
    int life=100;
};

#endif // BIGBOOS_H
