#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Book {
public:
    enum class Type { Fiction, Technical };

    Book(const std::string& author, const std::string& title, Type type)
        : author_(author), title_(title), type_(type) {
        if (author_.empty() || title_.empty()) {
            throw std::invalid_argument("Author and title cannot be empty.");
        }
    }

    void printInfo() const {
        std::cout << "Author: " << author_
            << ", Title: " << title_
            << ", Type: " << (type_ == Type::Fiction ? "Fiction" : "Technical")
            << std::endl;
    }

private:
    std::string author_;
    std::string title_;
    Type type_;
};

class Library {
public:
    void addBook(const Book& book) {
        books_.push_back(book);
    }

    void printLibrary() const {
        for (const auto& book : books_) {
            book.printInfo();
        }
    }

private:
    std::vector<Book> books_;
};

int main() {
    setlocale(LC_ALL, "Rus");
    Library library;

    try {
        library.addBook(Book("Jorj Oruel", "1984", Book::Type::Fiction));
        library.addBook(Book("Aizek Azimow", "Я,робот", Book::Type::Fiction));
        library.addBook(Book("Bjarne Stroustrup", "The C++ Programming Language", Book::Type::Technical));

        std::cout << "Books in the library:\n";
        library.printLibrary();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
