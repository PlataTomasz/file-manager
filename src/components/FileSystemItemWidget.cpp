#include "FileSystemItemWidget.h"
#include <qfileiconprovider.h>

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
    QFileIconProvider iconProvider;

    this->fileInfo = fileInfo;
    ui.iconLabel->setPixmap(iconProvider.icon(fileInfo).pixmap(64, 64));
    ui.filenameLabel->setText(fileInfo.fileName());
}