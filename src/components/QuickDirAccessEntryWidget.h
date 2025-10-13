#ifndef __QUICKDIRACCESSENTRYWIDGET_H__
#define __QUICKDIRACCESSENTRYWIDGET_H__

#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qwidget.h>
#include <QLabel>

class QuickDirAccessEntryWidget : public QWidget
{
    Q_OBJECT
private:
    QString path;
    QLabel *label = nullptr;
    QGridLayout *layout = nullptr;
    QWidget *widget = nullptr;
protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
signals:
    void doubleClicked();
public:
    explicit QuickDirAccessEntryWidget(QWidget *parent = nullptr);
    explicit QuickDirAccessEntryWidget(QString path, QWidget *parent = nullptr);

    void setPath(QString path);
    QString getPath();
};

#endif // __QUICKDIRACCESSENTRYWIDGET_H__
