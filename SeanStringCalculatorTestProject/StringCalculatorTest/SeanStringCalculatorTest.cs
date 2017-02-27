using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace SeanStringCalculatorTestProject
{
    [TestClass]
    public class SeanStringCalculatorTest
    {
        //[TestMethod]
        //[ExpectedException(typeof(ArgumentOutOfRangeException))]

        //public void whenMoreThan2NumbersAreUsedThenExceptionIsThrown()
        //{
        //    SeanStringCalculator.add("1,2,3");
        //}

        [TestMethod]
        public void when2NumbersAreUsedThenNoExceptionIsThrown()
        {
            SeanStringCalculator.add("1,2");
            Assert.IsTrue(true);
        }

        [TestMethod]
        public void whenEmptyStringIsUsedThenReturnValueIs0()
        {
            Assert.AreEqual(0, SeanStringCalculator.add());
                ;
        }

        [TestMethod]
        public void whenOneNumberIsUsedThenReturnValueIsThatSameNumber()
        {
            Assert.AreEqual(3, SeanStringCalculator.add("3"));
        }

        [TestMethod]
        public void whenTwoNumbersAreUsedThenReturnValueIsTheirSum()
        {
            Assert.AreEqual(3 + 6, SeanStringCalculator.add("3,6"));
        }

        [TestMethod]
        public void whenAnyNumberOfNumbersIsUsedThenReturnValuesAreTheirSums()
        {
            Assert.AreEqual(3 + 6 + 15 + 18 + 46 + 33, SeanStringCalculator.add("3,6,15,18,46,33"));
        }

        [TestMethod]
        public void whenNewLineIsUsedBetweenNumbersThenReturnValuesAreTheirSums()
        {
            Assert.AreEqual(3 + 6 + 15, SeanStringCalculator.add("3,6\n15"));
        }


    }
}



//public class StringCalculatorTest
//{
//    @Test(expected = RuntimeException.class)
//    public final void whenMoreThan2NumbersAreUsedThenExceptionIsThrown()
//    {
//        StringCalculator.add("1,2,3");
//    }
//    @Test
//    public final void when2NumbersAreUsedThenNoExceptionIsThrown()
//    {
//        StringCalculator.add("1,2");
//        Assert.assertTrue(true);
//    }
//    @Test(expected = RuntimeException.class)
//    public final void whenNonNumberIsUsedThenExceptionIsThrown()
//    {
//        StringCalculator.add("1,X");
//    }
//}

