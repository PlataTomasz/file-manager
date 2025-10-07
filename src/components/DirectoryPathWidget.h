#ifndef __DIRECTORYPATHWIDGET_H__
#define __DIRECTORYPATHWIDGET_H__


#include <qobject.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include "ui_DirectoryPathWidget.h"

// Widget representing path string in file manager along It's controls
class DirectoryPathWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DirectoryPathWidget(QWidget *parent = nullptr);
    void onValidPathPrompt(QString path);
signals:
    void validPathPrompt(QString path);
private:
    Ui::DirectoryPathWidget ui;
};

#endif // __DIRECTORYPATHWIDGET_H__
