#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>

bool isTherteenDigit(long long int);

class ErrorConstructorAuthor {};
class ErrorConstructorBook {};

class Author {
public:
    Author() = delete;	//запретить конструктор по умолчанию

    Author(std::string _last_name, std::string _first_name);
    Author(std::string _last_name, std::string _first_name, short int _birth_year);	//контруктор делегирования ???
    Author(std::string _last_name, std::string _first_name, std::string _second_name, short int _birth_year);

    ~Author() = default;

    std::string getLast_name() const { return last_name; }
    std::string getFirst_name() const { return first_name; }
    std::string getSecond_name() const { return second_name; }
    std::string getFull_name() const { return last_name + " " + first_name + " " + second_name; }
    short int getBirth_year() const { return birth_year; }

    
    friend std::ostream& operator <<(std::ostream&, Author*);
    /*friend std::istream& operator >>(std::istream&, Author&);
    */
    void print(std::ostream&);
    friend Author readAuthor(std::istream&);
private:
    std::string last_name;
    std::string first_name;
    std::string second_name;
    short int birth_year;
};

Author::Author(std::string _last_name, std::string _first_name)
{

    last_name = _last_name;
    first_name = _first_name;

}

Author::Author(std::string _last_name, std::string _first_name, short int _birth_year)
{
    if (_birth_year <= 0 || _first_name == "" || _last_name == "") {
        throw ErrorConstructorAuthor();
    }

    Author(_last_name, _first_name);
    if (_birth_year > 0) {
        birth_year = _birth_year;
    }
    else {
        birth_year = 1;
    }
}

Author::Author(std::string _last_name, std::string _first_name, std::string _second_name, short int _birth_year)
{
    Author(_last_name, _first_name, _birth_year);
    second_name = _second_name;
}

std::ostream& operator <<(std::ostream& out, Author* ptrAuthor)
{
    ptrAuthor->print(out);
    return out;
}

/*
Author readAuthor(std::istream&)
{

}*/
/*
std::istream& operator >>(std::istream& in, Author& author)
{
    in >> author.last_name >> author.first_name;
    return in;
}*/

void Author::print(std::ostream& out)
{
    out << last_name << " " << first_name;
}
class Book {
public:
    Book() = delete;
    Book(long long int _isbn, std::string _title = " ", double _price = 1, std::vector<Author*> _authors = { nullptr },
        char* _publisher = (char*)"0", int _year = 1, int _pages = 1);

    Book(Book&&);
    Book(const Book&);

    ~Book() = default;

    friend std::ostream& operator <<(std::ostream&, const Book&);
    //friend std::istream& operator >>(std::istream&, Book&);
    friend Book readBook(std::istream&);
private:
    long long int isbn_;
    std::string title_;
    double price_;
    std::vector<Author*> authors_;
    char* publisher_;
    int year_;
    int pages_;
};

Book::Book(long long int _isbn, std::string _title, double _price, std::vector<Author*> _authors, char* _publisher, int _year, int _pages) 
{
    if (!isTherteenDigit(_isbn) || _isbn <= 0 || _title != "" || _price <= 0 || _pages <=0 || _year <= 0 || _publisher == nullptr) {
        //throw ErrorConstructorBook();
    }

    isbn_ = _isbn;
    title_ = _title;
    price_ = _price;
    authors_ = _authors;
    publisher_ = _publisher;
    year_ = _year;
    pages_ = _pages;
}



bool isTherteenDigit(long long int num)
{
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }

    return count == 13;
}

Book::Book(const Book& book) : isbn_(book.isbn_), title_(book.title_), authors_(book.authors_), 
            publisher_(new char[strlen(book.publisher_)]), year_(book.year_), pages_(book.pages_)
{
    strcpy(publisher_, book.publisher_);
};

Book::Book(Book&& book) : isbn_(book.isbn_), title_(book.title_), authors_(book.authors_),
        publisher_(book.publisher_), year_(book.year_), pages_(book.pages_)
{
    book.publisher_ = nullptr;
    book.isbn_ = 0;
    book.title_ = "";
    book.authors_ = { nullptr };
    book.year_ = 0;
    book.pages_ = 0;
};

std::ostream& operator <<(std::ostream& out, const Book& book)
{
    out << "Authors: ";
    //copy(book.authors_.begin(), book.authors_.end(), std::ostream_iterator<std::string>(out, " "));
    for (size_t i = 0; i < book.authors_.size(); i++)
    {
        out << book.authors_[i] << " ";
    }
    out << book.publisher_ << " " << book.isbn_ << " " << book.title_ << " " << book.year_ << " ";
    return out;
}
/*
std::istream& operator >>(std::istream& in, Book& book)
{
    in >> book.isbn_;
    in.ignore();
    std::getline(in, book.title_);
    std::string str;
    std::getline(in, str);
    std::istringstream line(str); //мы создали поток из строки

    std::string lastName, firstName;
    while (line) {
        line >> lastName >> firstName;	//читаем до пробела
        Author author(lastName, firstName);
        book.authors_.push_back(&author);
    }
}*/

Book readBook(std::istream& in)
{
    long long int isbn;
    std::string title;
    std::vector <Author*> authors;
    char publisher[20];
    int year, pages;
    int price;

    in >> isbn;
    in.ignore();
    std::getline(in, title);
    std::string str;
    std::getline(in, str);
    std::istringstream line(str); //мы создали поток из строки

    std::string lastName, firstName;

    while (!line.eof()) {
        line >> lastName >> firstName;	//читаем до пробела
        
        Author* a = new Author(lastName, firstName);    //неясно, где освободить память
                                                        //нужен умный указатель std::shared_ptr, недопустимый по условию 
        authors.push_back(a);	//ошибка здесь
    }
    in >> publisher;
    in >> year >> pages >> price;

    // объект автор уничтожается когда выходим из цикла, все указатели указывают на один и тот же постоянно изменяемый объект

    Book book(isbn, title, price, authors, publisher, year, pages);

    return book;
}