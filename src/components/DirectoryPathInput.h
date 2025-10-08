#ifndef __DIRECTORYPATHINPUT_H__
#define __DIRECTORYPATHINPUT_H__

#include <qlineedit.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qwidget.h>

class DirectoryPathInput : public QLineEdit
{
    Q_OBJECT
public:
    explicit DirectoryPathInput(QWidget *parent = nullptr);

    QString getCurrentDirectoryPath();
    void setCurrentDirectoryPath(QString currentDirPath);
signals:
    // User prompted a valid directory path
    void validDirectoryPathPrompted(QString path);
    // User prompted an invalid directory path - i.e. non-existant one
    void invalidDirectoryPathPrompted(QString path);
protected:
    
private:
    QString currentDirectoryPath;
    void onSubmit();
};

#endif // __DIRECTORYPATHINPUT_H__
