#ifndef __QUICKDIRACCESSENTRYWIDGET_H__
#define __QUICKDIRACCESSENTRYWIDGET_H__

#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include <QLabel>

/**
Represents entry on the quick access widget. Containing an absolute path.
*/
class QuickDirAccessEntryWidget : public QWidget
{
    Q_OBJECT
private:
    /**
    Stores current path, which is displayed on widget and where it should lead after double clicking.
    */
    QString path;
    QLabel *label = nullptr;
    QGridLayout *layout = nullptr;
    QWidget *widget = nullptr;
protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
signals:
    /**
    Informs that this entry was double clicked.
    */
    void doubleClicked();
public:
    explicit QuickDirAccessEntryWidget(QWidget *parent = nullptr);
    explicit QuickDirAccessEntryWidget(QString path, QWidget *parent = nullptr);

    /**
    @param path New path to be set.
    */
    void setPath(QString path);
    /**
    @return path
    */    
    QString getPath();
};

#endif // __QUICKDIRACCESSENTRYWIDGET_H__
