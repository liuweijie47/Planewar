#ifndef BOMB2_H
#define BOMB2_H

#include"config.h"
#include <QPixmap>
#include<QVector>
class bomb2
{
public:
    bomb2();
    void updateInfo();
public:
    QVector<QPixmap> m_pixArr;
    int m_x;
    int m_y;
    bool m_free;
    int m_recoder;
    int m_index;
};

#endif // BOMB2_H
