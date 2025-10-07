#ifndef __FILEMANAGERSERVICE_H__
#define __FILEMANAGERSERVICE_H__

#include <string_view>
#include <vector>
#include "DirectoryItem.h"
#include "FileItem.h"

class FileManagerService
{
public:
    std::vector<FileItem> getAllFilesInDirectory();
    std::vector<DirectoryItem> getAllDirectoriesInDirectory();

    FileManagerService(std::string_view path);
};

#endif // __FILEMANAGERSERVICE_H__
