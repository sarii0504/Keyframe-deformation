#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<QButtonGroup>
#include<QLabel>
#include<QImage>
#include<QPixmap>
#include<QLabel>

struct POINT{
    float x;
    float y;
};//新建结构体存储坐标信息


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void MainWindow::paintEvent(QPaintEvent *);//绘制事件函数
    void MainWindow::mousePressEvent(QMouseEvent *event);//鼠标点击事件函数
    bool MainWindow::InPix(QPoint p);//检测鼠标落点是否在画布内的函数

    int MainWindow::speed();//读取用户选择变形速度的函数
    int MainWindow::number();//读取用户选择插值数量的函数

    ~MainWindow();


private slots:
     void on_drawButton_clicked();//绘制按钮槽函数

     void on_Btn1_clicked();//“线性插值”按钮槽函数

     void on_Btn2_clicked();//“矢量线性插值”按钮槽函数

     void on_clear_clicked();//“清除”按钮槽函数

     void linear();//线性插值算法

     void vector();//矢量线性插值算法

     void on_close_clicked();//“闭合图形”按钮点击函数

     void on_loadArm_clicked();//加载图片函数

private:
    QPixmap pix;//用于生成白色画布
    Ui::MainWindow *ui;

    QButtonGroup *speedGroup;//新建变形速度按钮组
    QButtonGroup *numberGroup;//新建插值数量按钮组
    QButtonGroup *pixGroup;//选择是否显示插值按钮组

    POINT endPoint[50];//终止形状坐标信息
    POINT startPoint[50];//初始形状坐标信息
    POINT tempPoint[50];//中间形状坐标信息
    POINT basePoint[100];//矢量线性插值记录一个基准点
    QPoint start_Point,end_Point;//QPoint类型变量，用于绘制

    int close=0;//是否是闭合图形
    int img=1;//记录是否载入图片
    int count=-1;//记录点个数
    int status=1,flag=0;//区分绘制初始形状还是终止形状
    bool draw=false,move=false,clear=false;//记录绘制状态：绘制形状，绘制变形运动，清除画布
    float In=100,M=20,n=0;//In:定时器间隔时间，控制变形速度，M:两个关键帧之间的帧数量，n:记录当前绘制的帧编号
    float startDist[50],startAngle[50],endDist[50],endAngle[50],tempDist[50],tempAngle[50];
    //矢量线性插值算法记录形状的极坐标信息
    QTimer *timer;//定时器
};

#endif // MAINWINDOW_H
