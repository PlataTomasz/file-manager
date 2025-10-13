#include "QuickDirAccessEntryWidget.h"
#include <QWidget>
#include <QDir>
#include <QGridLayout>
#include <QLabel>   
#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qobject.h>

#include <iostream>
#include <qsizepolicy.h>

QuickDirAccessEntryWidget::QuickDirAccessEntryWidget(QWidget *parent)
{
    layout = new QGridLayout;

    label = new QLabel;
    label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    label->setText("NULL");
    layout->addWidget(label);

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

    setLayout(layout);
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