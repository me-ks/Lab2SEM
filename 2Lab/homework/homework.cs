using System;

class IntMatrix
{
    private int[,] data;

    public IntMatrix(int[,] initialData)
    {
        data = initialData;
    }

    
    public double this[int row]
    {
        get
        {
            if (row < 0 || row >= data.GetLength(0))
                throw new IndexOutOfRangeException("Invalid row index");

            int columns = data.GetLength(1);
            double sumOfSquares = 0;

            for (int j = 0; j < columns; j++)
            {
                sumOfSquares += data[row, j] * data[row, j];
            }

            return Math.Sqrt(sumOfSquares / columns);
        }
    }

    
    public int TotalSum
    {
        get
        {
            int sum = 0;
            for (int i = 0; i < data.GetLength(0); i++)
            {
                for (int j = 0; j < data.GetLength(1); j++)
                {
                    sum += data[i, j];
                }
            }
            return sum;
        }
    }
}

class Program
{
    static void Main()
    {
        int[,] matrixData = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };

        IntMatrix matrix = new IntMatrix(matrixData);

        Console.WriteLine("Root mean square of each row:");
        for (int i = 0; i < matrixData.GetLength(0); i++)
        {
            Console.WriteLine($"Row {i}: {matrix[i]:F2}");
        }

        Console.WriteLine($"\nTotal sum of all elements: {matrix.TotalSum}");
    }
}
