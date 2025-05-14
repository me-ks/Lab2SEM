using System;
using System.Collections.Generic;

class Expression
{
    private double a, c, d;

    public Expression(double a, double c, double d)
    {
        this.a = a;
        this.c = c;
        this.d = d;
    }

    private double SafeSqrt(double value)
    {
        if (value < 0.0)
        {
            throw new ArgumentException("Invalid input for square root (value < 0)");
        }
        return Math.Sqrt(value);
    }

    public double Calculate()
    {
        try
        {
            double denominator = c + a - 1;
            if (denominator == 0)
            {
                throw new DivideByZeroException("Division by zero");
            }

            double sqrtValue = SafeSqrt(42.0 / d);
            double result = (2 * c - d * sqrtValue) / denominator;
            return result;
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Calculation error: {ex.Message}");
            throw;
        }
    }
}

class Program
{
    static void Main()
    {
        List<Expression> expressions = new List<Expression>
        {
            new Expression(2, 4, 7),
            new Expression(1, 2, -5),
            new Expression(1, -1, 1)
        };

        for (int i = 0; i < expressions.Count; i++)
        {
            try
            {
                Console.WriteLine($"Expression {i + 1} result: {expressions[i].Calculate()}");
            }
            catch
            {
                Console.WriteLine($"Failed to evaluate expression {i + 1}");
            }
        }
    }
}
