#include "DirectoryPathInput.h"
#include <cstdint>
#include <iostream>
#include <qassert.h>
#include <qcontainerfwd.h>
#include <qdir.h>
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
    QString absoluteDirectoryPath = directory.absolutePath();

    if(directory.exists())
    {
        setText(absoluteDirectoryPath);
        emit validDirectoryPathPrompted(absoluteDirectoryPath);
    }
    else
    {
        emit invalidDirectoryPathPrompted(text());
    }
}

void DirectoryPathInput::setCurrentDirectoryPath(QString currentDirPath)
{
    QDir directory = QDir(currentDirPath);
    auto absoluteDirPath = directory.absolutePath();
    setText(absoluteDirPath);
    currentDirectoryPath = absoluteDirPath;
}

QString DirectoryPathInput::getCurrentDirectoryPath()
{
    return currentDirectoryPath;
}