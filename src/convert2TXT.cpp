#include "stdafx.h"
#include "stringPath.h"
#include "convert2TXT.h"

void excute(const char * path, const char * pbuffer)
{
    SHELLEXECUTEINFO ShExecInfo = {0};
    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    ShExecInfo.hwnd = NULL;
    ShExecInfo.lpVerb = "open";//��������� "explorer" "print" ��
    ShExecInfo.lpFile = path;//exe ·��    
    ShExecInfo.lpParameters = pbuffer;//����
    ShExecInfo.lpDirectory = NULL;
    ShExecInfo.nShow = SW_HIDE;//
    ShExecInfo.hInstApp = NULL;
    ShellExecuteEx(&ShExecInfo);

    WaitForSingleObject(ShExecInfo.hProcess, INFINITE);//�ȴ���� 
}