#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <qmainwindow.h>
#include <qtmetamacros.h>
#include <qwidget.h>

#include "ui_MainWindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    Ui::MainWindow ui;
};

#endif // __MAINWINDOW_H__
