using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SeanStringCalculatorTestProject
{
    public class SeanStringCalculator
    {
        public static int add(string numbers)
        {
            int returnValue = 0;
            string[] numbersArray = numbers.Split(',', '\n');
            //if (numbersArray.Length > 2)
            //{
            //    throw new ArgumentOutOfRangeException("nope");
            //}
            
            foreach (String number in numbersArray)
            {
                if (number.Trim() != null)
                { // After refactoring
                    returnValue += Int32.Parse(number);
                }
            }
            //if (numbers.Length == 0)
            //{
            //    returnValue = 0;
            //}
            return returnValue;

        }

        public static object add()
        {
            return 0;
        }

        //public static int add()
        //{
        //    return 0;
        //}
    }
}
