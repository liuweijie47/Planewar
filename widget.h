#ifndef WIDGET_H
#define WIDGET_H
#include<QPainter>
#include<QPixmap>
#include <QKeyEvent>
#include"emeyplane.h"
#include <QWidget>
#include<QTimer>
#include"map.h"
#include"weplane.h"
#include"bomb.h"
#include"bomb1.h"
#include"QMouseEvent"
#include"QLabel"
#include"QToolButton"
#include"wuqi.h"
#include"bigboos.h"
#include"bomb2.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initScene();
    QTimer m_Timer;
    //启动游戏 用于启动定时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //绘图事件
    void paintEvent(QPaintEvent*event);
    void bupdatePosition();
    void weupdetaPosition();
    void mouseMoveEvent(QMouseEvent *event);
    int overgame();
    void Weapons();
   void mousePressEvent(QMouseEvent *event);
    //地图对象
    emeyplane m_enemys[20];
    Bomb m_bombs[BOMB_NUM];
    bomb1 m_bomb[BOMB_NUM];
    bomb2 m_bombes[BOMB_NUM];
    QLabel *label_logo=new QLabel(this);
    QToolButton *ToolButton_start = new QToolButton(this);
    int t;
    void enemyToScene();
    int  boom1();
    int  boom3();
    int  boom2();
    int boom5();
    int  boom4();
    int boom6();
    int boom7();
    int boom8();
    int boom9();
    int boom10();
    bool over;
    int life;
    int score;
    int  m_recorder;
    int  recorder;
    int  werecorder;
    weplane we_plane;
    Map m_map;
    wuqi m_weapons;
    bigboos boss;
    int  time;
    int d=0;
    int bosslife;
    bool we=false;
    int ki;
    int big;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
