#include <opencv2/opencv.hpp>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matching.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QDirIterator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOpen_clicked()
{
    QString pathtest=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "../DB-test/lvl1",
                "Image file (*.jpg *.png);;"
                ); // Find file path

    double mindist = 9999.0;
    double newdist;
    QString pathresult, newpath;
    QDirIterator it("../DB/lvl1", QStringList() << "*", QDir::Files, QDirIterator::Subdirectories);

    while (it.hasNext()){
        newpath = it.next();
        newdist = match(newpath.toLatin1().data(), pathtest.toLatin1().data());
        qDebug() << newpath.toLatin1().data() << pathtest.toLatin1().data() << newdist;
        if(newdist<mindist && newdist>=0){
            mindist = newdist;
            pathresult = newpath;
        }
    }

    //mindist = match("../DB-test/lvl1/adobe.png", "../DB/lvl1/adobe.jpg");
    //QPixmap imgl(path1);
    QPixmap imgr(pathresult);
    imgr.scaled(QSize(64, 64), Qt::KeepAspectRatio);
    //ui->labelLeft->setPixmap(imgl);
    ui->labelLeft->setPixmap(imgr);

    QMessageBox::information(this, tr("File Name"), QString::number(mindist));
}
