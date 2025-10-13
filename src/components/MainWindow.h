#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <qmainwindow.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qwidget.h>

#include "DirectoryNavigationService.h"
#include "ui_MainWindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(
        DirectoryNavigationService *directoryNavigationService,
        QWidget *parent = nullptr
    );
private:
    DirectoryNavigationService *directoryNavigationService;
    Ui::MainWindow ui;
};

#endif // __MAINWINDOW_H__
