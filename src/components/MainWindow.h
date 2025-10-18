#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <qmainwindow.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qwidget.h>

#include "DirectoryNavigationService.h"
#include "ui_MainWindow.h"

/**
Represents main window of the file manager. It manages communication between DirectoryNavigationService and other objects, so they can alter current directory or receive notifications that indicate the current directory changed.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /**
    @param directoryNavigationService DirectoryNavigationService instance to be used by main window.
    @param parent Parent of this widget.
    */
    explicit MainWindow(
        DirectoryNavigationService *directoryNavigationService,
        QWidget *parent = nullptr
    );
private:
    DirectoryNavigationService *directoryNavigationService;
    Ui::MainWindow ui;
};

#endif // __MAINWINDOW_H__
