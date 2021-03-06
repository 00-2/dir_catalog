//
// Created by c0sta on 02.06.2022.
//

#ifndef REWRITE_DIR_CATALOG_FILE_H
#define REWRITE_DIR_CATALOG_FILE_H


#include <cstddef>
#include <string>

class File {
public:

    size_t size;
    std::string path;
    std::string extension;
    unsigned short mode; // max is 777
    File();
    File(std::string path, std::string extension);

    void change_mode(unsigned short mode);
    void change_size(size_t size);
    int get_file_hash();
    void clear();
    std::string get_path();
    bool operator==(const File&D_source){
        return (this->path == D_source.path) &&
            (this->size == D_source.size) &&
            (this->extension == D_source.extension) &&
            (this->mode == D_source.mode);
    }
    friend std::ostream & operator<< (std::ostream & os, File &F);
    friend std::istream & operator>> (std::istream & is, File &F);
    };

#endif //REWRITE_DIR_CATALOG_FILE_H
