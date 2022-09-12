#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->progressBar->setValue(0);
    QString text = ui->plainTextEdit->toPlainText();
    ui->progressBar->setValue(10);
    showmsgbox("Please close the player instance after played");
    fstream file;
       ui->progressBar->setValue(20);
       file.open("Prebuilt/a.txt",ios::out);

       if(!file)
       {
           showmsgbox("Error in creating file!!!");
           ui->progressBar->setValue(0);
           return;
       }
       ui->progressBar->setValue(30);
       //showmsgbox("File created successfully.");

       file.write(text.toStdString().c_str(),text.toStdString().size());
       file.close();
       ui->progressBar->setValue(60);
       this_thread::sleep_for(std::chrono::milliseconds(500));
       system("cd Prebuilt && ./execute.sh");
       ui->progressBar->setValue(90);
       this_thread::sleep_for(std::chrono::seconds(2));
       system("cd Prebuilt && totem --play b.mp3");
       ui->progressBar->setValue(100);
}

void MainWindow::showmsgbox(string strTxt)
{
    QString str;
    str = QString::fromUtf8(strTxt.c_str());
    QMessageBox msgBox;
    //msgBox.setText("");
    msgBox.setInformativeText(str);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->plainTextEdit->clear();
}

