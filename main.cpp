#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include <fstream>
#include "Directory.h"

File bad_file;

void insert_obj(Directory & dir){
    std::cout << "Введите данные директории(path, count)";
    std::cin >> dir;
    std::cout << std::endl;
}

File& find_obj(Directory & dir, std::string path){
    for (auto &d:dir.get_files()){
        if (d.get_path() == path){
            return d;
        }
    }
    for(auto &dir_:dir.get_dirs()){
        return find_obj(dir_, path);
    }
    return bad_file;
}

void redact_obj(){}

void delete_obj(){}

void save_to_file(){}

void read_from_file(){}

void sort_(){}

void print(){}

int main() {

//    std::map<int, std::pair<std::string, std::function<void()>>> data;
//    std::vector<std::pair<std::string, std::function<void()> >> str_description =
//            {std::make_pair("Ввод нового объекта и добавление его в контейнер", insert_obj),
//             std::make_pair("Поиск объекта в контейнере по значениям полей с печатью и данных о найденных объектах",find_obj),
//             std::make_pair("Редактирование объекта", redact_obj),
//             std::make_pair("Удаление объекта из контейнера", delete_obj),
//             std::make_pair("Сохранение данных всех объектов в файле", save_to_file),
//             std::make_pair("Чтение данных объектов из файла", read_from_file),
//             std::make_pair("Сортировка объектов контейнера по выбранному полю для list", sort_),
//             std::make_pair("Печать списка объектов", print),
//            };
//    int i = 0;
//    for(auto &s : str_description) {
//        data[i] = s;
//        i++;
//    }
//
//    std::string data_string = "";
//    i = 0;
//    for (auto& s : str_description){
//        data_string += std::to_string(i++) + " " + s.first +"\n";
//    }
//    std::cout << data_string;

    std::string data_string = "1.Ввод нового объекта и добавление его в контейнер\n2.Поиск объекта в контейнере по значениям полей с печатью и данных о найденных объектах\n3.Редактирование объекта\n4.Удаление объекта из контейнера\n5.Сохранение данных всех объектов в файле";
    std::cout << data_string;
    int c;
    std::cin >> c;
    Directory dir;
    std::string path, name_of_file;
    std::fstream f_in;
    std::fstream f_out;

    File res;
    while (c!=-1){
        switch (c) {
            case 1:
                insert_obj(dir);
                break;
            case 2:
                std::cout << "Введите path:"<<std::endl;
                std::cin >> path;
                std::cout <<"res:" <<  find_obj(dir, path) << std::endl;
                break;

            case 3:
                std::cout << "Введите path:"<<std::endl;
                std::cin >> path;
                res = find_obj(dir, path);
                std::cout <<"res:" <<  res << std::endl;
                std::cout << "Введите файл заново:" << std::endl;
                std::cin >> res;
                break;
            case 4:
                std::cout << "Введите path:"<<std::endl;
                std::cin >> path;
                res = find_obj(dir, path);
                std::cout <<"res:" <<  res << std::endl;
                std::cout << "Введите файл заново:" << std::endl;
                std::cin >> res;
                break;
            case 5:
                std::cout << "Введите название файла" << std::endl;
                std::cin >> name_of_file;
                f_in.open(name_of_file);
                f_in << dir;
                break;
            case 6:
                std::cout << "Введите название файла" << std::endl;
                std::cin >> name_of_file;
                f_out.open(name_of_file);
                f_out >> dir;
                break;
            case 7:
                std::cout << "Печать списка объектов:" << std::endl;
                std::cout << dir;
                break;
        }
        std::cout<<data_string;
        std::cin >> c;
    }
}
