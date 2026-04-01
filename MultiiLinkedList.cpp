#include <iostream>
using namespace std;

struct SNODE {
    int SNo;
    SNODE* SNext;
};

struct CNODE {
    int CNo;
    CNODE* CNNext;
    SNODE* studentlist;
};

CNODE* CList = NULL;

// 1. Add a course
void InsertCourse(int CNo) {
    CNODE* temp = new CNODE;
    temp->CNo = CNo;
    temp->CNNext = NULL;
    temp->studentlist = NULL;

    if (CList == NULL) {
        CList = temp;
    } else {
        CNODE* cur = CList;
        while (cur->CNNext != NULL) {
            cur = cur->CNNext;
        }
        cur->CNNext = temp;
    }
}

// 2. Delete a course (Deleting all students too)
void DeleteCourse(int CNo) {
    CNODE* cur = CList;
    CNODE* prev = NULL;

    while (cur != NULL) {
        if (cur->CNo == CNo) {
            // Delete all students first
            SNODE* stu = cur->studentlist;
            while (stu != NULL) {
                SNODE* temp = stu;
                stu = stu->SNext;
                delete temp;
            }

            // Now remove course node
            if (prev == NULL) {
                CList = cur->CNNext;
            } else {
                prev->CNNext = cur->CNNext;
            }
            delete cur;
            cout << "Course " << CNo << " deleted\n";
            return;
        }
        prev = cur;
        cur = cur->CNNext;
    }
    cout << "Course " << CNo << " not found\n";
}

// 3. Search a course
void SearchCourse(int CNo) {
    CNODE* temp = CList;
    while (temp != NULL) {
        if (temp->CNo == CNo) {
            cout << "Course " << CNo << " found\n";
            return;
        }
        temp = temp->CNNext;
    }
    cout << "Course " << CNo << " not found\n";
}

// 4. Display course list (only course numbers)
void DisplayCourseList() {
    if (CList == NULL) {
        cout << "No courses\n";
        return;
    }
    CNODE* temp = CList;
    while (temp != NULL) {
        cout << "Course: " << temp->CNo << endl;
        temp = temp->CNNext;
    }
}

// 5. Add student to a course
void InsertStudentToCourse(int SNo, int CNo) {
    CNODE* cur = CList;
    while (cur != NULL) {
        if (cur->CNo == CNo) {
            SNODE* newStu = new SNODE;
            newStu->SNo = SNo;
            newStu->SNext = NULL;

            if (cur->studentlist == NULL) {
                cur->studentlist = newStu;
            } else {
                SNODE* last = cur->studentlist;
                while (last->SNext != NULL) {
                    last = last->SNext;
                }
                last->SNext = newStu;
            }
            cout << "Student " << SNo << " added to course " << CNo << endl;
            return;
        }
        cur = cur->CNNext;
    }
    cout << "Course " << CNo << " not found\n";
}

// 6. Delete a student from ALL courses
void DeleteStudentEverywhere(int SNo) {
    CNODE* course = CList;
    bool deleted = false;

    while (course != NULL) {
        SNODE* cur = course->studentlist;
        SNODE* prev = NULL;

        while (cur != NULL) {
            if (cur->SNo == SNo) {
                if (prev == NULL) {
                    course->studentlist = cur->SNext;
                } else {
                    prev->SNext = cur->SNext;
                }
                delete cur;
                deleted = true;
                break;
            }
            prev = cur;
            cur = cur->SNext;
        }
        course = course->CNNext;
    }

    if (deleted) {
        cout << "Student " << SNo << " removed from all courses\n";
    } else {
        cout << "Student " << SNo << " not found\n";
    }
}

// 7. Delete student from specific course
void DeleteStudentFromCourse(int CNo, int SNo) {
    CNODE* course = CList;
    while (course != NULL && course->CNo != CNo) {
        course = course->CNNext;
    }

    if (course == NULL) {
        cout << "Course not found\n";
        return;
    }

    if (course->studentlist == NULL) {
        cout << "No students in this course\n";
        return;
    }

    SNODE* cur = course->studentlist;
    SNODE* prev = NULL;

    while (cur != NULL) {
        if (cur->SNo == SNo) {
            if (prev == NULL) {
                course->studentlist = cur->SNext;
            } else {
                prev->SNext = cur->SNext;
            }
            delete cur;
            cout << "Student " << SNo << " deleted from course " << CNo << endl;
            return;
        }
        prev = cur;
        cur = cur->SNext;
    }
    cout << "Student not found in course " << CNo << endl;
}

// 8. Search student (anywhere)
void SearchStudent(int SNo) {
    CNODE* course = CList;
    bool found = false;

    while (course != NULL) {
        SNODE* temp = course->studentlist;
        while (temp != NULL) {
            if (temp->SNo == SNo) {
                cout << "Student " << SNo << " found in course " << course->CNo << endl;
                found = true;
            }
            temp = temp->SNext;
        }
        course = course->CNNext;
    }

    if (!found) {
        cout << "Student " << SNo << " not found anywhere\n";
    }
}

// 9. Search student in a specific course
void SearchStudentInCourse(int CNo, int SNo) {
    CNODE* course = CList;
    while (course != NULL) {
        if (course->CNo == CNo) {
            SNODE* temp = course->studentlist;
            while (temp != NULL) {
                if (temp->SNo == SNo) {
                    cout << "Student " << SNo << " is in course " << CNo << endl;
                    return;
                }
                temp = temp->SNext;
            }
            cout << "Student " << SNo << " not in course " << CNo << endl;
            return;
        }
        course = course->CNNext;
    }
    cout << "Course " << CNo << " not found\n";
}

// 10. Display students in one course
void DisplayStudentsInCourse(int CNo) {
    CNODE* course = CList;
    while (course != NULL) {
        if (course->CNo == CNo) {
            cout << "Course " << CNo << " students: ";
            SNODE* temp = course->studentlist;
            if (temp == NULL) {
                cout << "none\n";
                return;
            }
            while (temp != NULL) {
                cout << temp->SNo << " ";
                temp = temp->SNext;
            }
            cout << endl;
            return;
        }
        course = course->CNNext;
    }
    cout << "Course " << CNo << " not found\n";
}

// 11. Display All 
void DisplayAll() {
    if (CList == NULL) {
        cout << "No courses\n";
        return;
    }

    CNODE* course = CList;
    while (course != NULL) {
        cout << "Course: " << course->CNo << " → Students: ";
        SNODE* stu = course->studentlist;
        if (stu == NULL) {
            cout << "none";
        } else {
            while (stu != NULL) {
                cout << stu->SNo << " ";
                stu = stu->SNext;
            }
        }
        cout << endl;
        course = course->CNNext;
    }
}


int main() {
    int choice, cno, sno;

    do {
        cout << "\n1. Add course\n";
        cout << "2. Delete course\n";
        cout << "3. Search course\n";
        cout << "4. Display course list\n";
        cout << "5. Add student to course\n";
        cout << "6. Delete student everywhere\n";
        cout << "7. Delete student from course\n";
        cout << "8. Search student\n";
        cout << "9. Search student in course\n";
        cout << "10. Display students in course\n";
        cout << "11. Display All\n";
        cout << "12. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter course no: "; cin >> cno;
                InsertCourse(cno);
                break;
            case 2:
                cout << "Enter course no: "; cin >> cno;
                DeleteCourse(cno);
                break;
            case 3:
                cout << "Enter course no: "; cin >> cno;
                SearchCourse(cno);
                break;
            case 4:
                DisplayCourseList();
                break;
            case 5:
                cout << "Course no: "; cin >> cno;
                cout << "Student no: "; cin >> sno;
                InsertStudentToCourse(sno, cno);
                break;
            case 6:
                cout << "Student no: "; cin >> sno;
                DeleteStudentEverywhere(sno);
                break;
            case 7:
                cout << "Course no: "; cin >> cno;
                cout << "Student no: "; cin >> sno;
                DeleteStudentFromCourse(cno, sno);
                break;
            case 8:
                cout << "Student no: "; cin >> sno;
                SearchStudent(sno);
                break;
            case 9:
                cout << "Course no: "; cin >> cno;
                cout << "Student no: "; cin >> sno;
                SearchStudentInCourse(cno, sno);
                break;
            case 10:
                cout << "Course no: "; cin >> cno;
                DisplayStudentsInCourse(cno);
                break;
            case 11:
                DisplayAll();
                break;
            case 12:
                cout << "Goodbye\n";
                break;
            default:
                cout << "Wrong choice\n";
        }
    } while (choice != 12);

    return 0;
}
