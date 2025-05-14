#include <iostream>
#include <string>
#include <algorithm>


class StringBase {
protected:
    std::string data;

public:
    StringBase() : data("") {}
    StringBase(const std::string& str) : data(str) {}
    StringBase(const StringBase& other) : data(other.data) {}
    virtual ~StringBase() {}

    std::string getData() const {
        return data;
    }

    size_t getLength() const {
        return data.length();
    }
};


class LetterString : public StringBase {
public:
    LetterString() : StringBase() {}
    LetterString(const std::string& str) : StringBase(str) {}
    LetterString(const LetterString& other) : StringBase(other) {}
    ~LetterString() {}

    std::string getSorted() const {
        std::string sorted = data;
        std::sort(sorted.begin(), sorted.end());
        return sorted;
    }
};


int main() {
    LetterString ls("helloWorld");

    std::cout << "String: " << ls.getData() << std::endl;
    std::cout << "Length: " << ls.getLength() << std::endl;
    std::cout << "Sorted: " << ls.getSorted() << std::endl;

    return 0;
}
