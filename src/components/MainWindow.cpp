#include "MainWindow.h"
#include "DirectoryPathWidget.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
{
    ui.setupUi(this);

    connect(ui.directoryPathWidget, &DirectoryPathWidget::validPathPrompt, this, &MainWindow::onDirectoryWidgetPathChange);
    // TODO: Should be a dependency, not hardcoded!
    setCurrentDirectoryPath("/");
}

void MainWindow::setCurrentDirectoryPath(QString currentDirPath)
{
    // Tell children that they should change their state to reflect this
    ui.directoryPathWidget->setCurrentDirectoryPath(currentDirPath);
    ui.directoryView->setCurrentDirectoryPath(currentDirPath);
}

void MainWindow::onDirectoryWidgetPathChange(QString path)
{
    std::cout<<"Path changed via child widget! New path is: "<<path.toStdString()<<std::endl;
    ui.directoryView->displayDirectory(path);
}
