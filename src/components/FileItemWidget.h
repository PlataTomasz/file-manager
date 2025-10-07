#ifndef __FILEITEMWIDGET_H__
#define __FILEITEMWIDGET_H__

#include "FileItem.h"
#include "FileSystemItemWidget.h"
#include <qtmetamacros.h>
#include <qwidget.h>

class FileItemWidget : public FileSystemItemWidget
{
    Q_OBJECT
protected:
    virtual void onRightClick() override;
public:
    explicit FileItemWidget(QWidget *parent = nullptr);
};

#endif // __FILEITEMWIDGET_H__
