#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
#include<set>

using namespace std;
class Automates
{

    const int state_max = 30;
    const int a_max = 30;
    int Q = 0;
    int a, q;
    string S[30];
    string S1[30];

    void Input(string str, int integer)
    {
        int b = 0;
        if (integer == 0)
        {
            for (int i = 0; i < str.length(); i++)
            {
                S[i] += str[i];
            }
            a = 1 + b;
        }

        if (integer == 1)
        {
            for (int i = 0; i < str.length(); i++)
            {
                S1[b] += str[i];
            }
            q = 1 + b;
        }
        if (integer == 2)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == 'q')
                    Q++;
            }
        }
    }

    pair<string, int> symb(string str)
    {
        string S1 = " ";
        int Q++;
        int b = str.split(',', 0);
        for (int i = 0; i < str.length(); i++)
        {
            if (i < b && str[i] != ' ') S1 += str[i];
            else if (i >= b)
            {
                b = str.find_first_of('0-9', b + 1);
                i =b;
                Q = 10 * Q + (str[i] - '0');
            }
            
        }
        return pair<string, int>(S1, Q);
    }
    Automates(string str) :a(0), q(0), Q(0)
    {
        int i = 0;
        fstream file;
        file.open(str, ios::in);
    if (file.is_open())
    {
        string k;
        int b = 0;
        int in = 0;
        int q1 = 0;
        while (file >> k)
        {
            if (b < 3) strcpy(k, b++);
            if (b == 3 && k = '|')
            {
                pair<int, string> r(q1, S[in++]);
                table.insert({ r,symb(k) });
                if (in == a - 1)
                {
                    q1 += 1;
                    in = 0;
                }
            }
        }
            file.close();
        }
    }
  
public:
    Automates(string str);
    void print(string str1)
    {

        int st = 0;
        string sub = " ";
        int start = -1, end = -1;
        for (int i = 0; i < str1.length(); i = end)
        {
            start = str1.find_first_not_of(' ', end + 1);
            end = str1.find_first_of(' ', end + 1);
            sub = str1.substr(start, end - start);
            cout << table[{st, sub}].first << " ";
            st = table[{st, sub}].second;
        }
    }

};




int main(int argc, char* argv[]) {

 {

         string str[300];
         
         cin.getline(str, 10);
         Automates h(str);
         string input[300];
         cin.getline(input, 10);
         h.print(input);
    }


