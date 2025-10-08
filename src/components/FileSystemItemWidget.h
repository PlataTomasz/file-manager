#ifndef __FILESYSTEMITEMWIDGET_H__
#define __FILESYSTEMITEMWIDGET_H__

#include <QFileInfo>
#include <deque>
#include <qfileinfo.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <queue>
#include <qwidget.h>
#include <stack>
#include "ui_FileSystemItemWidget.h"

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
    void primaryInteraction(QFileInfo fileInfo);
public:
    explicit FileSystemItemWidget(QWidget *parent = nullptr);

    void setFileInfo(QFileInfo fileInfo);
};

#endif // __FILESYSTEMITEMWIDGET_H__
