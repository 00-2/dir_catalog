//
// Created by c0sta on 02.06.2022.
//

#include "Directory.h"
Directory::Directory()
{
    this->count = 0;
    this->path = "";
};
Directory::Directory(std::string path)
{
    this->count = 1;
    this->path = path;
};
Directory::~Directory()
{
    this->dirs.clear();
    this->files.clear();
};

void Directory::add(File *pF) {
    this->files.push_back(*pF);
}
void Directory::remove(File *pF) {
    this->files.remove(*pF);
}
void Directory::add(Directory *pD) {
    this->dirs.push_back(*pD);
}
void Directory::remove(Directory *pD) {
    this->dirs.remove(*pD);
}
void Directory::move(Directory *pD) {
    this->dirs.push_back(*pD);
}
Directory& operator+(Directory &D, File &F){
    D.add(&F);
    return D;
}
Directory& operator+(Directory &D_source, Directory &D_dest){
    D_source.add(&D_dest);
    return D_source;
}

