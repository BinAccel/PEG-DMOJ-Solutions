#include <iostream>
#include <cctype>
#include <string>
using namespace std;
string line;
int num[1000];
int N;
int ori[1000];
int head = 0;
int main()
{
    cin>>N;
    for (int i = 0 ; i < N; i++)
    {
        for (int i= 0 ; i < 1000; i++)
        {
            num[i] = 0;
            ori[i] = 0;
        }
        int length = 0;
        head = 0;
        cin >> line;
        length = line.length();
        for (int i = head; i <length ; i++)
        {
            num[i] = line[i] - '0';
            ori[i] = line[i] - '0';
        }
        int ol = length;
        int last = length-1;
        cout<<line<<endl;
        while (length>2)
        {
                        num[last-1]-=num[last];
                        last-=1;
                        length-=1;
                        for (int j = last; j>=head; j--)
                        {
                            if (num[j]<0)
                            {
                                num[j] = 10 + num[j];
                                num[j-1] -=1;
                            }
                        }
                        if (num[head] == 0)
                        {
                            head++;
                            length-=1;
                        }
                        for (int i = head; i <= last; i++)
                        {
                            cout<<num[i];
                        }
                        cout<<endl;

        }
        cout <<"The number ";
        for (int i = 0 ; i < ol ; i++)
        {
            cout<<ori[i];
        }
        if ((num[head]*10+num[last])%11==0)
        {
            cout<<" is divisible by 11."<<endl;
        }
        else
        {
            cout<<" is not divisible by 11."<<endl;
        }
    }
    return 0;
}