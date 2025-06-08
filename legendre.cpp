
#include <iostream>
#include <vector>
#include <cmath>

// 检查是否为素数
bool isPrime(long long p) {
    if (p <= 1) return false;
    if (p == 2) return true;
    if (p % 2 == 0) return false;
    for (long long i = 3; i * i <= p; i += 2) {
        if (p % i == 0) return false;
    }
    return true;
}

// 模运算，保持非负
long long mod(long long a, long long p) {
    a %= p;
    if (a < 0) a += p;
    return a;
}

// 计算勒让德符号 (a/p)
long long legendreSymbol(long long a, long long p) {
    // 验证 p 是否为奇素数
    if (!isPrime(p) || p % 2 == 0) {
        std::cerr << "Error: p must be an odd prime!" << std::endl;
        return 0;
    }

    // 如果 a ≡ 0 (mod p)，返回 0
    a = mod(a, p);
    if (a == 0) return 0;

    long long result = 1;

    // 处理 a = -1
    if (a < 0) {
        a = -a;
        // ( -1/p ) = (-1)^((p-1)/2)
        if ((p - 1) / 2 % 2 == 1) result *= -1;
    }

    // 分解 a 为素因子
    std::vector<long long> factors;
    long long temp = a;
    for (long long i = 2; i * i <= temp; ++i) {
        while (temp % i == 0) {
            factors.push_back(i);
            temp /= i;
        }
    }
    if (temp > 1) factors.push_back(temp);

    // 计算每个素因子的勒让德符号
    for (long long q : factors) {
        if (q == 2) {
            // ( 2/p ) = (-1)^((p^2-1)/8)
            long long exponent = (p * p - 1) / 8;
            if (exponent % 2 == 1) result *= -1;
        } else {
            // 使用二次互反律: (q/p) * (p/q) = (-1)^((p-1)/2 * (q-1)/2)
            long long exponent = ((p - 1) / 2) * ((q - 1) / 2);
            long long sign = (exponent % 2 == 0) ? 1 : -1;
            // 计算 (p/q) 递归调用
            long long reciprocal = legendreSymbol(p, q);
            result *= sign * reciprocal;
        }
    }

    return result;
}

int main() {
    long long a, p;
    std::cout << "Enter integer a: ";
    std::cin >> a;
    std::cout << "Enter odd prime p: ";
    std::cin >> p;

    long long result = legendreSymbol(a, p);
    std::cout << "Legendre symbol (" << a << "/" << p << ") = " << result << std::endl;

    return 0;
}

