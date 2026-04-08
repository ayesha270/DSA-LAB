
    #include <iostream>
using namespace std;

/* ---------------- STRUCTURES ---------------- */

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

/* ---------------- COURSE FUNCTIONS ---------------- */

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
        curr = curr->CNext;

    curr->CNext = temp;
}

CNode* search_course(int CNo)
{
    CNode* curr = Clist;
    while (curr)
    {
        if (curr->CNo == CNo)
            return curr;
        curr = curr->CNext;
    }
    return NULL;
}

void delete_course(int CNo)
{
    CNode *curr = Clist, *prev = NULL;

    while (curr && curr->CNo != CNo)
    {
        prev = curr;
        curr = curr->CNext;
    }

    if (!curr)
    {
        cout << "Course not found\n";
        return;
    }

    if (!prev)
        Clist = curr->CNext;
    else
        prev->CNext = curr->CNext;

    SNode* s = curr->stulist;
    while (s)
    {
        SNode* temp = s;
        s = s->SNext;
        delete temp;
    }

    delete curr;
    cout << "Course deleted\n";
}

void display_courses()
{
    CNode* curr = Clist;
    if (!curr)
    {
        cout << "No courses available\n";
        return;
    }

    while (curr)
    {
        cout << "Course No: " << curr->CNo << endl;
        curr = curr->CNext;
    }
}

/* ---------------- STUDENT FUNCTIONS ---------------- */

void add_student_to_course(int CNo, int SNo)
{
    CNode* course = search_course(CNo);
    if (!course)
    {
        cout << "Course not found\n";
        return;
    }

    SNode* temp = new SNode;
    temp->SNo = SNo;
    temp->SNext = course->stulist;
    course->stulist = temp;

    cout << "Student added successfully\n";
}

void delete_student_from_course(int CNo, int SNo)
{
    CNode* course = search_course(CNo);
    if (!course)
    {
        cout << "Course not found\n";
        return;
    }

    SNode *curr = course->stulist, *prev = NULL;

    while (curr && curr->SNo != SNo)
    {
        prev = curr;
        curr = curr->SNext;
    }

    if (!curr)
    {
        cout << "Student not found in this course\n";
        return;
    }

    if (!prev)
        course->stulist = curr->SNext;
    else
        prev->SNext = curr->SNext;

    delete curr;
    cout << "Student deleted from course\n";
}

bool search_student(int SNo)
{
    CNode* c = Clist;
    while (c)
    {
        SNode* s = c->stulist;
        while (s)
        {
            if (s->SNo == SNo)
                return true;
            s = s->SNext;
        }
        c = c->CNext;
    }
    return false;
}

bool search_student_in_course(int CNo, int SNo)
{
    CNode* c = search_course(CNo);
    if (!c) return false;

    SNode* s = c->stulist;
    while (s)
    {
        if (s->SNo == SNo)
            return true;
        s = s->SNext;
    }
    return false;
}

void display_students_in_course(int CNo)
{
    CNode* c = search_course(CNo);
    if (!c)
    {
        cout << "Course not found\n";
        return;
    }

    SNode* s = c->stulist;
    if (!s)
    {
        cout << "No students in this course\n";
        return;
    }

    cout << "Students in course " << CNo << ": ";
    while (s)
    {
        cout << s->SNo << " ";
        s = s->SNext;
    }
    cout << endl;
}

void display_all()
{
    CNode* c = Clist;
    if (!c)
    {
        cout << "No data available\n";
        return;
    }

    while (c)
    {
        cout << "\nCourse No: " << c->CNo << endl;
        SNode* s = c->stulist;

        if (!s)
            cout << "  No students\n";
        else
        {
            cout << "  Students: ";
            while (s)
            {
                cout << s->SNo << " ";
                s = s->SNext;
            }
            cout << endl;
        }
        c = c->CNext;
    }
}

/* ---------------- EXIT FUNCTION ---------------- */

void exit_program()
{
    CNode* c = Clist;
    while (c)
    {
        SNode* s = c->stulist;
        while (s)
        {
            SNode* tempS = s;
            s = s->SNext;
            delete tempS;
        }

        CNode* tempC = c;
        c = c->CNext;
        delete tempC;
    }

    Clist = NULL;
    cout << "Program exited safely\n";
}

/* ---------------- MAIN (MENU) ---------------- */

int main()
{
    int choice, CNo, SNo;

    do
    {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert Course\n";
        cout << "2. Delete Course\n";
        cout << "3. Search Course\n";
        cout << "4. Display Courses\n";
        cout << "5. Add Student to Course\n";
        cout << "6. Delete Student from Course\n";
        cout << "7. Search Student\n";
        cout << "8. Search Student in Course\n";
        cout << "9. Display Students in Course\n";
        cout << "10. Display All\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter course number: ";
            cin >> CNo;
            insert_course(CNo);
            break;

        case 2:
            cout << "Enter course number: ";
            cin >> CNo;
            delete_course(CNo);
            break;

        case 3:
            cout << "Enter course number: ";
            cin >> CNo;
            if (search_course(CNo))
                cout << "Course found\n";
            else
                cout << "Course not found\n";
            break;

        case 4:
            display_courses();
            break;

        case 5:
            cout << "Enter course number and student number: ";
            cin >> CNo >> SNo;
            add_student_to_course(CNo, SNo);
            break;

        case 6:
            cout << "Enter course number and student number: ";
            cin >> CNo >> SNo;
            delete_student_from_course(CNo, SNo);
            break;

        case 7:
            cout << "Enter student number: ";
            cin >> SNo;
            if (search_student(SNo))
                cout << "Student found\n";
            else
                cout << "Student not found\n";
            break;

        case 8:
            cout << "Enter course number and student number: ";
            cin >> CNo >> SNo;
            if (search_student_in_course(CNo, SNo))
                cout << "Student found in course\n";
            else
                cout << "Student not found in course\n";
            break;

        case 9:
            cout << "Enter course number: ";
            cin >> CNo;
            display_students_in_course(CNo);
            break;

        case 10:
            display_all();
            break;

        case 0:
            exit_program();
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}



 
