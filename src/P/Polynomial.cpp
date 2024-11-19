#include "P/Polynomial.hpp"

#include <string>

#include "N/LongNatural.hpp"
#include "Q/LongRational.hpp"
#include "Z/LongInteger.hpp"

Polynomial::Polynomial(const std::map<LongNatural, LongRational>& map) : coefficients(map) {
    std::map<LongNatural, LongRational> temp_map = coefficients;
    for (const auto& [deg, coef] : temp_map) {
        if (coef.getNumerator() == LongInteger::ZERO) {
            coefficients.erase(deg);  // стираем нулевые степени
        }
    }
}

const std::map<LongNatural, LongRational>& Polynomial::getMap() const {
    return coefficients;
}

const LongRational& Polynomial::getCoef(const LongNatural& degree) const {
    if (coefficients.count(degree) == 1)
        return coefficients.at(degree);
    else
        return LongRational::ZERO;
}

const LongNatural& Polynomial::getDegree() const {
    if (coefficients.empty()) {
        return LongNatural::ZERO;  // если пустой - возвращаем 0
    }
    return coefficients.rbegin()->first;  // возвращаем степень последнего элемента
}

std::string Polynomial::toString() const {
    if (coefficients.empty()) {
        return "0";
    }
    std::string result = "";
    // добавляем в строку коэффиценты с наибольшей степени
    for (auto it = coefficients.rbegin(); it != coefficients.rend(); ++it) {
        auto [deg, coef] = *it;
        if (deg == LongNatural::ZERO) {
            result += coef.toString() + " + ";

        } else {
            result += "(" + coef.toString() + ")" + "x^" + deg.toString() + " + ";
        }
    }
    return result.substr(0, result.size() - 3);
}

bool Polynomial::operator==(const Polynomial& other) const {
    return coefficients == other.coefficients && getDegree() == other.getDegree();  // если равны коэффиценты и степени
}

bool Polynomial::operator!=(const Polynomial& other) const {
    return !(*this == other);  // обраное к равентсву
}

Polynomial Polynomial::derivative() const {
    std::map<LongNatural, LongRational> result;
    for (const auto& [deg, coef] : coefficients) {
        if (deg == LongNatural::ZERO) {
            continue;
        }
        result[deg - LongNatural::ONE] = LongRational({coef.getNumerator().isNegative(), deg * coef.getNumerator().getNaturalNumber()}, coef.getDenominator());
    }
    return Polynomial(result);
}

LongRational Polynomial::fact() {
    LongNatural gcf = LongNatural::ZERO;  // Для хранения НОД
    LongNatural lcm = LongNatural::ONE;   // Для хранения НОК
    LongNatural tmp_numerator = LongNatural::ZERO;

    // Проходим по всем коэффициентам многочлена не равным нулю
    for (const auto& [key, value] : coefficients) {
        tmp_numerator = value.getNumerator().abs();  // Временная переменная для получения абсолютного значения числа
        gcf = gcf.gcd(tmp_numerator);                // Считаем НОД всех числителей
        lcm = lcm.lcm(value.getDenominator());  // Считаем НОК всех знаменателей
    }

    LongInteger gcf_long_integer = LongInteger(false, gcf);  // Преобразование натурального в целое число
    LongNatural new_denominatior("1");  // Новый знаменатель будет равен 1, так как из многочлена выносится НОК всех знаменателей

    for (const auto& [key, value] : coefficients) {
        LongInteger new_numerator = value.getNumerator() / gcf_long_integer;    // "Выносим" НОД из числителя
        LongInteger factor = LongInteger(false, lcm / value.getDenominator());  // "Выносим" НОК из знаменателя
        new_numerator *= factor;                                                // Получаем новый числитель
        LongRational new_value = {new_numerator, new_denominatior};  // Новый коэффициент(числитель новый, а знаменатель равен 1)
        coefficients[key] = new_value;                               // Помещаем новый коэффициент в мап
    }

    // Возвращаем вынесенный коффициент
    return LongRational(gcf_long_integer, lcm).red();
}

Polynomial Polynomial::gcf(const Polynomial& other) const {
    Polynomial a = *this;
    Polynomial b = other;
    while (!(b.getDegree() == LongNatural::ZERO && b.getCoef(LongNatural::ZERO) == LongRational::ZERO)) {
        Polynomial tmp = a % b;
        // Если НОД равен единичному многочлену, то возвращаем его
        if (tmp.getDegree() == LongNatural::ZERO && tmp.getCoef(LongNatural::ZERO) != LongRational::ZERO) {
            std::map<LongNatural, LongRational> one_map;
            one_map.emplace(LongNatural::ZERO, LongRational::ONE);
            return Polynomial(one_map);
        }
        a = std::move(b);
        b = std::move(tmp);
    }
    // Возвращаем приведенный многочлен
    LongRational a0 = a.getCoef(a.getDegree());
    a *= (LongRational::ONE / a0);
    return a;
}

LongRational Polynomial::lead() const {
    return getCoef(getDegree());
}

Polynomial Polynomial::nmr() const {
    // Если многочлен - число, возвращаем его же
    if (getDegree() == LongNatural::ZERO) {
        return *this;
    }

    Polynomial derivative = this->derivative();  // Считаем производную многочлена
    Polynomial gcd = this->gcf(derivative);      // Считаем НОД исходного p(x) и его производной
    Polynomial result = *this / gcd;             // Делим p(x) на НОД

    return result;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    std::map<LongNatural, LongRational> result = coefficients;
    for (const auto& [deg, coef] : other.coefficients) {
        result[deg] += coef;
    }
    return Polynomial(result);
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
    for (const auto& [deg, coef] : other.coefficients) {
        coefficients[deg] += coef;
        if (coefficients[deg] == LongRational::ZERO) {
            coefficients.erase(deg);
        }
    }
    return *this;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    std::map<LongNatural, LongRational> result = coefficients;
    for (const auto& [deg, coef] : other.coefficients) {
        result[deg] -= coef;
    }
    return Polynomial(result);
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    for (const auto& [deg, coef] : other.coefficients) {
        coefficients[deg] -= coef;
        if (coefficients[deg] == LongRational::ZERO) {
            coefficients.erase(deg);
        }
    }
    return *this;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    // Создаем нулевой многочлен для результата
    Polynomial result({});

    // Проходим по всем степеням и коэффициентам текущего многочлена
    for (const auto& [degree, coeff] : coefficients) {
        Polynomial term = other * coeff;  // Умножаем второй многочлен на коэффициент из текущего многочлена
        term = term << degree;            // Сдвигаем умноженный многочлен на x^degree
        result = result + term;           // Добавляем полученное произведение к результату
    }

    return result;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
    *this = *this * other;
    return *this;
}

Polynomial Polynomial::operator*(const LongRational& other) const {
    std::map<LongNatural, LongRational> result = coefficients;
    for (auto& [deg, coef] : result) {
        coef *= other;
    }
    return Polynomial(result);
}

Polynomial& Polynomial::operator*=(const LongRational& other) {
    for (auto& [deg, coef] : coefficients) {
        coef *= other;
        if (coef == LongRational::ZERO) {
            coefficients.erase(deg);
        }
    }
    return *this;
}

Polynomial Polynomial::operator/(const Polynomial& other) const {
    // Проверка на единичный многочлен (если divisor == 1, возвращаем dividend)
    if (other.getDegree() == LongNatural::ZERO && other.getCoef(LongNatural::ZERO) == LongRational::ONE) {
        return *this;
    }

    // Результат деления
    std::map<LongNatural, LongRational> res;

    // Степень делимого и делителя
    const LongNatural& deg_divisor = other.getDegree();
    const LongRational& leading_coeff_divisor = other.getCoef(deg_divisor);

    Polynomial remainder = *this;  // Остаток от деления

    // Пока степень остатка >= степени делителя
    while (remainder.getDegree() >= deg_divisor) {  // Используем функцию сравнения
        // Получаем коэффициенты старших членов
        const LongRational& leading_coeff_dividend = remainder.lead();

        // Делим коэффициенты
        LongRational coeff_quotient = leading_coeff_dividend / leading_coeff_divisor;

        // Вычисляем текущую степень частного как разность степеней
        LongNatural degree_diff = remainder.getDegree() - deg_divisor;  // Используем функцию вычитания

        // Добавляем одночлен к частному
        res.emplace(degree_diff, coeff_quotient);

        // Вычитаем произведение (divisor * одночлен) из остатка
        Polynomial product = (other * coeff_quotient) << degree_diff;
        remainder -= product;
    }

    return Polynomial(res);
}

Polynomial& Polynomial::operator/=(const Polynomial& other) {
    *this = *this / other;
    return *this;
}

Polynomial Polynomial::operator%(const Polynomial& other) const {
    Polynomial quotient = *this / other;     // находим частное от деления
    Polynomial product = other * quotient;   // вычисляем произведение divisor * quotient
    Polynomial remainder = *this - product;  // находим остаток: dividend - (divisor * quotient)
    return remainder;
}

Polynomial& Polynomial::operator%=(const Polynomial& other) {
    *this = *this % other;
    return *this;
}

Polynomial Polynomial::operator<<(const LongNatural& n) const {
    std::map<LongNatural, LongRational> result;
    for (const auto& [deg, coef] : coefficients) {
        result[deg + n] = coef;
    }
    return Polynomial(result);
}

Polynomial& Polynomial::operator<<=(const LongNatural& n) {
    for (auto it = coefficients.rbegin(); it != coefficients.rend(); ++it) {
        auto [deg, coef] = *it;
        coefficients[deg + n] = coef;
        coefficients.erase(deg);
    }
    return *this;
}
