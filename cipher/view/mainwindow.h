#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class MainWidget;
class MainWindow : public QMainWindow {
    Q_OBJECT
   private:
    MainWidget *m_mainWidiget;

   public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif  // MAINWINDOW_H
