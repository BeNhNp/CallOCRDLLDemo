#include "stdafx.h"
#include "stringPath.h"
#include "convert2TXT.h"
#include "proofreadDoc.h"

bool OCRProof::parseImage2TXT(const char * path)
{
    std::stringstream s;
    sPath f(path);
    sPath res(this->dir.c_str(), f.getname().c_str(), "txt");
    
    bool flag = res.isExist();
    if(flag)
    {
        this->output.push_back(res.c_str());
        return flag;
    }
    std::string out;
    if(this->dir.empty())
        out = f.getdir();
    else
    {
        out = dir;
        char ch = out[out.size() - 1];
        if(ch == '\\' || ch == '/')
            out = out.substr(0, out.size() - 1);
    }
    s << "\"" << path << "\" \"" << out << '\\' << f.getname() << '\"' << " --tessdata-dir \"" << this->exePath << "\" -l tessdata/chi_sim";

    sPath exe(this->exePath.c_str(), "tesseract", "exe");

    if(!exe.isExist())
        return false;
    excute(exe.c_str(), s.str().c_str());

    flag = res.isExist();
    if(flag)
        this->output.push_back(res.c_str());
    return flag;
}
#include <fstream>
#include <codecvt>
bool OCRProof::combineAll(const char * path, bool isRemove)
{
    std::wofstream ofs(path);
	ofs.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

    //std::ifstream ifile;
    std::wifstream ifs;
    ifs.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
    typedef std::istreambuf_iterator<wchar_t> iter_type;
	iter_type end;
    iter_type begin;

    std::wstring data;
    wchar_t ch;
    for(auto& i : output)
    {
        ifs.open(i);
        begin = ifs;
	    if (*begin == 0xfeff)
		    ++begin;// ++ to skip the BOM
        //data.assign(begin, end);
        for(;begin != end;begin++)
        {
            if(iswspace(*begin))
                continue;
            data += *begin;
            break;
        }
        for(;begin != end;begin++)
        {
            ch = *data.rbegin();
            if(*begin == '\n')
            {
                if(ch == '\n')
                    continue;
            }
            else if(iswspace(*begin))
                if(ch <'A'|| 'Z' < ch&& ch < 'a'|| 'z' < ch )
                    continue;
            data += *begin;
        }
        ofs << data;
        ifs.close();
        data.clear();
        if(isRemove)
        {
            remove(i.c_str());
        }
    }
    ofs.close();
    return true;
}
