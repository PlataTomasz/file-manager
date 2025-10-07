#ifndef __FILESYSTEMENTRYICONQT_H__
#define __FILESYSTEMENTRYICONQT_H__

#include "FileSystemEntryIcon.h"
#include <vector>

// For Qt based desktop environments
class FileSystemEntryIconQt : public FileSystemEntryIcon
{
    virtual std::vector<unsigned char *> getIconImageData() override;
};

#endif // __FILESYSTEMENTRYICONQT_H__
