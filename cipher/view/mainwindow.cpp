#include "mainwindow.h"
#include "main_widget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_mainWidiget(new MainWidget())
{
    initUI();
    setCentralWidget(m_mainWidiget);
}
void MainWindow::initUI()
{
    setWindowTitle(tr("加密软件"));
    resize(950, 600);
}

MainWindow::~MainWindow() {}
