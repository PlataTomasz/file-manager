#include "DirectoryPathWidget.h"
#include "DirectoryPathInput.h"
#include <qassert.h>
#include <qobject.h>

DirectoryPathWidget::DirectoryPathWidget(QWidget *parent)
{
    ui.setupUi(this);
    connect(ui.directoryPathInput, &DirectoryPathInput::validDirectoryPathPrompted, this, &DirectoryPathWidget::onValidPathPrompt);
    connect(ui.goBackBtn, &QPushButton::clicked, this, &DirectoryPathWidget::onBackButtonPressed);
}

void DirectoryPathWidget::onValidPathPrompt(QString path)
{
    emit pathEdited(path);
}

void DirectoryPathWidget::onBackButtonPressed()
{
    emit backButtonPressed();
}

void DirectoryPathWidget::changeDisplayedPath(QString path)
{
    ui.directoryPathInput->setText(path);
}