#ifndef _OCR_WRAPPER_H
#define _OCR_WRAPPER_H

/*********************************************************************
*
*  Func Name  : OCRProof_init
*
*  Description: Init 
*               The function must be invoked before any operation listed as following
*
*  Parameters :
*  Returns    : always return 1
*  History    :
*              1.create 2019-07-25
*********************************************************************/
extern "C" OCR_PROOF_LIBDLL int OCRProof_Init() 
{
    return 1;
}
/*********************************************************************
*
*  Func Name  : OCRProof_NewInstance
*
*  Description: New a  OCR proofread Instance
*
*  Parameters : outputDir: the output dir
*               exeDir   : the tesseract dir 
*  Returns    : OCR_PROOF: OCR Handle if success; otherwise return -1;
*  History    :
*              1.create 2019-07-25
*********************************************************************/
typedef void* OCRProof_Handle
extern "C" OCR_PROOF_LIBDLL OCRProof_Handle OCRProof_NewInstance(const char* outputDir, const char* exeDir) 
{
    OCRProof *pOCRProof = new OCRProof();
    if(!pOCRProof)
        return -1;
    pOCRProof->dir = outputDir;
    pOCRProof->exePath = exePath;
    return pOCRProof;
}
extern "C" OCR_PROOF_LIBDLL void OCRProof_Exit(OCRProof_Handle pOCRProof)
{
    if(pOCRProof)
        delete (OCRProof *)pOCRProof; 
}

extern "C" OCR_PROOF_LIBDLL void OCRProof_setConvertexeDir(OCRProof_Handle pOCRProof, const char* filePath)
{
    if(!pOCRProof)
        return;
    ((OCRProof *)pOCRProof)->exePath = filePath;
}

extern "C" OCR_PROOF_LIBDLL void OCRProof_setOutputDir(OCRProof_Handle pOCRProof, const char* filePath)
{
    if(!pOCRProof)
        return;
    ((OCRProof *)pOCRProof)->dir = filePath;
}


/*********************************************************************
*
*  Func Name  : OCRProof_convert2TXT
*
*  Description: Convert a image file to txt
*
*  Parameters : pOCRProof: pointer to OCR object
*  Returns    : KGB_HANDLE: KeyScan Handle if success; otherwise return -1;
*  History    :
*              1.create 2019-07-25
*********************************************************************/
extern "C" OCR_PROOF_LIBDLL int OCRProof_convert2TXT(OCRProof_Handle pOCRProof, const char* filePath)
{
    if(!pOCRProof)
        return 0;

    return ((OCRProof *)pOCRProof)->parseImage2TXT(filePath);
}
extern "C" OCR_PROOF_LIBDLL void OCRProof_Combine(OCRProof_Handle pOCRProof, const char * path, bool isRemove)
{
    if(!pOCRProof)
        return;
    ((OCRProof *)pOCRProof)->combineAll(path, isRemove);
}


#endif // !_OCR_WRAPPER_H
