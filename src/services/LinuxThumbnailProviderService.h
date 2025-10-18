#ifndef __LINUXTHUMBNAILPROVIDERSERVICE_H__
#define __LINUXTHUMBNAILPROVIDERSERVICE_H__

#include "ThumbnailProviderService.h"
#include <qcontainerfwd.h>
#include <QPixmap>
#include <QFileInfo>
#include <QCryptographicHash>
#include <QDir>
#include <qfileinfo.h>
#include <qpixmap.h>

/**
Class which implements ThumbnailProviderService for Linux based platforms
*/
class LinuxThumbnailProviderService : public ThumbnailProviderService
{
public:
    QString getThumbnailPathForFile(QString filePath, int width = 128, int height = 128) override
    {
        // Compute FreeDesktop cache path
        QByteArray uri = ("file://" + QFileInfo(filePath).absoluteFilePath()).toUtf8();
        QByteArray hash = QCryptographicHash::hash(uri, QCryptographicHash::Md5).toHex();
        QString cachePath = QDir::homePath() + "/.cache/thumbnails/normal/" + QString(hash) + ".png";

        if(QFile::exists(cachePath)) return cachePath;

        // Generate thumbnail for images
        QPixmap pix(filePath);
        if (pix.isNull()) return QString();
        QPixmap scaled = pix.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        // Save thumbnail
        scaled.save(cachePath, "PNG");

        return cachePath;
    }

    QPixmap getThumbnailForFile(QString filePath, int width = 128, int height = 128) override
    {
        // Compute FreeDesktop cache path
        QByteArray uri = ("file://" + QFileInfo(filePath).absoluteFilePath()).toUtf8();
        QByteArray hash = QCryptographicHash::hash(uri, QCryptographicHash::Md5).toHex();
        QString cachePath = QDir::homePath() + "/.cache/thumbnails/normal/" + QString(hash) + ".png";

        if(QFile::exists(cachePath)) return QPixmap(cachePath);
        
        // Generate thumbnail for images
        QPixmap pix(filePath);
        if (pix.isNull()) return QPixmap();
        QPixmap scaled = pix.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        // Save thumbnail
        scaled.save(cachePath, "PNG");

        return scaled;
    }
};

#endif // __LINUXTHUMBNAILPROVIDERSERVICE_H__
