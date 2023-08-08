#include<bits/stdc++.h>

using namespace std;
class Schedule;
class Teacher;
class Ct;
class Student
{
    int ID;
    string course_name[10];
    float seperate_mark[10][3]= {0};
    float total_mark[10]= {0};
    string stud_name;
    string enrollment_status;
    string department;
public:
    Student()
    {

    }
    Student(int i);//for input student data
    void output();//for output of student class test
    friend void routine_check(Schedule &s,int ID,string course,string day);
    friend class Schedule;
    friend void sir_ct(Schedule &s);
};


class Teacher
{
    friend class Student;
    int ID;
    int time[10][10];
    string teacher_name;
    string department;
    string course_name;
public:
    Teacher()
    {

    }
    Teacher(int i);//for inputting teacher data
    friend void  tea_sche_check(Schedule &s,int ID,string day);
    friend   void routine_check(Schedule &s,int ID,string course,string day);
    friend class Schedule;
    friend void sir_ct(Schedule &s);
};
class Ct
{
    float date[3];
    string course_name;
public:
    void putdata();//for output of ct date
    friend class Schedule;
    friend void sir_ct(Schedule &s);

};

class Schedule
{
    Teacher about_teacher[10];
    Student about_student[10];
    string day[10];
    Ct about_ct[10];
public:
    void get_teacher_data();
    void get_student_data();
    void get_teacher_class_time();
    friend void  tea_sche_check(Schedule &s,int ID,string day);
    friend void routine_check(Schedule &s,int ID,string course,string day);
    friend void sir_ct(Schedule &s);
    void putdata();//for output of ct date
    void stud_putdata();//for output of student ct part
};
Student :: Student(int i)
{
    cout<<"Student ID=";
    cin>>ID;
    cout<<"Student name=";
    cin>>stud_name;
    cout<<"Student Department=";
    cin>>department;

}


void Student :: output()
{
    cout<<"student name="<<stud_name<<endl;
    for(int i=0; i<2; i++)//2=course number
    {
        cout<<"course _name="<<course_name[i]<<endl;
        cout<<"Seperate mark of ct of "<<" "<<course_name[i]<<" "<<"subject:"<<endl;
        for(int j=0; j<3; j++)
        {
            cout<<"CT"<<" "<<j+1<<" "<<"mark=";
            cout<<seperate_mark[i][j]<<endl;
        }
        cout<<"Total_mark of ct of"<<" "<<course_name[i]<<"subject:"<<" "<<total_mark[i]<<endl;
    }

}
Teacher:: Teacher(int i)
{
    cout<<"Teacher ID=";
    cin>>ID;
    cout<<"Teacher name=";
    cin>>teacher_name;
    cout<<"Teacher department=";
    cin>>department;
    cout<<"Teacher course name=";
    cin>>course_name;

}
void Ct::putdata()
{
    for(int i=0; i<3; i++)
    {
        cout<<"CT"<<" "<<i+1<<":";
        cout<<"date is"<<" "<<date[i]<<"  ";
    }
    cout<<endl;

}


void Schedule::putdata()//for output of ct date
{
    for(int i=0; i<2; i++)
    {
        cout<<"Course name:"<<" "<<about_ct[i].course_name<<endl;
        about_ct[i].putdata();
    }
}
void Schedule::stud_putdata()//for output of student ct part
{
    for(int i=0; i<2; i++)
    {
        about_student[i].output();
    }
}
void  tea_sche_check(Schedule &s,int ID,string day)
{
    int c=0;
    for(int i=0; i<5; i++)
    {
        if(day==s.day[i])
        {
            for(int j=0; j<2; j++)
            {
                if(ID==s.about_teacher[j].ID)
                {
                    if(s.about_teacher[j].time[i][j]>=8 && s.about_teacher[j].time[i][j]<=13 )
                    {
                        cout<<"class time="<<s.about_teacher[j].time[i][j]<<endl;
                        c=1;
                        break;
                    }
                }
            }

        }
        else  if(c==1)
            break;
        else if(i==4)
        {
            cout<<"No class today";
            cout<<endl;
        }
    }
}
void routine_check(Schedule &s,int ID,string course,string day)
{
    int c=0;
    for(int i=0; i<5; i++)
    {

        if(day==s.day[i])
        {
            for(int j=0; j<2; j++)
            {
                if(ID==s.about_student[j].ID)
                {

                    if(course==s.about_teacher[j].course_name)
                    {
                        if(s.about_teacher[j].time[i][j]>=8 && s.about_teacher[j].time[i][j]<=13 )

                        {
                            cout<<"Teacher name="<<s.about_teacher[j].teacher_name<<" "<<"Class time="<<s.about_teacher[j].time[i][j]<<endl;
                            c=1;
                            break;
                        }
                    }

                }
            }
        }
        if(c==1)break;
        else if(i==4)
            cout<<"no class"<<endl;
    }
}
void Schedule::get_teacher_data()

{
    cout<<"How many teacher do you want to add:";
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Information About teacher"<<endl;
        about_teacher[i]=Teacher(i);
        getchar();
    }
}
void Schedule::get_student_data()
{
    cout<<"How many student do you wanr to add:";
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Information About student"<<endl;
        about_student[i]=Student(i);
        getchar();
    }
}
void Schedule:: get_teacher_class_time()
{
    for(int i=0; i<5; i++)
    {
        cout<<"Day of the week:";
        cin>>day[i];
        getchar();
        for(int j=0; j<2; j++)
        {
            cout<<"Time of teacher of "<<" "<<about_teacher[j].teacher_name<<":";
            cin>> about_teacher[j].time[i][j];

        }
    }
    cout<<endl;


}
void sir_ct(Schedule &s)
{
    for(int i=0; i<2; i++)
    {
        s.about_ct[i].course_name=s.about_teacher[i].course_name;
        for(int k=0; k<2; k++)
        {
            s.about_student[i].course_name[k]=s.about_teacher[k].course_name;
        }
    }


    for(int i=0; i<2; i++)
    {

        cout<<"Entering Ct date of"<<" "<<s.about_teacher[i].course_name<<":"<<endl;
        for(int j=0; j<3; j++)
        {
            cout<<"CT"<<" "<<j+1<<":";
            cin>>s.about_ct[i].date[j];
        }
    }

    for(int i=0; i<2; i++)
    {
        for(int l=0; l<2; l++)
        {
            {

                cout<<"Entering "<<" "<<s.about_teacher[l].course_name<<" "<<"CT mark of"<<" "<<s.about_student[i].stud_name<<":"<<endl;
                for(int j=0; j<3; j++)
                {

                    cout<<"CT"<<j+1<<":";
                    cin>>s.about_student[i].seperate_mark[l][j];
                    s.about_student[i].total_mark[l]=s.about_student[i].total_mark[l]+s.about_student[i].seperate_mark[l][j];
                }
            }

        }

    }

}



int main()
{
    Schedule about_schedule;

    int choice;
    int id;

    do
    {
        cout << "\n\n==============================================\n\n";

        cout << "1. Add teacher  information\n";
        cout << "2.Add student  information \n";
        cout << "3. Add teacher class time \n";
        cout << "4. Check teacher class information  \n";
        cout << "5. Check student class information \n";
        cout << "6. Get Sir ct schedule and student mark \n";
        cout << "7. Show sir ct date \n";
        cout<<"8.Show student Ct mark\n";
        cout << "9. Exit \n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
            about_schedule.get_teacher_data();
            break;
        case 2:
            about_schedule.get_student_data();
            break;
        case 3:
            about_schedule.get_teacher_class_time();
            break;
        case 4:
        {
            cout<<"For teacher class information"<<endl;
            int ID;
            string day;
            cout<<"INPUT ID:";
            cin>>ID;
            cout<<"Input the name of the day";
            cin>>day;
            getchar();
            tea_sche_check(about_schedule,ID,day);
            break;
        }


        case 5:
        {
            cout<<"For student class information"<<endl;
            int stud_ID;
            string course;
            string day;
            cout<<"Enter search student id:";
            cin>>stud_ID;
            cout<<"Enter search student course:";
            cin>>course;
            cout<<"Enter search student class day:";
            cin>>day;
            routine_check(about_schedule,stud_ID,course,day);
            break;
        }


        case 6:
            sir_ct(about_schedule);
            break;
        case 7:
            about_schedule.putdata();
            break;
        case 8:
            about_schedule.stud_putdata();
            break;
        case 9:
            cout << "Goodbye. \n\n";
            break;
        default:
            cout << "Invalid choice! \n\n";
            break;
        }
    }
    while (choice != 9);
}

