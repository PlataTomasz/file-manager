#include "DirectoryViewWidget.h"

DirectoryViewWidget::DirectoryViewWidget(QWidget *parent)
{
    ui.setupUi(this);
}

void DirectoryViewWidget::populateContent()
{
    // TODO: Make width be proportional to window size
    int colIndex = 0;
    int rowIndex = 0;

    const int maxColumns = 3;
    /*
    for(ImageItem imageItem : imageItems)
    {
        auto imageItemWidget = new ImageItemWidget();
        QPixmap pixmap;
        bool isImageDataOk = pixmap.loadFromData(imageItem.data.data(), imageItem.data.size());
        if(isImageDataOk)
        {
            imageItemWidget->setImage(pixmap);
        }
        
        imageItemWidget->setLabel(imageItem.name.c_str());
        ui.imageArea->addWidget(imageItemWidget, rowIndex, colIndex);

        colIndex++;
        if(colIndex == maxColumns)
        {
            colIndex = 0;
            rowIndex++;
        }
    }
    */
}