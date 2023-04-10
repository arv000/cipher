#include "mainwindow.h"
#include "main_widget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_mainWidiget(new MainWidget())
{
    setCentralWidget(m_mainWidiget);
}

MainWindow::~MainWindow() {}
