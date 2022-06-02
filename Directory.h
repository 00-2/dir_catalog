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
    auto get_files(){return files;}
    auto get_dirs(){return dirs;}

    Directory();
    Directory(std::string path);
    Directory(
            size_t count_,
            std::string path_,
            DirectoryType dir_type_,
            std::list<Directory> dirs_,
            std::list<File> files_
            ) : count(count_), path(path_), dir_type(dir_type_), dirs(dirs_), files(files_){};
    ~Directory();
    void add(File &pF);
    void remove(File &pF);
    void add(Directory &pD);
    void remove(Directory &pD);
    void move(Directory &pD);
    std::string get_path(){return path;}
    size_t get_count(){return count;}
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
    // у нас только одна директория
    bool operator==(const Directory &D){
        return this == &D;
    }
    friend std::istream& operator>> (std::istream& is, Directory &D);
    friend std::ostream & operator<< (std::ostream & os, Directory &D);
};


#endif //REWRITE_DIR_CATALOG_DIRECTORY_H
