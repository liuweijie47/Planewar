#ifndef WUQI_H
#define WUQI_H
#include<QPixmap>
#include<QRect>

class wuqi
{
public:
    wuqi();
   void updatePosition();
   public:
    QPixmap m_wuqi;
    int m_x;
    int m_y;
    QRect m_Rect;
    bool m_free;
    int m_speed;
};

#endif // WUQI_H
