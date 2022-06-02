//
// Created by c0sta on 02.06.2022.
//

#include "File.h"
File::File() {
    this->size = 0;
};

File::File(std::string path, std::string extension) {
    this->path = path;
    this->extension = extension;
};


// analog for replace data
void File::change_size(size_t size) {
    this->size = size;
}

//analog for chmod
void File::change_mode(unsigned short mode) {
    this->mode = mode;

}

int File::get_file_hash() {
    return std::hash<std::string>()(std::to_string(this->size) + this->extension);
}

void File::clear() {
    this->size = 0;
}
