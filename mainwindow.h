#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTextEdit *edit;

private slots:
void newfile();
void openfile();
void savefile();
void saveas();
void exitMyNotepad();
void undo();
void cut();
void copy();
void paste();
void selectAll();
void date();
void setfont();
void setcolor();
void aboutMyNotepad();
void aboutQt();

bool texthaschanged();

signals:

};

#endif // MAINWINDOW_H
