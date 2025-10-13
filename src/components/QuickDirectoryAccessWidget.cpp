#include "QuickDirectoryAccessWidget.h"
#include "QuickDirAccessEntryWidget.h"
#include <iostream>
#include <qboxlayout.h>
#include <QDir>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qwidget.h>
#include <QLayout>

QuickDirectoryAccessWidget::QuickDirectoryAccessWidget(QWidget *parent)
{
    ui.setupUi(this);

    ui.pathLayout->setAlignment(Qt::AlignTop);
}

void QuickDirectoryAccessWidget::addEntry(QString path)
{
    QuickDirAccessEntryWidget *widget = new QuickDirAccessEntryWidget(path);

    entries.push_back(widget);
    ui.pathLayout->addWidget(widget);

    connect(widget, &QuickDirAccessEntryWidget::doubleClicked, this, [this, widget]() {
        emit directoryOpened(widget->getPath());
    } );
}

void QuickDirectoryAccessWidget::removeEntry(QString path)
{
    // Regular O(n) search
    QuickDirAccessEntryWidget *foundWidget = nullptr;
    for(auto currentIter = entries.begin(); currentIter != entries.end() && !foundWidget; currentIter++)
    {
        QuickDirAccessEntryWidget *potentialWidget = (*currentIter);
        if(potentialWidget->getPath() == path)
        {
            foundWidget = potentialWidget;
        }
    }

    if(foundWidget == nullptr)
    {
        std::cerr<<"No entry found for path: "<<path.toStdString()<<std::endl;
    }
    else
    {
        ui.pathLayout->removeWidget(foundWidget);
    }
}
