#include "DirectoryPathWidget.h"
#include "DirectoryPathInput.h"
#include <qassert.h>

DirectoryPathWidget::DirectoryPathWidget(QWidget *parent)
{
    ui.setupUi(this);
    connect(ui.directoryPathInput, &DirectoryPathInput::validDirectoryPathPrompted, this, &DirectoryPathWidget::onValidPathPrompt);
    connect(ui.goBackBtn, &QPushButton::clicked, this, &DirectoryPathWidget::onBackButtonPressed);
}

void DirectoryPathWidget::onValidPathPrompt(QString path)
{
    emit validPathPrompt(path);
}

void DirectoryPathWidget::setCurrentDirectoryPath(QString currentDirPath)
{
    previousDirectories.push(ui.directoryPathInput->getCurrentDirectoryPath());
    ui.directoryPathInput->setCurrentDirectoryPath(currentDirPath);
}

void DirectoryPathWidget::onBackButtonPressed()
{
    if(!previousDirectories.empty())
    {
        auto lastPath = previousDirectories.top();
        previousDirectories.pop();

        ui.directoryPathInput->setCurrentDirectoryPath(lastPath);
        emit validPathPrompt(lastPath);
    }
}