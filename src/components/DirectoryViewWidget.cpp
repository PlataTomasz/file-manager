#include "DirectoryViewWidget.h"
#include "DirectoryItemWidget.h"
#include "FileItemWidget.h"
#include "FileSystemItemWidget.h"
#include "layouts/FlowLayout.h"
#include <QFileInfo>
#include <qfileinfo.h>
#include <qgridlayout.h>
#include <qicon.h>
#include <QObject>
#include <QDir>
#include <QFileIconProvider>
#include <iostream>
#include <QWidget>
#include <qurl.h>
#include <qwidget.h>
#include <QDesktopServices>
#include <QFileIconProvider>
#include "LinuxThumbnailProviderService.h"

DirectoryViewWidget::DirectoryViewWidget(QWidget *parent)
{
    ui.setupUi(this);

    // Replace layout
    delete layout();
    FlowLayout *directoryViewLayout = new FlowLayout;
    setLayout(directoryViewLayout);

    // TODO: Remove - Temporary implementation testing
    thumbnailProviderService = new LinuxThumbnailProviderService();
}

void DirectoryViewWidget::displayDirectory(QString path)
{
    QDir currentDirectory = QDir(path);
    if(!currentDirectory.exists())
    {
        std::cerr<<"Failed to open directory! Path:"<<path.toStdString()<<std::endl;
        return;
    }
    currentDirectory.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);

    // Clear previous elements
    QLayoutItem* item;
    while ((item = layout()->takeAt(0)) != nullptr) {
        if(QWidget *widget = item->widget()) {
            widget->setParent(nullptr);
            delete widget;
        }
        delete item;
    }

    // TODO: Make width be proportional to window size
    int colIndex = 0;
    int rowIndex = 0;

    const int maxColumns = 3;
    
    for(QFileInfo entry : currentDirectory.entryInfoList())
    {
        FileSystemItemWidget *itemWidget = nullptr;

        if(entry.isFile())
        {
            itemWidget = new FileItemWidget();
        }
        else if(entry.isDir())
        {
            itemWidget = new DirectoryItemWidget();
        }

        if(itemWidget == nullptr)
        {
            std::cerr<<"Failed to create widget for file named "<<entry.fileName().toStdString()<<std::endl;
            continue;
        }

        if(entry.isDir())
        {
            connect(itemWidget, &FileSystemItemWidget::primaryInteraction, this, [this](QFileInfo info) {
                emit directoryOpened(info.filePath());
            });
        }
        else if(entry.isFile())
        {
            connect(itemWidget, &FileSystemItemWidget::primaryInteraction, this, [this](QFileInfo info) {
                QDesktopServices::openUrl(QUrl::fromLocalFile(info.absoluteFilePath()));
            });
        }

        itemWidget->setFileInfo(entry);
        QPixmap thumbnailImage = thumbnailProviderService->getThumbnailForFile(entry.absoluteFilePath());

        if(!thumbnailImage.isNull())
        {
            itemWidget->setThumbnail(thumbnailImage);
        }
        else
        {
            // Thumbnail image retrieval failed, resort to system default
            QFileIconProvider iconProvider;
            itemWidget->setThumbnail(iconProvider.icon(entry).pixmap(128, 128));
        }
        // Reasonable size, so thumbnails are visible
        itemWidget->setFixedWidth(256);
        itemWidget->setFixedHeight(256);
        layout()->addWidget(itemWidget);

        colIndex++;
        if(colIndex == maxColumns)
        {
            colIndex = 0;
            rowIndex++;
        }
    }
}