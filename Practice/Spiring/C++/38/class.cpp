#include <iostream>
#include <cmath>

bool equal(double a, double b, double e = 1E-10);

int sign(int a)
{
    return a < 0 ? -1 : 1;
}

class Rational
{
    int numerator_;
    int denominator_;
    int sign_;

public:
    static int gcd(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }

        if (b == 0)
        {
            return a;
        }

        if (b > a)
        {
            std::swap(a, b);
        }

        for (int i = b; i > 1; --i)
        {
            if (a % i == 0 and b % i == 0)
            {
                return i;
            }
        }

        return 1;
    }

    static int lcm(int a, int b)
    {
        return abs(a * b) / gcd(a, b);
    }

    Rational() : numerator_(0), denominator_(1), sign_(1) {}

    Rational(int a, int b) : numerator_(abs(a)), denominator_(abs(b)), sign_(sign(a) == sign(b) ? 1 : -1)
    {
        if (a != 0 and b != 0)
        {
            int gcd = Rational::gcd(numerator_, denominator_);

            numerator_ /= gcd;
            denominator_ /= gcd;
        }
    }

    bool operator ==(const Rational& other) const
    {
        if (isNaN() or other.isNaN())
        {
            return false;
        }

        if (numerator_ == 0 and other.numerator_ == 0)
        {
            return true;
        }

        if (sign_ != other.sign_)
        {
            return false;
        }

        if (denominator_ == 0 and other.denominator_ == 0)
        {
            return true;
        }

        return numerator_ == other.numerator_ and denominator_ == other.denominator_;
    }

    Rational operator -(const Rational& other) const
    {
        Rational copy = other;
        copy.sign_ = -copy.sign_;

        return *this + copy;
    }

    Rational operator +(const Rational& other) const
    {
        if (isNaN() or other.isNaN())
        {
            return Rational(0, 0);
        }

        if (denominator_ == 0 and other.denominator_ == 0)
        {
            if (sign_ == other.sign_)
            {
                return other;
            }

            return Rational(0, 0);
        }

        if (denominator_ == 0)
        {
            return *this;
        }

        if (other.denominator_ == 0)
        {
            return other;
        }

        int lcm = Rational::lcm(denominator_, other.denominator_);

        int first_numerator = numerator_ * (lcm / denominator_);
        int second_numerator = other.numerator_ * (lcm / other.denominator_);

        int result_sign;
        int result_numerator;

        if (sign_ == other.sign_)
        {
            result_sign = sign_;
            result_numerator = first_numerator + second_numerator;
        }
        else
        {
            result_sign = first_numerator > second_numerator ? sign_ : other.sign_;
            result_numerator = abs(first_numerator - second_numerator);
        }

        Rational result(result_numerator, lcm);
        result.sign_ = result_sign;

        return result;
    }

    Rational operator *(const Rational& other) const
    {
        Rational result(numerator_ * other.numerator_, denominator_ * other.denominator_);
        result.sign_ = sign_ * other.sign_;

        return result;
    }

    Rational operator /(const Rational& other) const
    {
        Rational result = Rational(numerator_ * other.denominator_, denominator_ * other.numerator_);
        result.sign_ = sign_ * other.sign_;

        return result;
    }

    operator double() const
    {
        return sign_ * numerator_ / double(denominator_);
    }

    operator bool() const
    {
        return numerator_ != 0 or denominator_ == 0;
    }

    int numerator() const
    {
        return numerator_;
    }

    int denominator() const
    {
        return denominator_;
    }

    bool isNaN() const
    {
        return numerator_ == 0 and denominator_ == 0;
    }
};
