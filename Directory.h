//
// Created by c0sta on 02.06.2022.
//

#ifndef REWRITE_DIR_CATALOG_DIRECTORY_H
#define REWRITE_DIR_CATALOG_DIRECTORY_H


#include <cstddef>
#include <string>
#include <list>
#include "File.h"

enum DirectoryType{
    dir,
    archive,
    archive_with_pwd

};

class Directory {
    size_t count;
    std::string path;
    DirectoryType dir_type;
    std::list<Directory> dirs;
    std::list<File> files;
public:

    Directory();
    Directory(std::string path);
    ~Directory();
    void add(File *pF);
    void remove(File *pF);
    void add(Directory *pD);
    void remove(Directory *pD);
    void move(Directory *pD);
    //конструктор копирования - мы не можем копировать в один path
    Directory (const Directory &D){
        if (D.path!=this->path){
            this->path = D.path;
            this->count = D.count;
            this->dir_type = D.dir_type;
            this->dirs = D.dirs;
            this->files = D.files;
        }
    }
    friend Directory& operator+(Directory &D, File &F);
    friend Directory& operator+(Directory &D_source, Directory &D_dest);
    friend Directory& operator==(Directory &D_source, Directory &D_dest);
    // у нас только одна директория
    bool operator==(Directory &D){
        return this == &D;
    }

};


#endif //REWRITE_DIR_CATALOG_DIRECTORY_H
