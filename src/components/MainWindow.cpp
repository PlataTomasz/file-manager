#include "MainWindow.h"
#include "DirectoryPathWidget.h"
#include "DirectoryViewWidget.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
{
    ui.setupUi(this);

    // TODO: Should be a dependency, not hardcoded!
    setCurrentDirectoryPath("/");

    connect(ui.directoryPathWidget, &DirectoryPathWidget::validPathPrompt, this, &MainWindow::onDirectoryWidgetPathChange);
    connect(ui.directoryView, &DirectoryViewWidget::currentDirectoryChangeRequest, this, &MainWindow::currentDirectoryChangeRequested);
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

void MainWindow::currentDirectoryChangeRequested(QString newCurrentDirPath)
{
    setCurrentDirectoryPath(newCurrentDirPath);
}