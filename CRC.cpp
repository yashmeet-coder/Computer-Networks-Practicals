#include <iostream>
using namespace std;

class CRC
{
public:
    string dividend;
    string divisor;
    string answer;
    int l1, l2;

    void input()
    {

        cout << "Enter the message to be transmitted:- ";
        cin >> dividend;
        cout << "Enter the generator function(divisor):- ";
        cin >> divisor;
        l1 = dividend.length();
        l2 = divisor.length();
        for (int i = l1; i < l1 + (l2 - 1); i++)
        {
            dividend += "0";
        }
    }


    string xor_operation(string temp, string div)
    {
        answer = "";
        int n = temp.length();
        for (int i = 1; i < n; i++)
        {
            if (temp[i] == div[i])
                answer += "0";
            else
                answer += "1";
        }
        return answer;
    }

    void divide()
    {
        int count = divisor.length();
        string temporary = dividend.substr(0, count);
        while (count <= dividend.length())
        { 
            if (temporary[0] == '1')
            {
                temporary = xor_operation(temporary, divisor) + dividend[count];
            }
            else
            {
                temporary = xor_operation(temporary, string(count, '0')) + dividend[count];
            }
            count+=1;
        }

    }

    void message()
    {   string delivery="";
        for(int i=0;i<l1;i++)
        {
          delivery+=dividend[i];
        }
        for(int i=0;i<answer.length();i++)
        {
            delivery+=answer[i];
        }
        cout<<"The CRC remainder is:- "<<answer<<endl;
        cout<<"The message to be transmiited:- "<<delivery<<endl;
    }

};

int main()
{
    CRC obj;
    obj.input();
    obj.divide();
    obj.message();
}
