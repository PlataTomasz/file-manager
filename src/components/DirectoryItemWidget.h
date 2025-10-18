#ifndef __DIRECTORYITEMWIDGET_H__
#define __DIRECTORYITEMWIDGET_H__

#include "DirectoryItem.h"
#include "FileSystemItemWidget.h"
#include <qtmetamacros.h>
#include <qwidget.h>

class DirectoryItemWidget : public FileSystemItemWidget
{
    Q_OBJECT
public:
    explicit DirectoryItemWidget(QWidget *widget = nullptr);
};

#endif // __DIRECTORYITEMWIDGET_H__
