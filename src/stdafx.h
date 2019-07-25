#pragma once


#include<vector>
#include<string>
//#include <sstream>
#include <windows.h>

#define OCR_PROOF_LIBDLL
//#define CompareFileAPI
#ifdef OCR_PROOF_LIBDLL
#define OCR_PROOF_LIBDLL _declspec(dllexport)
#else
#define OCR_PROOF_LIBDLL  _declspec(dllimport)
#endif
