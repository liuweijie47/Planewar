#ifndef BOMB1_H
#define BOMB1_H
#include"config.h"
#include <QPixmap>
#include<QVector>

class bomb1
{
public:
    bomb1();
    void updateInfo();
public:
    QVector<QPixmap> m_pixArr;
    int m_x;
    int m_y;
    bool m_free;
    int m_recoder;
    int m_index;
};

#endif // BOMB1_H
