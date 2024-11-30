#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>
#include <locale>
using namespace std;
class Transport {
public:
 virtual void info() const = 0;
 virtual ~Transport() = default;
};
class Bicycle : public Transport {
public:
 void info() const override {
 cout << "Велосипед: экологичное средство, не требует топлива." << endl;
 }
};
class Car : public Transport {
private:
 int speed;
public:
 Car(int s) : speed(s) {
 if (s > 300) {
 throw overflow_error("Скорость автомобиля превышает допустимый предел.");
 }
 }
 void info() const override {
 cout << "Автомобиль: удобный транспорт, скорость = " << speed << " км/ч." <<
endl;
 }
};
class Truck : public Transport {
private:
 int weight;
public:
 Truck(int w) : weight(w) {
 if (w > 10000) {
 throw overflow_error("Масса грузовика превышает допустимый предел.");
 }
 }
 void info() const override {
 cout << "Грузовик: предназначен для перевозки тяжелых грузов, масса = " <<
weight << " кг." << endl;
 }
};
template <typename T>
class Array {
private:
 vector<T*> elements;
public:
 Array(size_t size = 0) : elements(size, nullptr) {}
 T* operator[](size_t index) {
 if (index >= elements.size()) {
 throw out_of_range("Индекс вне допустимого диапазона.");
 }
 return elements[index];
 }
 const T* operator[](size_t index) const {
 if (index >= elements.size()) {
 throw out_of_range("Индекс вне допустимого диапазона.");
 }
 return elements[index];
 }
 void set(size_t index, T* value) {
 if (index >= elements.size()) {
 throw out_of_range("Индекс вне допустимого диапазона.");
 }
 elements[index] = value;
 }
 void info() const {
 for (const auto& element : elements) {
 if (element) {
 element->info();
 }
 else {
 cout << "Пустая ячейка" << endl;
 }
 }
 }
 ~Array() {
 for (auto& element : elements) {
 delete element;
 }
 }
};
int main() {
 setlocale(LC_ALL, "Russian");
 try {
 Array<Transport> transportArray(3);
 transportArray.set(0, new Bicycle());
 transportArray.set(1, new Car(120));
 transportArray.set(2, new Truck(8000));
 cout << "Информация о транспортных средствах:" << endl;
 transportArray.info();
 try {
 transportArray.set(3, new Car(350));
 }
 catch (const out_of_range& e) {
 cerr << "Перехвачено исключение: " << e.what() << endl;
 }
 try {
 Car fastCar(350);
 }
 catch (const overflow_error& e) {
 cerr << "Перехвачено исключение: " << e.what() << endl;
 }
 }
 catch (const exception& e) {
 cerr << "Необработанное исключение: " << e.what() << endl;
 }
 return 0;
}