#ifndef __FILESYSTEMITEMWIDGET_H__
#define __FILESYSTEMITEMWIDGET_H__

#include <QFileInfo>
#include <deque>
#include <qfileinfo.h>
#include <qobject.h>
#include <qpixmap.h>
#include <qtmetamacros.h>
#include <queue>
#include <qwidget.h>
#include <stack>
#include "ui_FileSystemItemWidget.h"

/**
Represents entry in the filesystem. Used to display details in DirectoryViewWidget.
*/
class FileSystemItemWidget : public QWidget
{
    Q_OBJECT
protected:
    QFileInfo fileInfo;
    Ui::FileSystemItemWidget ui;
protected slots:
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
    virtual void onRightClick();
signals:
    /**
    Informs that user interacted with and expects this entry to be opened.
    @param fileInfo Information about file, which this widget is representing.
    */
    void primaryInteraction(QFileInfo fileInfo);
public:
    explicit FileSystemItemWidget(QWidget *parent = nullptr);
    /**
    @param fileInfo New fileInfo to be set.
    */
    void setFileInfo(QFileInfo fileInfo);
    /**
    @param thumbnailImage New thumbnail image for this entry.
    */
    void setThumbnail(QPixmap thumnailImage);
};

#endif // __FILESYSTEMITEMWIDGET_H__
