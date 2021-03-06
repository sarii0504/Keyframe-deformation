#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include<qmath.h>
#include<QPixmap>
#include<QPixmapCache>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pix=QPixmap(650, 300);//画布大小
    pix.fill(Qt::white);//绘制背景为白色

    ui->close->setEnabled(false);
    speedGroup = new QButtonGroup(this);//将单选框分组
    speedGroup->addButton(ui->speed1,0);
    speedGroup->addButton(ui->speed2,1);
    speedGroup->addButton(ui->speed3,2);

    numberGroup=new QButtonGroup(this);//将单选框分组
    numberGroup->addButton(ui->number1,0);
    numberGroup->addButton(ui->number2,1);
    numberGroup->addButton(ui->number3,2);

    pixGroup=new QButtonGroup(this);//将单选框分组
    pixGroup->addButton(ui->display,0);
    pixGroup->addButton(ui->hidden,1);


    QPixmap px;
    px.load("C:/Users/sam/Desktop/JiDong/arm.jpg");
    ui->armLabel->setPixmap(px);
    ui->armLabel->setVisible(false);


}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(&pix);

    if(draw&&count>=0&&!clear){
        //绘制初始形状和终止形状的情况
        p.setPen(QPen(QColor(0,0,0),1,Qt::SolidLine,Qt::RoundCap));//设置画笔
        if(flag==1)//绘制初始形状
        {
            startPoint[count].x=end_Point.x();//记录坐标信息
            startPoint[count].y=end_Point.y();
            status=2;
        }


        else//绘制终止形状
        {

            endPoint[count].x=end_Point.x();//记录坐标信息
            endPoint[count].y=end_Point.y();
            status=1;
         }

         if(count>=0)
         p.drawEllipse(end_Point,2,2);//绘制点
         if(count>=1)
             p.drawLine(start_Point,end_Point);//绘制两点之间直线
         start_Point=end_Point;
    }

    if(move&&!clear){
        //绘制变形动画的情况
       p.setPen(QPen(QColor(0,0,0),1,Qt::SolidLine,Qt::RoundCap));//设置画笔
       end_Point.setX(tempPoint[0].x);
       end_Point.setY(tempPoint[0].y);
       p.drawEllipse(end_Point,2,2);//绘制第一个点
       for(int i=1;i<=count;i++){
           //逐个绘制点以及两点之间的直线
           start_Point.setX(tempPoint[i-1].x);
           start_Point.setY(tempPoint[i-1].y);
           end_Point.setX(tempPoint[i].x);
           end_Point.setY(tempPoint[i].y);
           p.drawEllipse(end_Point,2,2);//绘制点
           p.drawLine(start_Point,end_Point);//绘制两点之间的直线
       }
    }


    QPainter painter(this);
    painter.drawPixmap(0, 0, pix);//在画布上绘制

}


void MainWindow::mousePressEvent(QMouseEvent *event)//鼠标左键按下事件函数
{
    if(event->button() == Qt::LeftButton&&InPix(event->pos()))
        //如果鼠标左键按下并且鼠标落点在画布内
    {
        end_Point = event->pos();//记录鼠标位置
        count++;//增加点数
        update();//调用绘制函数，更新画布
    }
}


MainWindow::~MainWindow()//析构函数
{
    delete ui;
}

void MainWindow::on_drawButton_clicked()//点击绘制按钮槽函数
{
    draw=true;
    move=false;
    clear=false;
    count=-1;//重置点数
    ui->close->setEnabled(true);

    if(status==1){//准备绘制初始形状
        flag=1;
        ui->drawButton->setText(QStringLiteral("绘制终止形状"));
    }
    else{//准备绘制终止形状
        flag=2;
        ui->drawButton->setText(QStringLiteral("绘制初始形状"));
        ui->drawButton->setEnabled(false);
     }

}

void MainWindow::on_Btn1_clicked()//点击“线性插值”按钮槽函数
{
    draw=false;
    ui->close->setEnabled(false);
    n=0;
    M=number();//判断变形中间帧数量
    In=speed();//判断变形速度

    pix.fill(Qt::white);//清除画布
    update();//调用绘制时间，更新画布

    timer = new QTimer();//新建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(linear()));//将定时器与槽函数连接
    timer->setInterval(In);//设定时间间隔
    timer->start();//定时器开始工作
}

void MainWindow::on_Btn2_clicked()
{

    draw=false;
    ui->close->setEnabled(false);
    n=0;
    M=number();//判断变形中间帧数量
    In=speed();//判断变形速度


    for(int i=1;i<=count;i++)
        //计算初始形状和终止形状各个矢量的极坐标信息
    {
        float x1,y1;
        x1=startPoint[i].x-startPoint[i-1].x;
        y1=startPoint[i].y-startPoint[i-1].y;

        float x2,y2;
        x2=endPoint[i].x-endPoint[i-1].x;
        y2=endPoint[i].y-endPoint[i-1].y;

        startDist[i-1]=sqrt(x1*x1+y1*y1);
        startAngle[i-1]=qAtan2(y1,x1);

        endDist[i-1]=sqrt(x2*x2+y2*y2);
        endAngle[i-1]=qAtan2(y2,x2);

    }

    for(int i=0;i<=M;i++){
        //计算变形过程中每一帧的基准点坐标信息
        float t=float(i)/M;
        basePoint[i].x=(1-t)*startPoint[0].x+(t)*endPoint[0].x;
        basePoint[i].y=(1-t)*startPoint[0].y+(t)*endPoint[0].y;
    }

    timer = new QTimer();//新建定时器
    connect(timer, SIGNAL(timeout()), this, SLOT(vector()));//连接定时器与槽函数
    timer->setInterval(In);//设定定时器时间间隔
    timer->start();//启动定时器
}


void MainWindow::on_clear_clicked()//“清楚”按钮点击事件槽函数
{
    //重置状态
    draw=false;
    move=false;
    clear=true;
    n=0;
    close=0;
    ui->close->setEnabled(false);
    ui->drawButton->setEnabled(true);
    ui->drawButton->setText(QStringLiteral("绘制初始形状"));
    status=1;
    pix.fill(Qt::white);//设置画布背景为白色
    update();//调用绘制函数，更新画布
}


bool MainWindow::InPix(QPoint p){//判断鼠标是否落在画布内的函数
    if(p.x()<=650&&p.y()<=300)//画布的大小为650*300
        return true;
    else
        return false;
}


void MainWindow::linear(){//线性插值算法（绘制一帧）

    float t=n/M;//当前绘制帧编号/中间帧总数量，得到插值变量
    if(ui->hidden->isChecked()){
    pix.fill(Qt::white);
    clear=true;
    update();//清除当前画布上前一帧的形状
    }

    //绘制下一帧
    move=true;
    clear=false;//更改状态

    for(int i=0;i<=count;i++){//根据插值算法，求出每一个点的坐标信息
        tempPoint[i].x=(1-t)*startPoint[i].x+(t)*endPoint[i].x;
        tempPoint[i].y=(1-t)*startPoint[i].y+(t)*endPoint[i].y;
    }

    n=n+1;//帧编号+1
    if(n>M)//如果帧编号>中间帧总数量
    {
        timer->stop();//停止计时器
    }
    update();//调用绘制函数，更新画布
}

void MainWindow::vector(){//矢量线性插值算法（绘制一帧）

    double PI=3.1415926;

    float t=n/M;//当前绘制帧编号/中间帧总数量，得到插值变量
    if(ui->hidden->isChecked()){
      pix.fill(Qt::white);
      clear=true;
      update();//更新画布，清除画布上前一帧的形状
    }
    //绘制下一帧
    move=true;
    clear=false;//更改状态

    for(int i=0;i<=count;i++){//根据插值算法，求出矢量的极坐标信息
        tempDist[i]=(1-t)*startDist[i]+(t)*endDist[i];
        float angle=endAngle[i]-startAngle[i];

        printf("angle=%f\n",angle);
        if(angle>PI)//两个矢量之间夹角绝对值>180°
        {
            angle=angle-2*PI;//使角度绝对值在0-180°之间
        }
        if(angle<-PI)

        {
            angle=angle+2*PI;
        }
        tempAngle[i]=startAngle[i]+t*angle;

    }

    //将基准点作为矢量的起点
    float tempx=basePoint[int(n)].x;
    float tempy=basePoint[int(n)].y;

    tempPoint[0].x=tempx;
    tempPoint[0].y=tempy;

    //根据矢量极坐标，顺序连接矢量得到插值图形
    for(int i=1;i<=count;i++)
    {
        tempx=tempx+tempDist[i-1]*qCos(tempAngle[i-1]);
        tempy=tempy+tempDist[i-1]*qSin(tempAngle[i-1]);

        tempPoint[i].x=tempx;
        tempPoint[i].y=tempy;
    }
    if(close==1){
      //闭合图形
        tempPoint[count].x=tempPoint[0].x;
        tempPoint[count].y=tempPoint[0].y;
    }



    n=n+1;//帧编号+1
    if(n>M)//如果帧编号>中间帧数量
    {
        timer->stop();//停止计时器
    }
     update();//调用绘制函数，绘制当前帧形状
}


int MainWindow::speed(){//判断用户选择的变形速度
     if(ui->speed1->isChecked())
        return 50;
    else if(ui->speed2->isChecked())
        return 100;
    else
        return 500;
}

int MainWindow::number(){//判断用户选择的中间帧数量
    if(ui->number1->isChecked())
        return 20;
    else  if(ui->number2->isChecked())
        return 10;
    else
        return 5;
}


void MainWindow::on_close_clicked()//一键闭合图形
{
    count=count+1;
    close=1;
    if(flag==1)
    {
        end_Point.setX(startPoint[0].x);
        end_Point.setY(startPoint[0].y);
    }
    else
    {
        end_Point.setX(endPoint[0].x);
        end_Point.setY(endPoint[0].y);
    }
    update();
}

void MainWindow::on_loadArm_clicked()
{
    if(img==1)
    {    ui->armLabel->setVisible(true);
         img=0;
         ui->loadArm->setText(QStringLiteral("隐藏图片"));

    }
    else
    {
        ui->armLabel->setVisible(false);
        img=1;
        ui->loadArm->setText(QStringLiteral("加载图片"));
    }
}
