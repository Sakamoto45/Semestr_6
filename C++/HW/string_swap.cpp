#include <string.h>
#include <iomanip>
#include <iostream>
using namespace std;

class String
{
    char *str;
    int n;
    int IsEqual(const String& S) const {
        return strcmp(str, S.str);
    }
    int IsLessThan(const String& S) const {
        return (strcmp(str, S.str)<=0);
    }

public:
    String() {
        n=-1; str=0;
    }
    void swap(String& other) {
        int tmp_n = n;
        n = other.n;
        other.n = tmp_n;
        char *tmp_str = str;
        str = other.str;
        other.str = tmp_str;
    }
    String(int nstr) {
        n = nstr < 0 ? 0 : nstr;
        str = new char[n+1];
        str[n] = 0;
    }
    String(const char* s) {
        n = strlen(s);
        str = new char[n+1];
        strcpy(str, s);
    }
    String(const String& s) {
        n = s.n;
        str = strdup(s.str);
    }
    String(String&& s) {
        this->swap(s);
    }
    ~String() {
        delete[] str;
    }
    char& operator[] (int i) {
        return str[i];
    }
    const char& operator[](int i) const {
        return str[i];
    }
    String& operator = (String s) {
        this->swap(s);
        return *this;
    }
    String& operator += (String& s) {
        String res = String(n + s.n);
        strcpy(res.str, str);
        strcpy(res.str + n, s.str);
        *this = res;
        return *this;
    }
    String operator () (int i, int j) {
        String res = String(j - i);
        for (int k = 0; k < res.n; ++k) {
            res.str[k] = str[i + k];
        }
        return res;
    } //возвращает подстроку
    //operator char*() {return str;} //оператор преобразования типа String к char*
    friend int operator == (const String& s1, const String& s2)
        {return s1.IsEqual(s2);}
    friend int operator < (const String& s1, const String& s2)
        {return s1.IsLessThan(s2);}
    friend int operator != (const String& s1, const String& s2)
        {return !(s1==s2);}
    friend int operator > (const String& s1, const String& s2)
        {return (s2<s1);}
    friend int operator <= (const String& s1, const String& s2)
        {return !(s2<s1);}
    friend int operator >= (const String& s1, const String& s2)
        {return !(s1<s2);}
    friend String operator + (const String& s1, const String& s2) {
        String res = String(s1.n + s2.n);
        strcpy(res.str, s1.str);
        strcpy(res.str + s1.n, s2.str);
        return res;
    }
    friend ostream&  operator << (ostream& out, const String& S)
        { if (S.str) out<< S.str; return out;};
    friend istream&  operator >> (istream& in, String& S) {
        char buffer[256];
        cin >> setw(256) >> buffer;
        S.n = strlen(buffer);
        if (S.n) {
            delete[] S.str;
        }
        S.str = new char[S.n + 1];
        strcpy(S.str, buffer);
        return in;
    }
};


int main() {
    String a(10);
    cout << "input a >> ";
    cin >> a;
    cout << "a = " << a << endl;
    String b("12345");
    cout << "b = " << b << endl;
    String c(b);
    cout << "c = " << c << endl;
    String d(move(c));
    cout << "d = " << d << endl;
    cout << "c = " << c << endl;

    a += b;
    cout << "a = " << a << endl;
    
    cout << "a(2, 4) = " << a(2, 4) << endl;

    cout << "a+b = " << a+b << endl;





    return 0;
}