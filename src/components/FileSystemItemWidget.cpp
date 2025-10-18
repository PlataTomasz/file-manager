#include "FileSystemItemWidget.h"
#include <qcursor.h>
#include <qevent.h>
#include <qfileiconprovider.h>
#include <qmenu.h>
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
    showContextMenu();
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

QAction *FileSystemItemWidget::showContextMenu()
{
    // TODO: Can be cached
    QMenu *menu = new QMenu();
    menu->addAction(new QAction("Rename..."));
    menu->addAction(new QAction("Cut"));
    menu->addAction(new QAction("Copy"));
    menu->addAction(new QAction("Delete"));

    return menu->exec(QCursor::pos());
}

void FileSystemItemWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        onRightClick();
    }
}