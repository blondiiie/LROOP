#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>
using namespace std;
class Publication {
protected:
 string title;
 float price = 0;
public:
 void getdata() {
 setlocale(LC_ALL, "Russian");
 cout << "Введите название: ";
 cin.ignore();
 getline(cin, title);
 cout << "Введите цену: ";
 cin >> price;
 }
 void putdata() const {
 cout << "Название: " << title << endl;
 cout << "Цена: " << price << endl;
 }
};
class Book : public Publication {
private:
 int pages = 0;
public:
 void getdata() {
 Publication::getdata();
 cout << "Введите количество страниц: ";
 cin >> pages;
 }
 void putdata() const {
 Publication::putdata();
 cout << "Количество страниц: " << pages << endl;
 }
};
class Audio : public Publication {
private:
 int duration = 0;
public:
 void getdata() {
 Publication::getdata();
 cout << "Введите время записи (в минутах): ";
 cin >> duration;
 }
 void putdata() const {
 Publication::putdata();
 cout << "Время записи: " << duration << " минут" << endl;
 }
};
int main() {
 setlocale(LC_ALL, "Russian");
 system("chcp 1251");
 Book book;
 Audio audio;
 cout << "Ввод данных о книге:" << endl;
 book.getdata();
 cout << "\nВвод данных об аудиозаписи:" << endl;
 audio.getdata();
 cout << "\nДанные о книге:" << endl;
 book.putdata();
 cout << "\nДанные об аудиозаписи:" << endl;
 audio.putdata();
 return 0;
}