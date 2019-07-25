#pragma once
#include <string>
#include<io.h>

class sPath
{
    std::string fullpath;
    std::string name;
    std::string ext;
    std::string dir;
    char dim;
public:
    sPath()
    {

    }
    sPath(const std::string& path)
    {
        fullpath = path;
        dim = 0;
        int i;
        for(i = (int)fullpath.size() - 1; i >= 0; i--)
        {
            if(fullpath[i] == '/' || fullpath[i] == '\\')
            {
                dim = fullpath[i];
                break;
            }
        }
        if(dim)
        {
            dir = fullpath.substr(0, i);
            name = fullpath.substr(i + 1, fullpath.find_last_of('.') - i - 1);
        }
        i = fullpath.find_last_of('.');
        if(i != std::string::npos)
            ext = fullpath.substr(i+1);

    }
    sPath(const char * dir, const char* name, const char *ext):dir(dir),name(name),ext(ext)
    {
        if(!this->dir.empty())
        {
            dim = *this->dir.rbegin();
            if(dim != '/'&&dim != '\\')
                dim = '/';
            else
                this->dir.resize(this->dir.size() - 1);
        }
        fullpath = this->dir + dim + this->name + '.' + ext;
    }
    std::string getname()
    {
        return name;
    }
    std::string getFullName()
    {
        return name + '.' + ext;
    }
    void setname(const char *name)
    {
        this->name = name;
        fullpath = dir + dim + name + '.' + ext;
    }
    void setdir(const char *dir)
    {
        this->dir = dir;
        fullpath = dir + dim + name + '.' + ext;
    }
    std::string getext()
    {
        return ext;
    }
    std::string getdir()
    {
        return dir;
    }
    bool isExist()
    {
        if(_access(fullpath.c_str(), 0) == -1)
            return false;
        return true;
    }
    const char* c_str()
    {
        return fullpath.c_str();
    }
    sPath& operator=(const sPath& path)
    {
        fullpath = path.fullpath;
        name = path.name;
        ext = path.ext;
        dir = path.dir;
        dim = path.dim;
        return *this;
    }
};

