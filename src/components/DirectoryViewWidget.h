#ifndef __DIRECTORYVIEWWIDGET_H__
#define __DIRECTORYVIEWWIDGET_H__

#include <qcontainerfwd.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include "ThumbnailProviderService.h"
#include "ui_DirectoryView.h"

/**
Class responsible for displaying files and directories inside a specified directory.
*/
class DirectoryViewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DirectoryViewWidget(QWidget *parent = nullptr);
    /**
    Displays files and directories inside widget.
    @param path Path to directory, which contents should be displayed in this widget. Can be either relative or absolute.
    */
    void displayDirectory(QString path);
signals:
    /**
    Informs that specified directory wants to be opened.
    @param path Absolute path to directory, which wants to be opened.
    */
    void directoryOpened(QString path);
private:
    ThumbnailProviderService *thumbnailProviderService = nullptr;
    Ui::DirectoryView ui;
};

#endif // __DIRECTORYVIEWWIDGET_H__
