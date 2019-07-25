#include "stdafx.h"
#include "stringPath.h"
#include "convert2TXT.h"

void excute(const char * path, const char * pbuffer)
{
    SHELLEXECUTEINFO ShExecInfo = {0};
    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    ShExecInfo.hwnd = NULL;
    ShExecInfo.lpVerb = "open";//多种类别有 "explorer" "print" 等
    ShExecInfo.lpFile = path;//exe 路径    
    ShExecInfo.lpParameters = pbuffer;//参数
    ShExecInfo.lpDirectory = NULL;
    ShExecInfo.nShow = SW_HIDE;//
    ShExecInfo.hInstApp = NULL;
    ShellExecuteEx(&ShExecInfo);

    WaitForSingleObject(ShExecInfo.hProcess, INFINITE);//等待完成 
}