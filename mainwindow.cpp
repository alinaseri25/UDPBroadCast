#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->BtnSend,&QPushButton::clicked,this,&MainWindow::onBtnSendClicked);

    udpSocket = new QUdpSocket(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBtnSendClicked()
{
    QByteArray datagram = QString("Broadcast message from my App on : %1\n").arg(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss")).toLatin1();

    udpSocket->writeDatagram(datagram,QHostAddress::Broadcast,2525);
}
