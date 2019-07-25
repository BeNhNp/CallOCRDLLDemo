#ifndef _PROOFREAD_H
#define _PROOFREAD_H

#include "stdafx.h"

class OCRProof
{
    std::vector<std::string> output;
public:
    //OCRProof(){}
    std::string dir;
    std::string exePath;
    std::string finalPath;
    bool parseImage2TXT(const char* path);
    bool combineAll(const char * path, bool isRemove);
};

#endif // !_PROOFREAD_H
