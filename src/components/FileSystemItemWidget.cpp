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
    QFileIconProvider iconProvider;

    this->fileInfo = fileInfo;
    ui.iconLabel->setPixmap(iconProvider.icon(fileInfo).pixmap(64, 64));
    ui.filenameLabel->setText(fileInfo.fileName());
}