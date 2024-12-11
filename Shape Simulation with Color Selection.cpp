using System;

namespace GeometryApp
{
    public abstract class Shape
    {
        public abstract void Draw();
        public ConsoleColor Color { get; set; }

        protected void SetColor()
        {
            Console.ForegroundColor = Color;
        }
    }

    public class Square : Shape
    {
        public override void Draw()
        {
            SetColor();
            Console.WriteLine("");
            Console.WriteLine(" **** ");
            Console.WriteLine(" **** ");
            Console.WriteLine(" **** ");
            Console.WriteLine("");
            Console.ResetColor();
        }
    }

    public class Rectangle : Shape
    {
        public override void Draw()
        {
            SetColor();
            Console.WriteLine("");
            Console.WriteLine(" ************ ");
            Console.WriteLine(" ************ ");
            Console.WriteLine(" ************ ");
            Console.WriteLine(" ************ ");
            Console.WriteLine("");
            Console.ResetColor();
        }
    }

    public class Rhombus : Shape
    {
        public override void Draw()
        {
            SetColor();
            Console.WriteLine("");
            Console.WriteLine("   *   ");
            Console.WriteLine("  ***  ");
            Console.WriteLine(" ***** ");
            Console.WriteLine("  ***  ");
            Console.WriteLine("   *   ");
            Console.WriteLine("");
            Console.ResetColor();
        }
    }

    public class Triangle : Shape
    {
        public override void Draw()
        {
            SetColor();
            Console.WriteLine("");
            Console.WriteLine("    *    ");
            Console.WriteLine("   ***   ");
            Console.WriteLine("  *****  ");
            Console.WriteLine(" ******* ");
            Console.WriteLine("");
            Console.ResetColor();
        }
    }

    public class Trapezoid : Shape
    {
        public override void Draw()
        {
            SetColor();
            Console.WriteLine("");
            Console.WriteLine("   *****   ");
            Console.WriteLine("  *******  ");
            Console.WriteLine(" ********* ");
            Console.WriteLine("");
            Console.ResetColor();
        }
    }

    public class Polygon : Shape
    {
        public override void Draw()
        {
            SetColor();
            Console.WriteLine("");
            Console.WriteLine("    *****   ");
            Console.WriteLine("   **   **     ");
            Console.WriteLine("  **     ** ");
            Console.WriteLine("   **   **   ");
            Console.WriteLine("    *****   ");
            Console.WriteLine("");
            Console.ResetColor();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("");
                Console.WriteLine("Select a shape");
                Console.WriteLine("");
                Console.WriteLine("1) Square");
                Console.WriteLine("2) Rectangle");
                Console.WriteLine("3) Rhombus");
                Console.WriteLine("4) Triangle");
                Console.WriteLine("5) Trapezoid");
                Console.WriteLine("6) Polygon");
                Console.WriteLine("");

                int choice = -1;
                while (choice < 1 || choice > 6)
                {
                    Console.Write("Please select a valid shape number (1-6): ");
                    string input = Console.ReadLine();
                    if (int.TryParse(input, out choice) && choice >= 1 && choice <= 6)
                        break;
                    else
                        Console.WriteLine("Invalid input. Please enter a number between 1 and 6.");
                }

                Shape shape = null;

                switch (choice)
                {
                    case 1:
                        shape = new Square();
                        break;
                    case 2:
                        shape = new Rectangle();
                        break;
                    case 3:
                        shape = new Rhombus();
                        break;
                    case 4:
                        shape = new Triangle();
                        break;
                    case 5:
                        shape = new Trapezoid();
                        break;
                    case 6:
                        shape = new Polygon();
                        break;
                }

                Console.WriteLine("");
                Console.WriteLine("Choose a color (Red, Green, Blue, Yellow):");
                string colorInput = Console.ReadLine();

                bool isValidColor = Enum.TryParse(colorInput, true, out ConsoleColor color);
                if (isValidColor)
                {
                    shape.Color = color;
                    shape.Draw();
                }
                else
                {
                    Console.WriteLine("Invalid color. Using default color.");
                    shape.Color = ConsoleColor.White;
                    shape.Draw();
                }
            }
        }
    }
}
