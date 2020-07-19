#ifndef BOMB_H
#define BOMB_H
#include"config.h"
#include <QPixmap>
#include<QVector>

class Bomb
{
public:
    Bomb();
    void updateInfo();
public:
    QVector<QPixmap> m_pixArr;
    int m_x;
    int m_y;
    bool m_free;
    int m_recoder;
    int m_index;
};

#endif // BOMB_H
