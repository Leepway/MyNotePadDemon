#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtCore>
#include <QMessageBox>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QString>
#include <QIODevice>
#include <QDate>
#include <QFont>
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    edit = new QTextEdit(this);
    this->setCentralWidget(edit);
    statusBar()->showMessage("Ready");

    //文件
    connect(ui->action_NewFile,&QAction::triggered,this,&MainWindow::newfile);
    connect(ui->action_OpenFile,&QAction::triggered,this,&MainWindow::openfile);
    connect(ui->action_Save,&QAction::triggered,this,&MainWindow::savefile);
    connect(ui->action_SaveAs,&QAction::triggered,this,&MainWindow::saveas);
    connect(ui->action_Exit,&QAction::triggered,this,&MainWindow::exitMyNotepad);

    //编辑
    connect(ui->action_UnDo,&QAction::triggered,this,&MainWindow::undo);
    connect(ui->action_Cut,&QAction::triggered,this,&MainWindow::cut);
    connect(ui->action_Copy,&QAction::triggered,this,&MainWindow::copy);
    connect(ui->action_Paste,&QAction::triggered,this,&MainWindow::paste);
    connect(ui->action_SelectAll,&QAction::triggered,this,&MainWindow::selectAll);
    connect(ui->action_Date,&QAction::triggered,this,&MainWindow::date);

    //格式
    connect(ui->action_Color,&QAction::triggered,this,&MainWindow::setcolor);
    connect(ui->action_Font,&QAction::triggered,this,&MainWindow::setfont);

    //关于
    connect(ui->action_AboutMyNotePad,&QAction::triggered,this,&MainWindow::aboutMyNotepad);
    connect(ui->action_AboutQt,&QAction::triggered,this,&MainWindow::aboutQt);

    //判断是否更改

    connect(edit,&QTextEdit::textChanged,this,&MainWindow::texthaschanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newfile()
{
    //新建
    if (texthaschanged())
        QMessageBox::warning(this,"提示","文档已更改，是否保存？",QMessageBox::Yes,QMessageBox::Cancel,QMessageBox::Ignore);



    this->edit->clear();
}


void MainWindow::openfile()
{
    //打开
    QString filename = QFileDialog::getOpenFileName(this,"请选择文件","./","text files (*.txt)");
    QFile file (filename);

    if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {QMessageBox *msg = new QMessageBox(this);
        msg->setText("Error");
        return;}
    edit->setText( file.readAll());
    file.close();
}

void MainWindow::savefile()
{
    //保存

}

void MainWindow::saveas()
{
    //另存为
    QString filename = QFileDialog::getSaveFileName(this,"请输入文件名","./","text file(*.txt)");
    QFile file (filename);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
        return;
    QTextStream out(&file);
    out <<edit->toPlainText();
}

void MainWindow::undo()
{
    //撤销
    edit->undo();
}

void MainWindow::cut()
{
    //剪切
    edit->cut();
}

void MainWindow::copy()
{
    //复制
    edit->copy();
}

void MainWindow::paste()
{
    //粘贴
    edit->paste();
}

void MainWindow::selectAll()
{
    //全选
    edit->selectAll();
}


void MainWindow::date()
{
    //日期
    edit->insertPlainText(QDate::currentDate().toString());
}


void MainWindow::aboutMyNotepad()
{
    //关于NotePad
     QMessageBox::information(this,tr("关于MyNotePad"),tr("QQ:763045276\n made by Dev_Lee"));
}


void MainWindow::aboutQt()
{
    //关于Qt
    QMessageBox::aboutQt(this,"About Qt");
}

void MainWindow::exitMyNotepad()
{
    //退出
    this->close();
}

void MainWindow::setfont()
{
    //字体
    bool ok;
    QFont font = QFontDialog::getFont(&ok,QFont("宋体",10),this,"请选择字体");
    if (ok)
    {
        edit->setCurrentFont(font);
                //setFont(font);
    }
    else
    QMessageBox::information(this,"error","set font undone!!!");
}

void MainWindow::setcolor()
{
    //颜色
    QColor color = QColorDialog::getColor(Qt::black,this,"请选择颜色");
    edit->setTextColor(color);
}

bool MainWindow::texthaschanged()
{
    return true;
}
