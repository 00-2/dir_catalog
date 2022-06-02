#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include "Directory.h"

void insert_obj(){}

void find_obj(){}

void redact_obj(){}

void delete_obj(){}

void save_to_file(){}

void read_from_file(){}

void sort_(){}

void print(){}

int main() {

    std::map<int, std::pair<std::string, std::function<void()>>> data;
    std::vector<std::pair<std::string, std::function<void()> >> str_description =
            {std::make_pair("Ввод нового объекта и добавление его в контейнер", insert_obj),
             std::make_pair("Поиск объекта в контейнере по значениям полей с печатью и данных о найденных объектах",find_obj),
             std::make_pair("Редактирование объекта", redact_obj),
             std::make_pair("Удаление объекта из контейнера", delete_obj),
             std::make_pair("Сохранение данных всех объектов в файле", save_to_file),
             std::make_pair("Чтение данных объектов из файла", read_from_file),
             std::make_pair("Сортировка объектов контейнера по выбранному полю для list", sort_),
             std::make_pair("Печать списка объектов", print),
            };
    int i = 0;
    for(auto &s : str_description) {
        data[i] = s;
        i++;
    }

    std::string data_string = "";
    i = 0;
    for (auto& s : str_description){
        data_string += std::to_string(i++) + " " + s.first +"\n";
    }
    std::cout << data_string;
    int c;
    std::cin >> c;
    while (c!=-1){
        i = c;
        data[i].second();
        std::cin >> c;
    }
}
