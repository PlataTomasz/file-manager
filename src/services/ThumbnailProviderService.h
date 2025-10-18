#ifndef __THUMBNAILPROVIDERSERVICE_H__
#define __THUMBNAILPROVIDERSERVICE_H__

#include <QString>
#include <QPixmap>

/**
Class, which provides a common interface for retrieving and generating thumbnail icons.
 */
class ThumbnailProviderService
{
public:
    /**
    Generates and/or returns existing thumbnail path for given file
    @param filePath Path to file, for which thumbnail should be retrieved
    @param width Width of the thumbnail
    @param height Height of the thumbnail
    @returns QString which contains thumbnail image absolute path
    */
    virtual QString getThumbnailPathForFile(QString filePath, int width = 128, int height = 128) = 0;
    /**
    Generates and/or returns existing thumbnail for given file
    @param filePath Path to file, for which thumbnail should be retrieved
    @param width Width of the thumbnail
    @param height Height of the thumbnail
    @returns QPixmap which contains thumbnail image data
    */
    virtual QPixmap getThumbnailForFile(QString filePath, int width = 128, int height = 128) = 0;
};

#endif // __THUMBNAILPROVIDERSERVICE_H__
