#include "FileSystemItemWidget.h"

FileSystemItemWidget::FileSystemItemWidget(QWidget *parent)
{
    ui.setupUi(this);
}

void FileSystemItemWidget::onLeftClick()
{

}

void FileSystemItemWidget::onRightClick()
{

}

void FileSystemItemWidget::setFileInfo(QFileInfo fileInfo)
{
    this->fileInfo = fileInfo;
    //ui.iconLabel->pixmap(fileInfo);
    ui.filenameLabel->setText(fileInfo.fileName());
}