
#include "DirectoryNavigationService.h"
#include "MainWindow.h"
#include <qapplication.h>
#include <qdir.h>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

#if defined(Q_OS_UNIX)
    QDir defaultDirectory = QDir("/home");
#elif defined(Q_OS_WIN)
    QDir defaultDirectory = QDir("C:/Users");
#endif
    auto mainWindow = new MainWindow(
        new DirectoryNavigationService(
            defaultDirectory.absolutePath()
        )
    );
    mainWindow->show();

    return app.exec();
}