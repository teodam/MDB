#include <opencv2/opencv.hpp>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matching.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QDirIterator>
#include <QDebug>

struct imgstruct {
    QString name;
    QString path;
    double mindist = 999;
};

int posres = 1;
imgstruct imgtab[50];

bool imgcompare(imgstruct img1, imgstruct img2) { return (img1.mindist < img2.mindist); }

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
    posres=1;
    //imgstruct imgtab[50];
    int position=1;
    QDirIterator it("../DB/lvl1", QStringList() << "*", QDir::Files, QDirIterator::Subdirectories);

    imgtab[0].path=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "../DB-test/lvl1",
                "Image file (*.jpg *.png);;"
                );
    imgtab[0].mindist=0;

    while (it.hasNext()){
        imgtab[position].path = it.next();
        imgtab[position].name = it.fileName();
        imgtab[position].mindist = match(
                    imgtab[position].path.toLatin1().data(),
                    imgtab[0].path.toLatin1().data()
                );
        qDebug() << imgtab[0].path.toLatin1().data() << imgtab[position].path.toLatin1().data() << imgtab[position].mindist;
        position=position+1;
    }

    std::sort(imgtab, imgtab+50, imgcompare);

    QPixmap imgl(imgtab[0].path);
    QPixmap imgr(imgtab[posres].path);
    //imgr.scaled(QSize(64, 64), Qt::KeepAspectRatio);
    ui->labelLeft->setPixmap(imgl);
    ui->labelRight->setPixmap(imgr);
    match(imgtab[posres].path.toLatin1().data(),
          imgtab[0].path.toLatin1().data()
      );
    QMessageBox::information(this, tr("File Name"), imgtab[posres].name+"\n Distance : "+QString::number(imgtab[posres].mindist));
}

void MainWindow::on_pushButtonNext_clicked()
{
    if(imgtab[posres+1].mindist!=999)
    {
        posres = posres+1;
        QPixmap imgr(imgtab[posres].path);
        ui->labelRight->setPixmap(imgr);
    }
    match(imgtab[posres].path.toLatin1().data(),
          imgtab[0].path.toLatin1().data()
      );
    QMessageBox::information(this, tr("File Name"), imgtab[posres].name+"\n Distance : "+QString::number(imgtab[posres].mindist));
}

void MainWindow::on_pushButton_clicked()
{
    if(posres>1)
    {
        posres = posres-1;
        QPixmap imgr(imgtab[posres].path);
        ui->labelRight->setPixmap(imgr);
    }
    match(imgtab[posres].path.toLatin1().data(),
          imgtab[0].path.toLatin1().data()
      );
    QMessageBox::information(this, tr("File Name"), imgtab[posres].name+"\n Distance : "+QString::number(imgtab[posres].mindist));
}

void MainWindow::on_pushButtonResult_clicked()
{
    posres = 1;
    QPixmap imgr(imgtab[posres].path);
    ui->labelRight->setPixmap(imgr);
    match(imgtab[posres].path.toLatin1().data(),
          imgtab[0].path.toLatin1().data()
      );
    QMessageBox::information(this, tr("File Name"), imgtab[posres].name+"\n Distance : "+QString::number(imgtab[posres].mindist));
}
