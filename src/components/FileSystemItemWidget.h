#ifndef __FILESYSTEMITEMWIDGET_H__
#define __FILESYSTEMITEMWIDGET_H__

#include <QFileInfo>
#include <qtmetamacros.h>
#include <qwidget.h>
#include "ui_FileSystemItemWidget.h"

class FileSystemItemWidget : public QWidget
{
    Q_OBJECT
protected:
    QFileInfo fileInfo;
    Ui::FileSystemItemWidget ui;

protected slots:
    virtual void onLeftClick();
    virtual void onRightClick();
public:
    explicit FileSystemItemWidget(QWidget *parent = nullptr);

    void setFileInfo(QFileInfo fileInfo);
};

#endif // __FILESYSTEMITEMWIDGET_H__
