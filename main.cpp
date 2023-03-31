#include <iostream>
#include <vector>

struct Temp{
    Temp(int _b){
        std::cout << "const" << std::endl;
        b = _b;
    }
    int b;
};



int main() {

    std::vector<Temp> t;
    t.push_back(Temp(10));//вызвали конструктор
    t.emplace_back(Temp(10));
    Temp t1(10);
    std::cout << std::endl;
    t.push_back((t1));//записал переменную в структуру
    t.emplace_back(t1);//записал переменную в структуру

    std::cout << std::endl;
    Temp* t2 = new Temp(20);
    t.push_back((*t2));//push вызвал конструктор, emplace не вызвал конструктор, а просто записал переменную в структуру
    std::cout << std::endl;
    //t.emplace_back(*t2);
    delete t2;
    for(auto it : t){
        std::cout << &it.b;
    }
    //0xc79b7ffd5c
    //0xc79b7ffd5c
    //0x4691ffc6c
    return 0;


    std::vector<std::pair<int, float>> temp(5);//резиновый массив, 5 - длина массива. может быть нулевая длина
    int xz = 5;
    temp.emplace_back(1, 1);
    for(int i = 0; i < temp.size(); i++)
        std::cout << temp[i].first << " " << temp[i].second << std::endl;
    std::cout << std::endl;
    for(auto it : temp){// цикл проходит по всему вектору, используя переопределение :
        //альтернатива (int i = 0; i < size; i++), но для вектора
        //итератор(it) является указателем на тип в векторе, автоматически инкрементирует итератор

        it.first = xz;
        it.second = xz;
        std::cout << it.first << " " << it.second << std::endl;
    }//iterator хранит адрес текущего элемента
    std::cout << std::endl;
    for(int i = 0; i < temp.size(); i++)
        std::cout << temp[i].first << " " << temp[i].second << std::endl;

    //erase(it.begin() + 3, 2); удаляет n-ое количество элементов  с m-ого количества элементов
    // было  0 1 2 3 4 5 6
    //стало 0 1 2 5 6
    //resize(100);
    return 0;
}
