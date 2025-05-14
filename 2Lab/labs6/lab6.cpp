#include <iostream>
#include <string>
#include <vector>
#include <cctype>

class IDigitProcessor {
public:
    virtual int CountDigits() const = 0;
    virtual std::string RemoveDigits() const = 0;
    virtual ~IDigitProcessor() = default;
};

class TextLine : public IDigitProcessor {
private:
    std::string content;

public:
    TextLine(const std::string& text) : content(text) {}

    std::string GetContent() const {
        return content;
    }

    int CountDigits() const override {
        int count = 0;
        for (char c : content) {
            if (isdigit(c)) ++count;
        }
        return count;
    }

    std::string RemoveDigits() const override {
        std::string result;
        for (char c : content) {
            if (!isdigit(c)) result += c;
        }
        return result;
    }
};

class TextContainer {
private:
    std::vector<TextLine> lines;

public:
    void AddLine(const TextLine& line) {
        lines.push_back(line);
    }

    void Clear() {
        lines.clear();
    }

    int TotalDigitCount() const {
        int total = 0;
        for (const auto& line : lines) {
            total += line.CountDigits();
        }
        return total;
    }
};

int main() {
    TextContainer container;
    container.AddLine(TextLine("Line1 with 123"));
    container.AddLine(TextLine("Another456Line"));

    std::cout << "Total digits: " << container.TotalDigitCount() << std::endl;
    return 0;
}
