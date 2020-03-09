#include <iostream>
#include <stdlib.h>
using namespace std;

struct pile
{
    int weight;
    pile *next;
};


void Del(pile* del);//�������� �������
                    //��������� ��������� �� ������
int Protect();      //�������� �����
                    //���������� ����������� ��������


int main()
{
    setlocale(LC_ALL, "Rus");  //���������� ������� �����������

    int     i, j;               //��������
    int     quan = 0;           //���������� ������
    int     buf;                //������������� ���������� ��� ������������
    float   sum1 = 0, sum2 = 0; //���� ���
    pile    *pile1=NULL, *cur1; //��������� �� ������ � ������� �������� ������ ����
    pile    *pile2=NULL, *cur2; //��������� �� ������ � ������� �������� ������ ����
    char    answer;

    for(;;)                 //� �������� ����������
    {
        pile1=NULL;
        pile2=NULL;
        sum1 = 0;
        sum2 = 0;


        cout<<"������� ������?"<<endl;
        quan = Protect();

        int *rocks = new int[quan];         //�������� ������� �����
        cout<<"������� ���� ������"<<endl;
        for (i = 0; i < quan; i++)
        {
            rocks[i] = Protect();
        }

        for (int j = quan-1; j > 0; j--)                //���������� �� ��������
        {
            for (i = j; i >= 0; i--)
            {
                if (rocks[(i-1)/2] > rocks[i])
                {
                    buf = rocks[i];
                    rocks[i] = rocks[(i-1)/2];
                    rocks[(i-1)/2] = buf;
                }
            }
            buf = rocks[0];
            rocks[0] = rocks[j];
            rocks[j] = buf;
        }

        for (i = 0; i < quan; i++) //��������� ������ �� 2 ����
        {
            if(sum1 <= sum2) //��������� ����� � �� ����, ��� ������� ������
            {
                if(pile1 == NULL)
                {
                    pile1 = new pile;
                    cur1 = pile1;
                }
                else
                {
                    cur1->next = new pile;
                    cur1 = cur1->next;
                }
                cur1->weight = rocks[i];
                sum1 = sum1 + rocks[i];
            }
            else
            {
                if(pile2 == NULL)
                {
                    pile2 = new pile;
                    cur2 = pile2;
                }
                else
                {
                    cur2->next = new pile;
                    cur2 = cur2->next;
                }
                cur2->weight = rocks[i];
                sum2 = sum2 + rocks[i];
            }
        }
        if(pile1) cur1->next = NULL;
        if(pile2) cur2->next = NULL;

        delete[] rocks;

        if((sum1 == 0)||( sum2 == 0))
        {
            cout<<"����������";
        }
        else if(((sum1/sum2) > 2)||((sum2/sum1) > 2))
        {
            cout<<"����������";
        }
        else
        {
            cur1 = pile1;
            cout<<endl;
            while(cur1)
            {
                cout<<cur1->weight<<' ';
                cur1 = cur1->next;
            }

            cout<<endl;
            cur2 = pile2;
            while(cur2)
            {
                cout<<cur2->weight<<' ';
                cur2 = cur2->next;
            }
        }
        if(pile1) Del(pile1);
        if(pile2) Del(pile2);

        cout<<endl<<"���� ������� ����������, ������� 'y'. ��� �������� ��������� ������� ����� ������ ������"<<endl;
        cin>>answer;
        if(answer != 'y')break;
        system("cls");
    }
}

int Protect()
{
    int x;
    for(;;)
    {
        cin>>x;
        if (cin.fail()==true)           //���� ����������� ������
        {
            cin.clear();                //�������������� ������
        }
        for(;;)                         //������ ������ �������
        {
            if(cin.get()=='\n')break;
        }
        if(x > 0) break;                //������� �� �����, ���� ������� ������������� �����
        cout<<"����������, ������� ������ ������������� �����"<<endl;
    }
    return x;
}

void Del(pile* cur)
{
    pile* del;
    while (cur)
    {
        del = cur;
        cur = cur->next;
        delete del;
    }
}
