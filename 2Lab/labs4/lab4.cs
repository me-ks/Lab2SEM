using System;


class StringBase
{
    protected string data;

    public StringBase()
    {
        data = "";
    }

    public StringBase(string str)
    {
        data = str;
    }

    public StringBase(StringBase other)
    {
        data = other.data;
    }

    public string GetData()
    {
        return data;
    }

    public int GetLength()
    {
        return data.Length;
    }
}

class LetterString : StringBase
{
    public LetterString() : base() { }

    public LetterString(string str) : base(str) { }

    public LetterString(LetterString other) : base(other) { }

    public string GetSorted()
    {
        char[] chars = data.ToCharArray();
        Array.Sort(chars);
        return new string(chars);
    }
}

// Main entry point
class Program
{
    static void Main()
    {
        LetterString ls = new LetterString("helloWorld");

        Console.WriteLine("String: " + ls.GetData());
        Console.WriteLine("Length: " + ls.GetLength());
        Console.WriteLine("Sorted: " + ls.GetSorted());
    }
}
