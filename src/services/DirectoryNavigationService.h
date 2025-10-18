#ifndef __DIRECTORYNAVIGATIONSERVICE_H__
#define __DIRECTORYNAVIGATIONSERVICE_H__

#include <qobject.h>
#include <qtmetamacros.h>
#include <QObject>
#include <stack>
#include <string_view>

/**
Provides common operations related to changing directory which is currently browsed. Other objects can listen to events of this servic to react to changes of current directory.
*/
class DirectoryNavigationService : public QObject
{
    Q_OBJECT
private:
    QString currentDirectoryPath;
    std::stack<QString> previousPaths;
signals:
    /**
    Informs, that current directory has changed.
    @param path Absolute path to current directory.
    */
    void currentDirectoryChanged(QString path);
public:
    /**
    Creates new instance, setting initial directory to passed one.
    @param startingPath Path, which the service considers as initial. Can be either relative or absolute.
    @param parent Parent of this object.
     */
    explicit DirectoryNavigationService(QString startingPath, QObject *parent = nullptr);

    /**
    Requests a change of a current directory, emiting currentDirectoryChanged signal.
    @param path The path to directory. Can be either relative or absolute.
     */
    void changeCurrentDirectory(QString path);
    /**
    Changes current directory to previously visited one. If no directory was visited before, then this method fails silently, keeping current directory.
     */
    void returnToPreviousDirectory();
    /**
    Sets initial path of directory manager, clearing all previously visited directories.
    Emits currentDirectoryChanged signal.
    @param path Initial directory path. Can be either relative or absolute.
     */
    void setInitialPath(QString path);
};

#endif // __DIRECTORYNAVIGATIONSERVICE_H__
