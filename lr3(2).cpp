#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include<locale>
using namespace std;
class Base {
public:
 virtual void show() const {
 cout << "Это базовый класс Base." <<endl;
 }
 virtual ~Base() { }
};
class Derived : public Base {
public:
 void show() const override {
 cout << "Это производный класс Derived." << endl;
 }
};
void add(vector<shared_ptr<Base>>& storage,shared_ptr<Base> obj) {
 storage.push_back(obj);
}
int main() {
 setlocale(LC_ALL, "Russian");
 srand(static_cast<unsigned int>(time(0)));
 vector<std::shared_ptr<Base>> storage;
 for (int i = 0; i < 10; ++i) {
 int randomValue = rand();
 shared_ptr<Base> obj;
 if (randomValue % 2 == 0) {
 obj = make_shared<Base>();
 }
 else {
 obj = make_shared<Derived>();
 }
 add(storage, obj);
 }
 cout << "Содержимое хранилища:" <<endl;
 for (const auto& item : storage) {
 item->show();
 }
 return 0;
}

