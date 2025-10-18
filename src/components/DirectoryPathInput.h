#ifndef __DIRECTORYPATHINPUT_H__
#define __DIRECTORYPATHINPUT_H__

#include <qlineedit.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qwidget.h>

/**
Represents address bar. Allows for manual input of target path or copying of the current one. 
*/
class DirectoryPathInput : public QLineEdit
{
    Q_OBJECT
public:
    explicit DirectoryPathInput(QWidget *parent = nullptr);
    /**
    @returns Current directory absolute path, which is visible in this widget.
    */
    QString getCurrentDirectoryPath();
    /**
    Changes current directory path visible in this widget.
    @param currentDirPath 
    */
    void setCurrentDirectoryPath(QString currentDirPath);
signals:
    /**
    Informs that user prompted a valid directory path.
    @param path Path that used prompted
    */
    void validDirectoryPathPrompted(QString path);
    /**
    Informs that user prompted an invalid directory path - i.e. non-existant one
    @param path Path that used prompted
    */
    void invalidDirectoryPathPrompted(QString path);
protected:
    
private:
    QString currentDirectoryPath;
    void onSubmit();
};

#endif // __DIRECTORYPATHINPUT_H__
