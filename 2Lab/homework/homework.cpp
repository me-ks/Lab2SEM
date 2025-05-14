#include <iostream>
#include <cmath>
#include <vector>

class IntMatrix {
private:
    std::vector<std::vector<int>> data;

public:
    IntMatrix(const std::vector<std::vector<int>>& matrix) {
        data = matrix;
    }

    
    double getRowRMS(int row) const {
        if (row < 0 || row >= data.size()) {
            throw std::out_of_range("Invalid row index");
        }

        double sumOfSquares = 0.0;
        for (int value : data[row]) {
            sumOfSquares += value * value;
        }

        return std::sqrt(sumOfSquares / data[row].size());
    }

    
    int getTotalSum() const {
        int total = 0;
        for (const auto& row : data) {
            for (int value : row) {
                total += value;
            }
        }
        return total;
    }
};

int main() {
    std::vector<std::vector<int>> matrixData = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    IntMatrix matrix(matrixData);

    std::cout << "Root mean square of each row:\n";
    for (int i = 0; i < matrixData.size(); ++i) {
        std::cout << "Row " << i << ": " << matrix.getRowRMS(i) << "\n";
    }

    std::cout << "\nTotal sum of all elements: " << matrix.getTotalSum() << "\n";

    return 0;
}
