#ifndef __DIRECTORYVIEWWIDGET_H__
#define __DIRECTORYVIEWWIDGET_H__

#include <qtmetamacros.h>
#include <qwidget.h>
#include "ui_DirectoryView.h"

class DirectoryViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DirectoryViewWidget(QWidget *parent = nullptr);
    // Populates content based on currently browsed directory
    void populateContent();
private:
    Ui::DirectoryView ui;
};

#endif // __DIRECTORYVIEWWIDGET_H__
