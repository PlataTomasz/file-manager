#ifndef __DIRECTORYITEMWIDGET_H__
#define __DIRECTORYITEMWIDGET_H__

#include "DirectoryItem.h"
#include <qtmetamacros.h>
#include <qwidget.h>

class DirectoryItemWidget : public QWidget
{
    Q_OBJECT
private:
    DirectoryItem item;
private slots:
    void onLeftClick();
    void onRightClick();
public:
    DirectoryItemWidget(QWidget *widget = nullptr);
};

#endif // __DIRECTORYITEMWIDGET_H__
