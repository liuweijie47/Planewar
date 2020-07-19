#include "widget.h"
#include "ui_widget.h"
#include"config.h"
#include <QIcon>
#include<QPainter>
#include<QPixmap>
#include<QTime>
#include<QSound>
#include<QDebug>
#include<QLabel>
#include <QKeyEvent>
#include<QMouseEvent>
#include<conio.h>
#include<iostream>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    time=0;
    score=0;
    m_recorder=0;
    recorder=0;
    werecorder=0;
    over=false;
    life=100;
    big=0;
    bosslife=100;
    t=0;
    initScene();
    //for(int i=0;;i++)
      //f(t==1)
     //playGame();

}

Widget::~Widget()
{
    delete ui;
}
void Widget::initScene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);//设置窗口标题
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon("C:/Qt/Qt5.9.0/res/Cmm5.ico"));//加头文件
    m_Timer.setInterval(GAME_RATE);
    label_logo->setGeometry(20,50,450,100);
    label_logo->setPixmap(QPixmap("C:/Qt/Qt5.9.0/images/fei.png"));
    ToolButton_start->setGeometry(145,200,190,190);
    ToolButton_start->setAutoRaise(true);
     ToolButton_start->setIcon(QIcon("C:/Qt/Qt5.9.0/images/start.png"));
     ToolButton_start->setIconSize(QSize(190,190));
     //QMouseEvent *event;
    // mousePressEvent(event);
}
void Widget::enemyToScene()
{
    m_recorder++;
    if(time<50)
    if(m_recorder<100-time)
    {
        return;
    }
    if(m_recorder<50)
    {
        return;
    }
    m_recorder=0;
    if(score<50)
    for(int i=0;i<20;i++)
        if(m_enemys[i].m_free)
        {
            m_enemys[i].m_free=false;
            time++;

            m_enemys[i].m_x=rand()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_enemys[i].m_y=0;

            break;
        }
    if(d==0)
   { m_weapons.m_x=rand()%(GAME_WIDTH-m_weapons.m_Rect.width());
    m_weapons.m_y=0;
    d=1;
   }


}

int Widget::boom1()
{
    for(int i=0;i<20;i++)
        if(m_enemys[i].m_free==false)
        for(int j=0;j<20;j++)
        if(we_plane.m_bullet[j].m_free==false)
            if(m_enemys[i].m_Rect.intersects(we_plane.m_bullet[j].m_Rect))
            {   score++;
                m_enemys[i].m_free=true;
                  we_plane.m_bullet[j].m_free=true;
                  for(int k=0;k<BOMB_NUM;k++)
                  {
                      if(m_bombs[k].m_free)
                      {
                          QSound::play(SOUND_BOMB);
                          m_bombs[k].m_free=false;
                          m_bombs[k].m_x=m_enemys[i].m_x;
                          m_bombs[k].m_y=m_enemys[i].m_y;
                          break;
                      }
                  }
            }
}

int Widget::boom3()
{
    for(int i=0;i<20;i++)
        if(m_enemys[i].m_free==false)
            if(m_enemys[i].m_Rect.intersects(we_plane.m_Rect))
            {    m_enemys[i].m_free=true;
                life-=2;
                  for(int k=0;k<BOMB_NUM;k++)
                  {
                      if(m_bombs[k].m_free)
                      {
                          QSound::play(SOUND_BOMB);
                          m_bombs[k].m_free=false;
                          m_bombs[k].m_x=m_enemys[i].m_x;
                          m_bombs[k].m_y=m_enemys[i].m_y;
                          break;
                      }
                  }
            }
}

int Widget::boom2()
{
    for(int i=0;i<20;i++)
        if(m_enemys[i].m_free==false)
        for(int j=0;j<20;j++)
        if(m_enemys[i].m_bullet[j].m_free==false)
            if(we_plane.m_Rect.intersects(m_enemys[i].m_bullet[j].m_Rect))
            {    m_enemys[i].m_bullet[j].m_free=true;
                 life--;
                 if(life<=0)
                  for(int k=0;k<BOMB_NUM;k++)
                  {
                      if(m_bomb[k].m_free)
                      {
                          QSound::play(SOUND_BOMB);
                          m_bomb[k].m_free=false;

                          m_bomb[k].m_x=we_plane.m_x;
                          m_bomb[k].m_y=we_plane.m_y;

                          break;
                      }
                  }
            }
}

int Widget::boom5()
{
    for(int i=0;i<20;i++)
        if(m_enemys[i].m_free==false)
        for(int j=0;j<20;j++)
        if(we_plane.m_bullet1[j].m_free==false)
            if(m_enemys[i].m_Rect.intersects(we_plane.m_bullet1[j].m_Rect))
            {   score++;
                m_enemys[i].m_free=true;
                  we_plane.m_bullet1[j].m_free=true;
                  for(int k=0;k<BOMB_NUM;k++)
                  {
                      if(m_bombs[k].m_free)
                      {
                          QSound::play(SOUND_BOMB);
                          m_bombs[k].m_free=false;
                          m_bombs[k].m_x=m_enemys[i].m_x;
                          m_bombs[k].m_y=m_enemys[i].m_y;
                          break;
                      }
                  }
            }
}

int  Widget::boom4()
{
    if(m_weapons.m_free)
            if(m_weapons.m_Rect.intersects(we_plane.m_Rect))
            {    m_weapons.m_free=false;
                 we=true;
                 ki=score;
            }
}

int Widget::boom6()
{
        for(int j=0;j<20;j++)
        if(boss.m_bullet[j].m_free==false)
            if(boss.m_bullet[j].m_Rect.intersects(we_plane.m_Rect))
            {   life--;
                boss.m_bullet[j].m_free=true;
                if(life<=0)
                 for(int k=0;k<BOMB_NUM;k++)
                 {
                     if(m_bomb[k].m_free)
                     {
                         QSound::play(SOUND_BOMB);
                         m_bomb[k].m_free=false;

                         m_bomb[k].m_x=we_plane.m_x;
                         m_bomb[k].m_y=we_plane.m_y;

                         break;
                     }
            }
            }
}

int Widget::boom7()
{
    for(int j=0;j<20;j++)
    if(boss.m_bullet1[j].m_free==false)
        if(boss.m_bullet1[j].m_Rect.intersects(we_plane.m_Rect))
        {   life--;
            boss.m_bullet1[j].m_free=true;
            if(life<=0)
             for(int k=0;k<BOMB_NUM;k++)
             {
                 if(m_bomb[k].m_free)
                 {
                     QSound::play(SOUND_BOMB);
                     m_bomb[k].m_free=false;

                     m_bomb[k].m_x=we_plane.m_x;
                     m_bomb[k].m_y=we_plane.m_y;

                     break;
                 }
        }
        }
}

int Widget::boom8()
{
    for(int j=0;j<20;j++)
    if(boss.m_bullet2[j].m_free==false)
        if(boss.m_bullet2[j].m_Rect.intersects(we_plane.m_Rect))
        {   life--;
            boss.m_bullet2[j].m_free=true;
            if(life<=0)
             for(int k=0;k<BOMB_NUM;k++)
             {
                 if(m_bomb[k].m_free)
                 {
                     QSound::play(SOUND_BOMB);
                     m_bomb[k].m_free=false;

                     m_bomb[k].m_x=we_plane.m_x;
                     m_bomb[k].m_y=we_plane.m_y;

                     break;
                 }
        }
        }
}

int Widget::boom9()
{
    if(boss.m_free==false)
        for(int j=0;j<20;j++)
        if(we_plane.m_bullet1[j].m_free==false)
            if(boss.m_Rect.intersects(we_plane.m_bullet1[j].m_Rect))
            {   bosslife--;
                  we_plane.m_bullet1[j].m_free=true;
                  if(bosslife<=0)
                  for(int k=0;k<BOMB_NUM;k++)
                  {
                      if(m_bombes[k].m_free)
                      {
                          QSound::play(SOUND_BOMB);
                          m_bombes[k].m_free=false;
                          m_bombes[k].m_x=240-boss.m_Rect.width()*0.5;
                          m_bombes[k].m_y=0;
                          if(k==3)
                              over=true;
                          break;
                      }
                  }
            }
}

int Widget::boom10()
{
    if(boss.m_free==false)
    for(int j=0;j<20;j++)
    if(we_plane.m_bullet[j].m_free==false)
        if(boss.m_Rect.intersects(we_plane.m_bullet1[j].m_Rect))
        {   bosslife--;
              we_plane.m_bullet[j].m_free=true;
              if(bosslife<=0)
              for(int k=0;k<BOMB_NUM;k++)
              {
                  if(m_bombes[k].m_free)
                  {
                      QSound::play(SOUND_BOMB);
                      m_bombes[k].m_free=false;
                      m_bombes[k].m_x=240-boss.m_Rect.width()*0.5;
                      m_bombes[k].m_y=0;
                      if(k==3)
                          over=true;
                      break;
                  }
              }
        }
}
void Widget::playGame()
{

    //delete label_logo;
    //delete ToolButton_start;
    QSound::play(SOUND_BACKGROUND);
    //启动定时器
    m_Timer.start();
    //监听定时器
    ui->label_5->hide();
    ui->label_6->hide();
    connect(&m_Timer,&QTimer::timeout,[=](){

    if(!over)
    {
        ui->label->setNum(life);
       ui->label->setStyleSheet("QLabel{color:red;}");
        ui->label_2->setStyleSheet("QLabel{color:red;}");
        ui->label_4->setNum(score);
        ui->label_3->setStyleSheet("QLabel{color:yellow;}");
         ui->label_4->setStyleSheet("QLabel{color:yellow;}");
         if(boss.m_free==false)
         {
             ui->label_5->show();
             ui->label_6->show();
             ui->label_6->setNum(bosslife);
         }

        boom1();
        boom2();
        boom3();
        boom4();
        boom5();
        boom6();
        boom7();
        boom8();
        boom9();
        boom10();
         }
        if(score==50)
        {
            big=1;
        }
        if(score==10)
            Weapons();
        enemyToScene();
         weupdetaPosition();
         bupdatePosition();
        //更新游戏中元素的坐标
        updatePosition();
        //重新绘制图片
        update();



            //;
         });

}
void Widget::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();
    for(int i=0;i<20;i++)
    {
        if(m_enemys[i].m_free==false)
        {
            m_enemys[i].updatePosition();
            for(int j=0;j<20;j++)
                if(m_enemys[i].m_bullet[j].m_free==false)
                    m_enemys[i].m_bullet[j].updatePosition();
        }
    }
    for(int i=0;i<20;i++)
        if(we_plane.m_bullet[i].m_free==false)
            we_plane.m_bullet[i].weupdatePosition();
    if(we)
    for(int i=0;i<20;i++)
        if(we_plane.m_bullet1[i].m_free==false)
            we_plane.m_bullet1[i].weupdatePosition();
    if(score>=50)
    {
        for(int i=0;i<20;i++)
        {if(boss.m_bullet1[i].m_free==false)
                boss.m_bullet1[i].updatePosition();
            if(boss.m_bullet[i].m_free==false)
                            boss.m_bullet[i].bossupdatePosition1();
            if(boss.m_bullet2[i].m_free==false)
                            boss.m_bullet2[i].bossupdatePosition2();
        }
    }
    for(int i=0;i<BOMB_NUM;i++)
    {
        if(m_bombs[i].m_free==false)
        {
            m_bombs[i].updateInfo();
        }
    }
    for(int i=0;i<BOMB_NUM;i++)
    {
        if(m_bomb[i].m_free==false)
        {
            m_bomb[i].updateInfo();
        }
    }  for(int i=0;i<5;i++)
    {
        if(m_bombes[i].m_free==false)
        {
            m_bombes[i].updateInfo();
        }
    }
    if(m_weapons.m_free)
        m_weapons.updatePosition();

}
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(_kbhit())
       {
        int a = _getch();
        if(a==3)
            _getch();

        }
    //QPixmap pix;
    //pix.load("C:/Qt/Qt5.9.0/res/oo.png");
    //painter.drawPixmap(0,0,pix);
    if(!over)
    {
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);
    if(life>0)
    painter.drawPixmap(we_plane.m_x,we_plane.m_y,we_plane.we_plane);
    for(int i=0;i<20;i++)
    {
        if(m_enemys[i].m_free==false)
        {
           painter.drawPixmap(m_enemys[i].m_x,m_enemys[i].m_y,50,50,m_enemys[i].m_enemy);
           for(int j=0;j<20;j++)
               if(m_enemys[i].m_bullet[j].m_free==false)
                   painter.drawPixmap(m_enemys[i].m_bullet[j].m_x,m_enemys[i].m_bullet[j].m_y,20,20,m_enemys[i].m_bullet[j].m_bullet1);
        }

    }
    if(life>0)
    for(int i=0;i<20;i++)
       if(we_plane.m_bullet[i].m_free==false)
            painter.drawPixmap(we_plane.m_bullet[i].m_x,we_plane.m_bullet[i].m_y,40,40,we_plane.m_bullet[i].m_bullet2);
    if(we)
        if(life>0)
    for(int i=0;i<20;i++)
       if(we_plane.m_bullet1[i].m_free==false)
            painter.drawPixmap(we_plane.m_bullet1[i].m_x+40,we_plane.m_bullet1[i].m_y,40,40,we_plane.m_bullet1[i].m_bullet2);

    for(int i=0;i<BOMB_NUM;i++)
    {
        if(m_bombs[i].m_free==false)
        {
           painter.drawPixmap(m_bombs[i].m_x,m_bombs[i].m_y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }
    for(int i=0;i<BOMB_NUM;i++)
    {
        if(m_bomb[i].m_free==false)
        {
           painter.drawPixmap(m_bomb[i].m_x,m_bomb[i].m_y,m_bomb[i].m_pixArr[m_bomb[i].m_index]);
        }
    }for(int i=0;i<5;i++)
    {
        if(m_bombes[i].m_free==false)
        {
           painter.drawPixmap(m_bombes[i].m_x,m_bombes[i].m_y,m_bombes[i].m_pixArr[m_bombes[i].m_index]);
        }
    }
    if(m_weapons.m_free)
        painter.drawPixmap(m_weapons.m_x,m_weapons.m_y,m_weapons.m_wuqi);
    if(score>=50)
        if(bosslife>0)
       {    boss.m_free=false;
            painter.drawPixmap(240-boss.m_Rect.width()*0.5,0,boss.m_bigboss);
        for(int i=0;i<20;i++)
          { if(boss.m_bullet1[i].m_free==false)
                painter.drawPixmap(boss.m_bullet1[i].m_x,boss.m_bullet1[i].m_y,40,40,boss.m_bullet1[i].m_bullet1);
            if(boss.m_bullet[i].m_free==false)
                 painter.drawPixmap(boss.m_bullet[i].m_x,boss.m_bullet[i].m_y,40,40,boss.m_bullet[i].m_bullet1);
            if(boss.m_bullet2[i].m_free==false)
                 painter.drawPixmap(boss.m_bullet2[i].m_x,boss.m_bullet2[i].m_y,40,40,boss.m_bullet2[i].m_bullet1);
        }

    }}
    else
    {
        if(m_map.d==-1)
        {
      QPixmap pix;
      pix.load("C:/Qt/Qt5.9.0/res/oo.png");
      painter.drawPixmap(0,0,pix);
        }
        else
        {
            m_map.map1();
            m_map.mapPosition();
            painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
            painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);
        }
      ui->label_5->hide();
      ui->label_6->hide();
      ui->label->hide();
      ui->label_2->hide();
      ui->label_3->hide();
      ui->label_4->hide();

    }
}

void Widget::bupdatePosition()
{
    recorder++;
    if(recorder<=50)
        return ;
    recorder=0;
     for(int i=0;i<20;i++)
         if(m_enemys[i].m_free==false)
    for(int l=0;l<20;l++)
        if(m_enemys[i].m_bullet[l].m_free)
        {
            m_enemys[i].m_bullet[l].m_free=false;


            m_enemys[i].m_bullet[l].m_x=m_enemys[i].m_x+m_enemys[i].m_Rect.width()*0.32;
            m_enemys[i].m_bullet[l].m_y=m_enemys[i].m_y+m_enemys[i].m_Rect.height()*0.35;
            break;
        }




}

void Widget::weupdetaPosition()
{
    werecorder++;
    if(werecorder<=30)
        return ;
    werecorder=0;
    for(int l=0;l<20;l++)
        if(we_plane.m_bullet[l].m_free)
        {
            we_plane.m_bullet[l].m_free=false;


            we_plane.m_bullet[l].m_x=we_plane.m_x+we_plane.m_Rect.width()*0.5;
            we_plane.m_bullet[l].m_y=we_plane.m_y;
           break;
        }
    if(we)
        for(int l=0;l<20;l++)
            if(we_plane.m_bullet1[l].m_free)
            {
                we_plane.m_bullet1[l].m_free=false;


                we_plane.m_bullet1[l].m_x=we_plane.m_x+we_plane.m_Rect.width()*0.45;
                we_plane.m_bullet1[l].m_y=we_plane.m_y;
               break;
            }
    if(score>=50)
    {
        for(int l=0;l<20;l++)
            if(boss.m_bullet1[l].m_free)
            {
                boss.m_bullet1[l].m_free=false;
                boss.m_bullet1[l].m_x=220;
                boss.m_bullet1[l].m_y=200;
               break;
            }
        for(int l=0;l<20;l++)
            if(boss.m_bullet[l].m_free)
            {
                boss.m_bullet[l].m_free=false;


                boss.m_bullet[l].m_x=220;
                boss.m_bullet[l].m_y=200;
               break;
            }
        for(int l=0;l<20;l++)
            if(boss.m_bullet2[l].m_free)
            {
                boss.m_bullet2[l].m_free=false;


                boss.m_bullet2[l].m_x=220;
                boss.m_bullet2[l].m_y=200;
               break;
            }
    }

}
void Widget::mouseMoveEvent(QMouseEvent * event)
{
   int x =  event->x() - we_plane.m_Rect.width() * 0.5;
   int y =  event->y() - we_plane.m_Rect.height() * 0.5;
   if(x<=0)
       x=0;
   if(y>=700)
       y=700;
   if(y<=0)
       y=0;
   if(x>480-we_plane.m_Rect.width())
       x=480-we_plane.m_Rect.width();

   we_plane.updatePosition(x,y);

}

int Widget::overgame()
{

}

void Widget::Weapons()
{
    m_weapons.m_free=true;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        label_logo->hide();
        ToolButton_start->hide();
        t=t+1;
        if(t==1)
        playGame();
    }
}

