#ifndef __CONTEXTMENUPROVIDERSERVICE_H__
#define __CONTEXTMENUPROVIDERSERVICE_H__

#include <qmenu.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qwidget.h>

/**
Class responsible for providing context menu based on context
*/
class ContextMenuProviderService : public QObject
{
    Q_OBJECT
public:
    /**
    @param data Allows to determine what kind of context menu should be created
    @param actions List of actions, which should appear in the menu. These action might be disabled. Each action contains name and behaviour to be invoked.
    @returns New QMenu instance to be displayed as context menu
    */
    QMenu *createContextMenu();
};

#endif // __CONTEXTMENUPROVIDERSERVICE_H__
