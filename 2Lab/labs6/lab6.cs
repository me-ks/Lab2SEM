using System;
using System.Collections.Generic;
using System.Linq;

public interface IDigitProcessor {
    int CountDigits();
    string RemoveDigits();
}

public class TextLine : IDigitProcessor {
    private readonly string content;

    public TextLine(string text) {
        content = text;
    }

    public string GetContent() => content;

    public int CountDigits() {
        return content.Count(char.IsDigit);
    }

    public string RemoveDigits() {
        return new string(content.Where(c => !char.IsDigit(c)).ToArray());
    }
}

public class TextContainer {
    private readonly List<TextLine> lines = new();

    public void AddLine(TextLine line) => lines.Add(line);

    public void Clear() => lines.Clear();

    public int TotalDigitCount() => lines.Sum(line => line.CountDigits());
}

class Program {
    static void Main() {
        var container = new TextContainer();
        container.AddLine(new TextLine("Example123Text"));
        container.AddLine(new TextLine("Another456Example"));

        Console.WriteLine("Total digits: " + container.TotalDigitCount());
    }
}
