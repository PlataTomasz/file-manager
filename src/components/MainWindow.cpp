#include "MainWindow.h"
#include "DirectoryNavigationService.h"
#include "DirectoryPathWidget.h"
#include "DirectoryViewWidget.h"
#include "QuickDirectoryAccessWidget.h"
#include <iostream>

MainWindow::MainWindow(DirectoryNavigationService *directoryNavigationService, QWidget *parent)
{
    ui.setupUi(this);

    this->directoryNavigationService = directoryNavigationService;
    directoryNavigationService->setParent(this);

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

    connect(
        ui.quickDirAccessWidget, &QuickDirectoryAccessWidget::directoryOpened,
        directoryNavigationService, &DirectoryNavigationService::changeCurrentDirectory
    );

    ui.quickDirAccessWidget->addEntry("/home");
    ui.quickDirAccessWidget->addEntry("/usr");
    ui.quickDirAccessWidget->addEntry("/opt");

    directoryNavigationService->setInitialPath("/home");
}