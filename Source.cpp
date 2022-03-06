#include <iostream> 
#include <algorithm> 
#include <string> 
using namespace std;
class HugeInt
{

    friend istream& operator>>(istream&, HugeInt&);
    friend ostream& operator<<(ostream&, const HugeInt&);
    int value1;
    string str1;
public:
    HugeInt() {}
    HugeInt(int value , string str) { value1 = value, str1 = str; }
     HugeInt(int value) { value1 = value; }
     HugeInt(string str) { str1 = str; }

    //copy constructor 
   

    HugeInt(const HugeInt& arg1) { value1 = arg1.value1, str1 = arg1.str1; }
    

    HugeInt operator +(const HugeInt& arg) const
    {
        int size{}, carry;
        HugeInt str;
        int* str3 = new int[size];

        size = (this->value1 > arg.value1) ? this->value1 : arg.value1;
        for (int i{ size - 1 }; i >= 0; --i) {
            if (this->str1[i] - '0' + (arg.str1[i] - '0') > 9) {
                carry = (this->str1[i] - '0') + (arg.str1[i] - '0') % 10 + (str3[i] - '0');
                str3[i - 1] = (this->str1[i] - '0') + (arg.str1[i] - '0') / 10;
                str.str1[i] = (char)carry;
            }
            else {
                carry = (this->str1[i] - '0') + (arg.str1[i] - '0') + (str3[i] - '0');
                str.str1[i] = char(carry);
            }
        }
        return str;

    };
    HugeInt func(string str111, string str222)
    {
        if (str111 == "0" || str222 == "0")
        {
            HugeInt obj(0, "0");
            return obj;
        }

        int x1 = str111.size();
        int x2 = str222.size();
        string str = "";
        int carry = 0;
        int mult;
        string size = (x1 + x2, "0");
        for (int i = x1 - 1; i >= 0; --i)
        {
            for (int j = x2 - 1; j >= 0; --j)

            {
                mult = (str111[i] - '0') * (str222[i] - '0') + size[i + j + 1];
                carry = mult / 10;
                str.push_back(mult % 10 - '0');
                str += carry;
                size[i + j + 1] = mult % 10;
                size[i + j + 1] = mult / 10;
            }
        }
        for (int i = 0; i < size.size(); ++i)
        {
            size[i] += '0';
        }
        if (size[0] == '0')
        {
            HugeInt obj1(stoi(size), size.substr(1));
            return obj1;

        }
    }

    HugeInt operator *(const HugeInt& arg) const
    {
        HugeInt result;
        if (this->str1 == "0" || arg.str1 == "0") {
            return result;
        }
        int size{}, carry;
        HugeInt str;
        int* str3 = new int[size] {1};

        size = (this->value1 > arg.value1) ? this->value1 : arg.value1;
        for (int i{ size - 1 }; i >= 0; --i) {
            if (this->str1[i] - '0' * (arg.str1[i] - '0') > 9) {
                carry = (this->str1[i] - '0') * (arg.str1[i] - '0') % 10 * str3[i];
                str3[i - 1] = (this->str1[i] - '0') * (arg.str1[i] - '0') / 10;
                str.str1[i] = (char)carry;
            }
            else {
                carry = (this->str1[i] - '0') * (arg.str1[i] - '0') * str3[i];
                str.str1[i] = char(carry);
            }
        }
        return str;

    }
};
istream& operator>>(istream& in, HugeInt& a) {
    in >> a.value1 >> a.str1;
    return in;
}

ostream& operator<<(ostream& out, const HugeInt& a) {
    out << a.value1 << endl << a.str1 << endl;
    return out;
}


int main()
{
    HugeInt str1_1, str2_2;
    HugeInt str3_3;
    cin >> str1_1;
    cin >> str2_2;
    cout << str1_1.operator+(str2_2);
    cout << str2_2.operator*(str1_1);
    return 0;
}