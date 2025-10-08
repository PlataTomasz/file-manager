#include "DirectoryPathInput.h"
#include <cstdint>
#include <iostream>
#include <qassert.h>
#include <qline.h>
#include <qlineedit.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include <QDir>

DirectoryPathInput::DirectoryPathInput(QWidget *parent)
{
    connect(this, &QLineEdit::returnPressed, this, &DirectoryPathInput::onSubmit);
}

void DirectoryPathInput::onSubmit()
{
    // Check if path exists
    QDir directory = QDir(text());

    if(directory.exists())
    {
        emit validDirectoryPathPrompted(text());
    }
    else
    {
        emit invalidDirectoryPathPrompted(text());
    }
}

void DirectoryPathInput::setCurrentDirectoryPath(QString currentDirPath)
{
    setText(currentDirPath);
    currentDirectoryPath = currentDirPath;
}