#include "DirectoryPathInput.h"
#include <cstdint>
#include <iostream>
#include <qline.h>
#include <qlineedit.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include <QDir>

DirectoryPathInput::DirectoryPathInput(QWidget *parent)
{
    //connect(this, &QLineEdit::textEdited, this, &DirectoryPathInput::onTextEdited);
    connect(this, &QLineEdit::returnPressed, this, &DirectoryPathInput::onSubmit);
}

void DirectoryPathInput::validDirectoryPathPrompted(QString path)
{

}

void DirectoryPathInput::invalidDirectoryPathPrompted(QString path)
{

}

void DirectoryPathInput::onSubmit()
{
    // Check if path exists
    QDir directory = QDir(text());

    if(directory.exists())
    {
        emit validDirectoryPathPrompted(text());
        std::cout<<"Valid directory prompted!"<<std::endl;
    }
    else
    {
        emit invalidDirectoryPathPrompted(text());
        std::cout<<"Invalid directory prompted!"<<std::endl;
    }
}

void DirectoryPathInput::onTextEdited(QString path)
{
    
}