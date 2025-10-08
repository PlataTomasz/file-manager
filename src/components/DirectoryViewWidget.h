#ifndef __DIRECTORYVIEWWIDGET_H__
#define __DIRECTORYVIEWWIDGET_H__

#include <qcontainerfwd.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include "ui_DirectoryView.h"

class DirectoryViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DirectoryViewWidget(QWidget *parent = nullptr);
    // Populates content based on currently browsed directory
    void displayDirectory(QString path);
    void setCurrentDirectoryPath(QString currentDirPath);
signals:
    void currentDirectoryChangeRequest(QString newCurrentDirectory);

private:
    Ui::DirectoryView ui;
};

#endif // __DIRECTORYVIEWWIDGET_H__
