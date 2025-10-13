#include "MainWindow.h"
#include "DirectoryNavigationService.h"
#include "DirectoryPathWidget.h"
#include "DirectoryViewWidget.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
{
    ui.setupUi(this);

    // TODO: Should be a dependency, not hardcoded!
    directoryNavigationService = new DirectoryNavigationService();

    connect(
        ui.directoryPathWidget, &DirectoryPathWidget::pathEdited, 
        directoryNavigationService, &DirectoryNavigationService::changeCurrentDirectory
    );
    connect(
        directoryNavigationService, &DirectoryNavigationService::currentDirectoryChanged,
        ui.directoryPathWidget, &DirectoryPathWidget::changeDisplayedPath
    );
    connect(
        ui.directoryView, &DirectoryViewWidget::directoryOpened,
        directoryNavigationService, &DirectoryNavigationService::changeCurrentDirectory
    );
    connect(
        directoryNavigationService, &DirectoryNavigationService::currentDirectoryChanged,
        ui.directoryView, &DirectoryViewWidget::displayDirectory
    );
    connect(
        ui.directoryPathWidget, &DirectoryPathWidget::backButtonPressed,
        directoryNavigationService, &DirectoryNavigationService::returnToPreviousDirectory
    );

    ui.quickDirAccessWidget->addEntry("/home");
    ui.quickDirAccessWidget->addEntry("/usr");
    ui.quickDirAccessWidget->addEntry("/opt");

    directoryNavigationService->setInitialPath("/home");
}