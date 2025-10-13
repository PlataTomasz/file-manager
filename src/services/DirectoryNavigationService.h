#ifndef __DIRECTORYNAVIGATIONSERVICE_H__
#define __DIRECTORYNAVIGATIONSERVICE_H__

#include <qobject.h>
#include <qtmetamacros.h>
#include <QObject>
#include <stack>
#include <string_view>
class DirectoryNavigationService : public QObject
{
    Q_OBJECT
private:
    QString currentDirectoryPath;
    std::stack<QString> previousPaths;
signals:
    void currentDirectoryChanged(QString path);
public:
    explicit DirectoryNavigationService(QString startingPath, QObject *parent = nullptr);

    void changeCurrentDirectory(QString path);
    void returnToPreviousDirectory();
    void setInitialPath(QString path);
};

#endif // __DIRECTORYNAVIGATIONSERVICE_H__
