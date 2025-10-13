#ifndef __QUICKDIRECTORYACCESSWIDGET_H__
#define __QUICKDIRECTORYACCESSWIDGET_H__

#include "QuickDirAccessEntryWidget.h"
#include <QWidget>
#include <qboxlayout.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include <ui_QuickDirectoryAccessWidget.h>

class QuickDirectoryAccessWidget : public QWidget
{
    Q_OBJECT
private:
    Ui::QuickDirectoryAccessWidget ui;
    std::list<QuickDirAccessEntryWidget *> entries;
public:
    explicit QuickDirectoryAccessWidget(QWidget *parent = nullptr);

    void addEntry(QString path);
    void removeEntry(QString path);
};

#endif // __QUICKDIRECTORYACCESSWIDGET_H__
