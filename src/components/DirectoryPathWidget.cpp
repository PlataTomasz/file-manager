#include "DirectoryPathWidget.h"
#include "DirectoryPathInput.h"
#include <qassert.h>

DirectoryPathWidget::DirectoryPathWidget(QWidget *parent)
{
    ui.setupUi(this);
    connect(ui.directoryPathInput, &DirectoryPathInput::validDirectoryPathPrompted, this, &DirectoryPathWidget::onValidPathPrompt);
}

void DirectoryPathWidget::onValidPathPrompt(QString path)
{
    emit validPathPrompt(path);
}

void DirectoryPathWidget::setCurrentDirectoryPath(QString currentDirPath)
{
    ui.directoryPathInput->setCurrentDirectoryPath(currentDirPath);
}