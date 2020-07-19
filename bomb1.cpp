#include "bomb1.h"

bomb1::bomb1()
{
    for(int i=1;i<=BOMB_MAX;i++)
      {  QString str=QString(BOMB_PATHS).arg(i);
              m_pixArr.push_back(QPixmap(str));
      }
    m_x=0;
    m_y=0;
    m_free=true;
    m_index=0;
    m_recoder=0;
}

void bomb1::updateInfo()
{
    if(m_free==true)
        return;
    m_recoder++;
    if(m_recoder<BOMB_INTERVAL)
        return ;
    m_recoder=0;
    m_index++;
    if(m_index>BOMB_MAX-1)
     {
        m_index=0;
        m_free=true;
     }
}
