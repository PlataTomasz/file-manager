#include "QuickDirAccessEntryWidget.h"
#include <QWidget>
#include <QDir>
#include <QGridLayout>
#include <QLabel>   
#include <qobject.h>
QuickDirAccessEntryWidget::QuickDirAccessEntryWidget(QWidget *parent)
{
    widget = new QWidget;
    layout = new QGridLayout;

    label = new QLabel;
    label->setText("");
    layout->addWidget(label);

    widget->setLayout(layout);
}

QuickDirAccessEntryWidget::QuickDirAccessEntryWidget(QString path, QWidget *parent) 
    : QuickDirAccessEntryWidget(parent)
{
    setPath(path);
}

void QuickDirAccessEntryWidget::setPath(QString path)
{
    this->path = path;
    label->setText(path);
}

QString QuickDirAccessEntryWidget::getPath()
{
    return path;
}