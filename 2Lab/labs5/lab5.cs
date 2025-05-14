using System;

namespace GeometryPolymorphism
{
    public class Figure
    {
        protected double Length { get; }
        protected double Width { get; }

        public Figure(double length, double width)
        {
            Length = length;
            Width = width;
        }

        public virtual double Area()
        {
            return Length * Width;
        }

        public virtual double Perimeter()
        {
            return 2 * (Length + Width);
        }
    }

    public class Ellipse : Figure
    {
        public Ellipse(double a, double b) : base(a, b) { }

        public override double Area()
        {
            return Math.PI * Length * Width;
        }

        public override double Perimeter()
        {
            return Math.PI * (3 * (Length + Width) - Math.Sqrt((3 * Length + Width) * (Length + 3 * Width)));
        }
    }

    public class Circle : Figure
    {
        public Circle(double radius) : base(radius, radius) { }

        public override double Area()
        {
            return Math.PI * Length * Length;
        }

        public override double Perimeter()
        {
            return 2 * Math.PI * Length;
        }
    }

    class Program
    {
        static void DisplayFigureInfo(Figure figure)
        {
            Console.WriteLine($"Area: {figure.Area()}");
            Console.WriteLine($"Perimeter: {figure.Perimeter()}");
        }

        static void Main(string[] args)
        {
            Ellipse e = new Ellipse(3.0, 2.0);
            Circle c = new Circle(5.0);

            Console.WriteLine("--- Ellipse ---");
            DisplayFigureInfo(e);

            Console.WriteLine("--- Circle ---");
            DisplayFigureInfo(c);
        }
    }
}
