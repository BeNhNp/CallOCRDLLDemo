#include "stdafx.h"
#include "convert2TXT.h"
#include "proofreadDoc.h"
#include "ocrWrapper4C.h"
int main()
{
    OCRProof_Init();
    void* p = OCRProof_NewInstance("E:\\tmp\\proof_out", "E:\\tmp\\tesseract");
    std::vector<std::string> imagesPath = {
        "E:\\tmp\\proof_in\\img\\test_Page_1.jpg",
        "E:\\tmp\\proof_in/img\\test_Page_2.jpg",
	    "E:\\tmp\\proof_in\\img\\test_Page_3.jpg",
	};
    //char *outDir = "E:\\tmp\\proof_out";
    for(auto path : imagesPath)
    {
        printf("%s 开始处理\n", path.c_str());
        if(!OCRProof_convert2TXT(p, path.c_str()))
            printf("%s OCR失败\n", path.c_str());
    }

    OCRProof_Combine(p, "E:\\tmp\\proof_out\\test_Page.txt", 0);
    OCRProof_Exit(p);
    return 0;
}