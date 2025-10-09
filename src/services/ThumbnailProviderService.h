#ifndef __THUMBNAILPROVIDERSERVICE_H__
#define __THUMBNAILPROVIDERSERVICE_H__

#include <QString>
#include <QPixmap>

class ThumbnailProviderService
{
public:
    // Generates or returns existing thumbnail path for given file
    virtual QString getThumbnailPathForFile(QString filePath, int width = 128, int height = 128) = 0;
    // Generates or returns existing thumbnail for given file
    virtual QPixmap getThumbnailForFile(QString filePath, int width = 128, int height = 128) = 0;
};

#endif // __THUMBNAILPROVIDERSERVICE_H__
