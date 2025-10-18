#ifndef __QUICKDIRECTORYACCESSWIDGET_H__
#define __QUICKDIRECTORYACCESSWIDGET_H__

#include "QuickDirAccessEntryWidget.h"
#include <QWidget>
#include <qboxlayout.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include <ui_QuickDirectoryAccessWidget.h>

/**
Widget, which displays quick access directories. Visually It's a list of common directories. Each can be clicked to move instantly to that directory. 
*/
class QuickDirectoryAccessWidget : public QWidget
{
    Q_OBJECT
private:
    Ui::QuickDirectoryAccessWidget ui;
    std::list<QuickDirAccessEntryWidget *> entries;
signals:
    /**
    Informs that one of the directories from widget wants to be opened.
    @param string Absolute path of directory that wants to be opened
    */
    void directoryOpened(QString string);
public:
    explicit QuickDirectoryAccessWidget(QWidget *parent = nullptr);

    /**
    Adds new entry to the list of directories.
    @param path Absolute path to entry.
    */
    void addEntry(QString path);
    /**
    Removes first entry with matching path from the list of directories.
    @param path Path to directory, that needs to be removed from widget. Can be either relative or absolute.
    */
    void removeEntry(QString path);
};

#endif // __QUICKDIRECTORYACCESSWIDGET_H__
