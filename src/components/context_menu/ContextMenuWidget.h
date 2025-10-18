#ifndef __CONTEXTMENUWIDGET_H__
#define __CONTEXTMENUWIDGET_H__

#include <qmenu.h>
#include <qtmetamacros.h>
#include <qwidget.h>


class ContextMenuWidget : public QMenu
{
    Q_OBJECT
private:
    void *commands;
public:
    template<typename T>
    explicit ContextMenuWidget(const T& collection)
    {
        for(auto item : collection)
        {
            
        }
    }
};

#endif // __CONTEXTMENUWIDGET_H__
