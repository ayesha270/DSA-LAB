#include <iostream>
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
    CNode* temp = new CNode;
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

void insert_stu(int SNo, int CNo)
{
    CNode* Ccurr = Clist;

    while (Ccurr != NULL)
    {
        if (Ccurr->CNo == CNo)
        {
            SNode* temp = new SNode;
            temp->SNo = SNo;
            temp->SNext = NULL;

            if (Ccurr->stulist == NULL)
            {
                Ccurr->stulist = temp;
            }
            else
            {
                SNode* Scurr = Ccurr->stulist;
                while (Scurr->SNext != NULL)
                {
                    Scurr = Scurr->SNext;
                }
                Scurr->SNext = temp;
            }
            return;
        }
        Ccurr = Ccurr->CNext;
    }
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
            cout << "  No students enrolled\n";
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

    insert_stu(1, 101);
    insert_stu(2, 101);
    insert_stu(3, 102);
    insert_stu(4, 103);
    insert_stu(5, 103);

    display();

    return 0;
}
