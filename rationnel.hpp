#include <iostream>
using namespace std;

class Rationnal {
    private:
        int p;
        int q;
        friend ostream& operator<<(ostream& os, const Rationnal& r);
        friend inline Rationnal simply ();
        friend Rationnal operator+ (const Rationnal& r1, const Rationnal& r2);
        friend Rationnal operator+ (const Rationnal& r, const int i);
        friend inline Rationnal operator- (const Rationnal& r);
        friend inline Rationnal operator * (const Rationnal& r1, const Rationnal& r2);
        friend inline Rationnal operator / (const Rationnal& r1, const Rationnal& r2);
        friend inline bool operator != (const Rationnal& r1, const Rationnal& r2);
        friend inline bool operator < (const Rationnal& r1, const Rationnal& r2);
    public:
        Rationnal (int p, int q);
};

inline Rationnal::Rationnal(int p, int q): p(p),q(q){};
inline ostream& operator<<(ostream& os, const Rationnal& r){
    os << r.p << "/" << r.q;
    return os;
}

inline Rationnal operator+ (const Rationnal& r1, const Rationnal& r2) {
    int new_p = r1.p * r2.q + r1.q * r2.p;
    int new_q = r1.q * r2.q;
    Rationnal res(new_p, new_q);
    return res;
}

inline Rationnal operator+ (const Rationnal& r, const int i) {
    Rationnal res(r.p + i*r.q, r.q);
    return res;
}

inline Rationnal operator- (const Rationnal& r) {
    Rationnal res(-r.p, r.q);
    return res;
}

inline Rationnal operator- (const Rationnal& r1, const Rationnal& r2) {
    Rationnal res = r1 + (-r2);
    return res;
}

inline Rationnal operator * (const Rationnal& r1, const Rationnal& r2) {
    int new_p = r1.p * r2.p;
    int new_q = r1.q * r2.q;
    Rationnal res(new_p, new_q);
    return res;
}

inline Rationnal operator / (const Rationnal& r1, const Rationnal& r2) {
    if (r2.p == 0) throw "Erreur : division par zéro";
    else{
        int new_p = r1.p;
        int new_q = r1.q / r2.p;
        Rationnal res(new_p, new_q);
        return res;
    }
}

inline bool operator < (const Rationnal& r1, const Rationnal& r2) {
    Rationnal res(r1 - r2);
    return res.p < 0;
}

inline bool operator> (const Rationnal& r1, const Rationnal& r2) {
    return (!(r1 < r2) && (r1 != r2));
}

inline bool operator != (const Rationnal& r1, const Rationnal& r2) {
    return (r1.p != r2.p || r1.q != r2.q);
}

inline bool operator == (const Rationnal& r1, const Rationnal& r2) {
    return !(r1 != r2);
}