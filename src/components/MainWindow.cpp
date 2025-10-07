#include "MainWindow.h"
#include "DirectoryPathWidget.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
{
    ui.setupUi(this);

    //connect(ui.directoryPathWidget, &DirectoryPathWidget::onPathPrompt, this, &MainWindow::handleCurrentPathChange);
}


void MainWindow::handleCurrentPathChange(std::string newPath)
{
    std::cout<<"Path changed! New path is: "<<newPath<<std::endl;
}
