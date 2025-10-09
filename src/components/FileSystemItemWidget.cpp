#include "FileSystemItemWidget.h"
#include <qevent.h>
#include <qfileiconprovider.h>
#include <qnamespace.h>
#include <qwidget.h>
#include <QMouseEvent>

FileSystemItemWidget::FileSystemItemWidget(QWidget *parent)
{
    ui.setupUi(this);
    ui.filenameLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui.iconLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
}

void FileSystemItemWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        emit primaryInteraction(fileInfo);
    }
}

void FileSystemItemWidget::onRightClick()
{

}

void FileSystemItemWidget::setFileInfo(QFileInfo fileInfo)
{
    this->fileInfo = fileInfo;
    ui.filenameLabel->setText(fileInfo.fileName());
}

void FileSystemItemWidget::setThumbnail(QPixmap thumnailImage)
{
    ui.iconLabel->setPixmap(thumnailImage);
}