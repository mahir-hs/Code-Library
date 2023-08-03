using T = __int128;
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) {
    return x == y;
}

template<typename T>
T extendedEuclid(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    T x1, y1;
    T g = extendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

/// x = (a1*m2*q + a2*m1*p) % lcm(m1, m2)
template<typename T>
pair<T, T> ChineseRemainderTheorem(T a1, T m1, T a2, T m2) {
    T p, q;
    T g = extendedEuclid(m1, m2, p, q);
    if (a1 % g != a2 % g) return pair<T, T>(0, -1);
    T m = (m1 / g) * m2;
    p = (p % m + m) % m;
    q = (q % m + m) % m;

    return pair<T, T>(((((a1 * q) % m) * (m2 / g)) % m + (((a2 * p) % m) * (m1 / g)) % m) % m, m); /// returns {x, m}, m = lcm(m1, m2)
}
