#include <iostream>
#include <vector>
#include <memory>
#include <locale>
#include <string>
class Detail {
protected:
 std::string name;
 int partNumber;
 Detail(const std::string& name, int partNumber)
 : name(name), partNumber(partNumber) { }
public:
 virtual void info() const = 0;
 virtual ~Detail() {}
};
class Assembly : public Detail {
private:
 std::vector<std::shared_ptr<Detail>> components;
protected:
 Assembly(const std::string& name, int partNumber)
 : Detail(name, partNumber) { }
public:
 void addComponent(std::shared_ptr<Detail> component) {
 components.push_back(component);
 }
 void info() const override {
 std::cout << "Сборка: " << name << ", Номер: " << partNumber << std::endl;
 std::cout << "Содержит следующие детали:" << std::endl;
 for (const auto& component : components) {
 component->info();
 }
 }
 friend std::shared_ptr<Assembly> createAssembly(const std::string& name, int
partNumber);
};
class Component : public Detail {
public:
 Component(const std::string& name, int partNumber)
 : Detail(name, partNumber) { }
 void info() const override {
 std::cout << "Деталь: " << name << ", Номер: " << partNumber << std::endl;
 }
 friend std::shared_ptr<Component> createComponent(const std::string& name, int
partNumber);
};
std::shared_ptr<Component> createComponent(const std::string& name, int partNumber) {
 return std::make_shared<Component>(name, partNumber);
}
std::shared_ptr<Assembly> createAssembly(const std::string& name, int partNumber) {
 return std::shared_ptr<Assembly>(new Assembly(name, partNumber));
}
int main() {
 setlocale(LC_ALL, "Russian");
 std::vector<std::shared_ptr<Detail>> storage;
 storage.push_back(createComponent("Деталь A", 101));
 storage.push_back(createComponent("Деталь B", 102));
 storage.push_back(createComponent("Деталь C", 103));
 auto assembly = createAssembly("Сборка 1", 201);
 assembly->addComponent(storage[0]);
 assembly->addComponent(storage[1]);
 assembly->addComponent(storage[2]);
 storage.push_back(assembly);
 for (const auto& item : storage) {
 item->info();
 }
 return 0;
}