#ifndef __FILEITEMWIDGET_H__
#define __FILEITEMWIDGET_H__

#include "FileItem.h"
#include <qtmetamacros.h>
#include <qwidget.h>

class FileItemWidget : public QWidget
{
    Q_OBJECT
private:
    FileItem item;
private slots:
    void onLeftClick();
    void onRightClick();
public:
    FileItemWidget(QWidget *parent = nullptr);
};

#endif // __FILEITEMWIDGET_H__
