#ifndef RATIONAL_HPP
#define RATIONAL_HPP

/// @file

/// \brief
/// rational ADT
/// \details
/// This is an ADT that implements rational (fractional) values.
/// The counter and denominator are stored as two (signed) integers.
/// The appropriate constructors and operators are provided.
///
/// Rational values are always simplied (reduced): the counter
/// and denominator have no common factors.
class rational
{
private:
   int counter;
   int denominator;

   void reduce()
   {
      int a = counter;
      int b = denominator;

      while (b)
      {
         int temp = b;
         b = a % b;
         a = temp;
      }

      if (a)
      {
         counter /= a;
         denominator /= a;
      }
   }

public:
   /// \brief
   /// constructor from explicit values
   /// \details
   /// This constructor initializes a rational from its counter and denominator.
   /// The default value for the denominator is 1, so a rational be initialized
   /// with just a whole value.
   rational(int counter, int denominator = 1) : counter(counter), denominator(denominator)
   {
      reduce();
   }

   /// \brief
   /// compare two rational values
   /// \details
   /// This operator tests for equality. It returns true
   /// if and only if the counter and denminator of both
   /// operands are equal.
   bool operator==(const rational &rhs) const
   {
      return (counter == rhs.counter) && (denominator == rhs.denominator); // GEBRUIKTE OR OPERATOR || IN PLAATS VAN AND !
   }

   /// \brief
   /// output operator for a rational value
   /// \details
   /// This operator<< prints a constructor in the format
   /// [counter/denominator] where both values are printed as
   /// decimal values.
   friend std::ostream &operator<<(std::ostream &lhs, const rational &rhs)
   {
      return lhs
             << "["
             << rhs.counter
             << "/"
             << rhs.denominator
             << "}";
   }

   /// \brief
   /// multiply a rational by an integer
   /// \details
   /// This operator* multiplies a rational value by an integer value.
   rational operator*(const int rhs) const
   {
      rational result(counter * rhs, denominator); // KEER ALLEEN DE TELLER, WANT BREUK * NORMAAL GETAAL IS ALLEEN KEER DE TELLER
      result.reduce(); // HAD GEEN REDUCE          // DUS 2/10 * 5 = 10/10de of bijvoorbeeld 3/12 * 3 = 9/12de
      return result;
   }

   /// \brief
   /// multiply a rational by a rational
   /// \details
   /// This operator* multiplies a rational value by a rational value.
   rational operator*(const rational &rhs) const
   {
      rational result(
          counter * rhs.counter,
          denominator * rhs.denominator);
      result.reduce(); // HAD GEEN REDUCE
      return result;
   }

   /// \brief
   /// add a rational to another rational
   /// \details
   /// This operator+= adds a rational value a rational variable.
   rational &operator+=(const rational &rhs)
   {
      counter = counter * rhs.denominator + rhs.counter * denominator;
      denominator *= rhs.denominator;
      reduce();
      return *this;
   }

   rational operator*=(const rational rhs)
   {
      counter = counter * rhs.counter;
      denominator = denominator * rhs.denominator;
      reduce();
      return *this;
      // HOORDE GEEN + EN += TE STAAN!!
      // + EN += VERANDERD IN DE TWEE * DIE ER STAAN!
      // RETURNED NIET RHS! RETURNED *THIS!!!!!!
   }
};

#endif