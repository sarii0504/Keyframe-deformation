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
};//�½��ṹ��洢������Ϣ


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void MainWindow::paintEvent(QPaintEvent *);//�����¼�����
    void MainWindow::mousePressEvent(QMouseEvent *event);//������¼�����
    bool MainWindow::InPix(QPoint p);//����������Ƿ��ڻ����ڵĺ���

    int MainWindow::speed();//��ȡ�û�ѡ������ٶȵĺ���
    int MainWindow::number();//��ȡ�û�ѡ���ֵ�����ĺ���

    ~MainWindow();


private slots:
     void on_drawButton_clicked();//���ư�ť�ۺ���

     void on_Btn1_clicked();//�����Բ�ֵ����ť�ۺ���

     void on_Btn2_clicked();//��ʸ�����Բ�ֵ����ť�ۺ���

     void on_clear_clicked();//���������ť�ۺ���

     void linear();//���Բ�ֵ�㷨

     void vector();//ʸ�����Բ�ֵ�㷨

     void on_close_clicked();//���պ�ͼ�Ρ���ť�������

     void on_loadArm_clicked();//����ͼƬ����

private:
    QPixmap pix;//�������ɰ�ɫ����
    Ui::MainWindow *ui;

    QButtonGroup *speedGroup;//�½������ٶȰ�ť��
    QButtonGroup *numberGroup;//�½���ֵ������ť��
    QButtonGroup *pixGroup;//ѡ���Ƿ���ʾ��ֵ��ť��

    POINT endPoint[50];//��ֹ��״������Ϣ
    POINT startPoint[50];//��ʼ��״������Ϣ
    POINT tempPoint[50];//�м���״������Ϣ
    POINT basePoint[100];//ʸ�����Բ�ֵ��¼һ����׼��
    QPoint start_Point,end_Point;//QPoint���ͱ��������ڻ���

    int close=0;//�Ƿ��Ǳպ�ͼ��
    int img=1;//��¼�Ƿ�����ͼƬ
    int count=-1;//��¼�����
    int status=1,flag=0;//���ֻ��Ƴ�ʼ��״������ֹ��״
    bool draw=false,move=false,clear=false;//��¼����״̬��������״�����Ʊ����˶����������
    float In=100,M=20,n=0;//In:��ʱ�����ʱ�䣬���Ʊ����ٶȣ�M:�����ؼ�֮֡���֡������n:��¼��ǰ���Ƶ�֡���
    float startDist[50],startAngle[50],endDist[50],endAngle[50],tempDist[50],tempAngle[50];
    //ʸ�����Բ�ֵ�㷨��¼��״�ļ�������Ϣ
    QTimer *timer;//��ʱ��
};

#endif // MAINWINDOW_H
