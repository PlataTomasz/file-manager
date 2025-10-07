#ifndef __FILEITEM_H__
#define __FILEITEM_H__

#include "FileSystemEntryInfo.h"
#include <string_view>

class FileItem
{
private:
    FileSystemEntryInfo entry;
public:
    explicit FileItem(std::string_view name);
};

#endif // __FILEITEM_H__
