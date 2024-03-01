#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cerr << "Знаменатель не может быть равен нулю!" << endl;
            exit(1);
        }
    }
    void input() {
        cout << "Введите числитель: ";
        cin >> numerator;
        cout << "Введите знаменатель: ";
        cin >> denominator;

        if (denominator == 0) {
            cerr << "Знаменатель не может быть равен нулю!" << endl;
            exit(1);
        }
    }
    void display() const {
        cout << numerator << "/" << denominator;
    }
    Fraction add(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction subtract(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction multiply(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    Fraction divide(const Fraction& other) const {
        if (other.numerator == 0) {
            cerr << "Деление на ноль!" << endl;
            exit(1);
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }
};

int main() {

    system("chcp 1251");

    Fraction frac1, frac2;
    cout << "Введите первую дробь:\n";
    frac1.input();
    cout << "Введите вторую дробь:\n";
    frac2.input();
    cout << "Первая дробь: ";
    frac1.display();
    cout << endl;
    cout << "Вторая дробь: ";
    frac2.display();
    cout << endl;
    Fraction sum = frac1.add(frac2);
    cout << "Сумма: ";
    sum.display();
    cout << endl;
    Fraction difference = frac1.subtract(frac2);
    cout << "Разность: ";
    difference.display();
    cout << endl;
    Fraction product = frac1.multiply(frac2);
    cout << "Произведение: ";
    product.display();
    cout << endl;
    Fraction quotient = frac1.divide(frac2);
    cout << "Частное: ";
    quotient.display();
    cout << endl;
    return 0;
}
