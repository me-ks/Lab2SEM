#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>

class Expression {
private:
    double a, c, d;

    
    double SafeSqrt(double value) const {
        if (value < 0.0) {
            throw std::invalid_argument("Invalid input for square root (value < 0)");
        }
        return std::sqrt(value);
    }

public:
    Expression(double a_, double c_, double d_) : a(a_), c(c_), d(d_) {}

    double Calculate() const {
        try {
            double denominator = c + a - 1;
            if (denominator == 0) {
                throw std::runtime_error("Division by zero");
            }

            double sqrtValue = SafeSqrt(42.0 / d); 
            double result = (2 * c - d * sqrtValue) / denominator;
            return result;
        }
        catch (const std::exception& ex) {
            std::cerr << "Calculation error: " << ex.what() << std::endl;
            throw;
        }
    }
};

int main() {
    std::vector<Expression> expressions = {
        Expression(2, 4, 7),
        Expression(1, 2, -5), 
        Expression(1, -1, 1)  
    };

    for (size_t i = 0; i < expressions.size(); ++i) {
        try {
            std::cout << "Expression " << i + 1 << " result: " << expressions[i].Calculate() << std::endl;
        }
        catch (...) {
            std::cout << "Failed to evaluate expression " << i + 1 << std::endl;
        }
    }

    return 0;
}
