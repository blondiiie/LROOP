#include <iostream>
#include <string>
#include <array>
#include <locale.h>
#include <cstdlib>
using namespace std;
class Publication {
protected:
 string title;
 float price;
public:
 void getdata() {
 cout << "Введите название: ";
 cin.ignore();
 cout << "Введите цену: ";
 cin >> price;
 }
 void putdata() const {
 cout << "Название: " << title << endl;
 cout << "Цена: " << price << endl;
 }
};
class Sales {
protected:
 array<float, 3> salesData;
public:
 Sales() {
 for (int i = 0; i < 3; ++i) {
 salesData[i] = 0.0f;
 }
 }
 void getSalesData() {
 for (int i = 0; i < 3; ++i) {
 cout << "Введите продажи за месяц " << (i + 1) << ": ";
 cin >> salesData[i];
 }
 }
 void putSalesData() const {
 for (int i = 0; i < 3; ++i) {
 cout << "Продажи за месяц " << (i + 1) << ": " << salesData[i] << endl;
 }
 }
};
class Book : public Publication, public Sales {
private:
 int pages;
public:
 void getdata() {
 Publication::getdata();
 cout << "Введите количество страниц: ";
 cin >> pages;
 getSalesData();
 }
 void putdata() const {
 Publication::putdata();
 cout << "Количество страниц: " << pages << endl;
 putSalesData();
 }
};
class Audio : public Publication, public Sales {
private:
 int duration;
public:
 void getdata() {
 Publication::getdata();
 cout << "Введите время записи (в минутах): ";
 cin >> duration;
 getSalesData();
 }
 void putdata() const {
 Publication::putdata();
 cout << "Время записи: " << duration << " минут" << endl;
 putSalesData();
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
7
 cout << "\nДанные о книге:" << endl;
 book.putdata();
 cout << "\nДанные об аудиозаписи:" << endl;
 audio.putdata();
 return 0;
}
