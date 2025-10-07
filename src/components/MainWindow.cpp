#include "MainWindow.h"
#include "DirectoryPathWidget.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
{
    ui.setupUi(this);

    connect(ui.directoryPathWidget, &DirectoryPathWidget::validPathPrompt, this, &MainWindow::onDirectoryWidgetPathChange);
}


void MainWindow::onDirectoryWidgetPathChange(QString path)
{
    std::cout<<"Path changed via child widget! New path is: "<<path.toStdString()<<std::endl;
    ui.directoryView->displayDirectory(path);
}
