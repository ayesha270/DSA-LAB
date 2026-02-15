#include <iostream>
#include<stdlib.h>
using namespace std;

struct SNode
{
    int SNo;
    SNode* SNext;
};

struct CNode
{
    int CNo;
    CNode* CNext;
    SNode* stulist;   
};

CNode* Clist = NULL;

void insert_course(int CNo)
{
    CNode* temp;
    temp =(CNode*)malloc(sizeof(CNode));
    temp->CNo = CNo;
    temp->CNext = NULL;
    temp->stulist = NULL;

    if (Clist == NULL)
    {
        Clist = temp;
        return;
    }

    CNode* curr = Clist;
    while (curr->CNext != NULL)
    {
        curr = curr->CNext;
    }
    curr->CNext = temp;
}

int main()
{
    insert_course(101);
    insert_course(102);
    insert_course(103);

    cout << "Courses added successfully";
    return 0;
}  
void display()
{
    CNode* Ccurr = Clist;

    while (Ccurr != NULL)
    {
        cout << "Course No: " << Ccurr->CNo << endl;

        SNode* Scurr = Ccurr->stulist;

        if (Scurr == NULL)
        {
            cout << "  No students enrolled" << endl;
        }
        else
        {
            cout << "  Students: ";
            while (Scurr != NULL)
            {
                cout << Scurr->SNo << " ";
                Scurr = Scurr->SNext;
            }
            cout << endl;
        }

        Ccurr = Ccurr->CNext;
    }
}
int main()
{
    insert_course(101);
    insert_course(102);
    insert_course(103);

    display();

    return 0;
}


