#ifndef __FILESYSTEMENTRYICON_H__
#define __FILESYSTEMENTRYICON_H__

#include <vector>
class FileSystemEntryIcon
{
public:
    virtual std::vector<unsigned char *> getIconImageData() = 0;
};

#endif // __FILESYSTEMENTRYICON_H__
