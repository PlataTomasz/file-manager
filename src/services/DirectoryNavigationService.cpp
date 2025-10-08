#include "DirectoryNavigationService.h"
#include <qobject.h>

DirectoryNavigationService::DirectoryNavigationService(QObject *parent)
{

}

void DirectoryNavigationService::changeCurrentDirectory(QString path)
{
    previousPaths.push(currentDirectoryPath);
    currentDirectoryPath = path;
    emit currentDirectoryChanged(path);
}

void DirectoryNavigationService::returnToPreviousDirectory()
{
    if(!previousPaths.empty())
    {
        QString path = previousPaths.top();
        previousPaths.pop();

        currentDirectoryPath = path;
        emit currentDirectoryChanged(path);
    }
}

void DirectoryNavigationService::setInitialPath(QString path)
{
    currentDirectoryPath = path;
    emit currentDirectoryChanged(path);
}