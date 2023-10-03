#include<bits/stdc++.h>
#include<fstream>
#include<string>
//abstract class,polymorphism,operator overloading using friend,inheritance,template
using namespace std;
class customer;
class employee;
class bank;
class security;
int size=10;




template<class T>
void details(T &a);
class bank
{
public:
    virtual void showdetails()=0;
    //template<class T>
    //friend void details(T &a);
};


class security:public bank

{

    int username;
    string password;

public:
    security()
    {

    }
    security(int s,string s1)
    {
        username=s;
        password=s1;
        // cout<<  username<<" "<< password<<endl;
    }

    void passwordchange(string s)
    {
        password=s;
    }

    int getuser()
    {
        return username;
    }
    string getpass()
    {
        return password;

    }

    void showdetails() {}
    template<class T>
    friend void details(T &a);
};

class customer:public security
{
    string name;
    string address;
    string mobile_number;
    int money;
    string fullFileName;
public:
    customer()
    {

    }

    customer(int s3,string s2,string s,string s1,string a,int a1):security(s3,s2)
    {

        name=s;
        address=s1;
        mobile_number=a;
        money=a1;
        string fileName = "customer";
        string extension = ".txt";
        int user;
        user=getuser();


        // Concatenate the file name components into a single string
        fullFileName = fileName + to_string(user) + extension;
        //  cout << "File name: " << fullFileName << endl;
        ofstream file;
        file.open(fullFileName,ios::out);
        file<<"Name="<<name<<endl;
        file<<"Address="<<address<<endl;
        file<<"Mobile Number="<<mobile_number<<endl;
        file<<"Money="<<money<<endl;
        file.close();

    }
    string filename()
    {
        return fullFileName;
    }
    int getmoney()
    {
        return money;
    }
    void setmoney(int d)
    {
        money=d;
        string fileName = "customer";
        string extension = ".txt";
        int user;
        user=getuser();


        // Concatenate the file name components into a single string
        string fullFileName = fileName + to_string(user) + extension;
        // cout << "File name: " << fullFileName << endl;
        ofstream file;
        file.open(fullFileName,ios::out);
        file<<"Name="<<name<<endl;
        file<<"Address="<<address<<endl;
        file<<"Mobile Number="<<mobile_number<<endl;
        file<<"Money="<<money<<endl;
        file.close();
    }

    void showdetails()
    {
        string fileName = "customer";
        string extension = ".txt";
        int  user;
        user=getuser();

        // Concatenate the file name components into a single string
        string fullFileName = fileName + to_string(user) + extension;
        // cout << "File name: " << fullFileName << endl;
        ifstream file;
        cout<<"Showing individual information of customer ID="<<getuser()<<endl;
        file.open(fullFileName,ios::in);
        while(file)
        {
            char n[50];
            file.getline(n,50);
            cout<<n<<endl;

        }
        file.close();
    }
    template<class T>
    friend void details(T &a);
    friend void get(int k,int l);
    friend void enteringinformation(int k,int l);

};


class employee:public customer
{

    int username;
    string password;
    string name;
    string address;
    string mobile_number;
    // int money;
    string fullFileName;
    int payment;

public:
    employee()
    {

    }
    void getemp()//to create a employee file
    {

        string fileName = "employee";
        string extension = ".txt";



        // Concatenate the file name components into a single string
        string fullFileName = fileName + to_string(username) + extension;
        //cout << "File name: " << fullFileName << endl;
        ofstream file;
        file.open(fullFileName,ios::out);
    }
    friend  void enteringinformation(int k,int l);
    friend void get(int k,int l);
    int getuser()
    {
        return username;
    }
    string getpassword()
    {
        return password;
    }
    string getname()
    {
        return name;
    }
    string getaddress()
    {
        return address;
    }
    string getmobile()
    {
        return mobile_number;
    }
    int getpayment()
    {
        return payment;
    }
    void putpayment(int a)
    {
        payment=a;
    }
    void showdetails()
    {
        string fileName = "employee";
        string extension = ".txt";
// Concatenate the file name components into a single string
        fullFileName = fileName + to_string(username) + extension;
        //  cout << "File name: " << fullFileName << endl;
        ifstream file;
        file.open(fullFileName,ios::in);
        cout<<"Showing All customer information from employee="<<username <<endl;
        while(file)
        {
            char n[50];
            file.getline(n,50);
            cout<<n<<endl;

        }
        file.close();

    }
    //friend void get(int k,int l);
    friend istream & operator >>(istream &,employee &);



};
istream & operator >>(istream &din,employee &e)
{

    cout<<"Please give the information:"<<endl;
    cout<<"Your username can only be digit"<<endl;
    cout<<"username=";
    din>>e.username;
    while(1)
    {
        cout<<"password=";
        din>>e.password;
        int length;
        length=e.password.size();
        if(length<8)
        {
            cout<<"Your password is so weak give another password"<<endl;
        }
        else
            break;
    }
    cout<<"Your Account Has been created as a employee"<<endl;
    cout<<"Now fill up the below information"<<endl;
    cout<<"Name=";
    cin>>e.name;

    cout<<"Address=";
    cin>>e.address;

    cout<<"Payment=";
    cin>>e.payment;

    while(1)
    {
        cout<<"Mobile Number=";
        cin>>e.mobile_number;
        if(e.mobile_number.size()<11)
            cout<<"Invalid Mobile Number";
        else
            break;

    }
    return (din);
}

class manager:public employee
{
    int userid;
    string password;
    string  fullFileName;
public:
    friend void enteringinformation(int k,int l);
    friend istream & operator >>(istream &,manager &);
    void getman()//to create a employee file
    {

        string fileName = "manager";
        string extension = ".txt";



        // Concatenate the file name components into a single string
        string fullFileName = fileName + to_string(userid) + extension;
        //cout << "File name: " << fullFileName << endl;
        ofstream file;
        file.open(fullFileName,ios::out);
    }
    int username()
    {
        return userid;
    }
    string getpass()
    {
        return password;
    }
    void showdetails()
    {
        string fileName = "manager";
        string extension = ".txt";


        // Concatenate the file name components into a single string
        fullFileName = fileName + to_string(userid) + extension;
        //  cout << "File name: " << fullFileName << endl;
        ifstream file;
        file.open(fullFileName,ios::in);
        cout<<"Showing All employee & customer information" <<endl;
        while(file)
        {
            char n[50];
            file.getline(n,50);
            cout<<n<<endl;

        }
        file.close();

    }




};
istream & operator >>(istream &din,manager &m)
{
    cout<<"Please give the information:"<<endl;
    cout<<"Your username can only be digit"<<endl;
    cout<<"username=";
    din>>m.userid;
    while(1)
    {
        cout<<"password=";
        din>>m.password;
        int length;
        length=m.password.size();
        if(length<8)
        {
            cout<<"Your password is so weak give another password"<<endl;
        }
        else
            break;
    }
    cout<<"Your Account Has been created as a manager"<<endl;
    return (din);

}
template<class T>
void details(T *a)
{
    a->showdetails();
}
customer cust_omer[100];
employee emp_loyee[100];
manager mana_ger;
void get(int k,int l)//k=employee,l==customer
{
    for(int j=1; j<k; j++)
    {

        string fileName = "employee";
        string extension = ".txt";



        // Concatenate the file name components into a single string
        string fullFileName = fileName + to_string(emp_loyee[j].getuser()) + extension;
        //cout << "File name: " << fullFileName << endl;
        ofstream file;
        ifstream file1;
        file.open(fullFileName,ios::out);

        for(int i=1; i<l; i++)
        {

            int n;
            n=cust_omer[i].getuser();
            // cout<<n<<endl;
            file<<"ID="<<n<<endl;
            string s=cust_omer[i].filename();
//cout<<s<<endl;
            file1.open(s);
            while(file1)
            {
                char ch;
                file1.get(ch);
                file.put(ch);
            }
            file1.close();

        }

        file.close();

    }


}

void enteringinformation(int k,int l)//k=employee,l==customer
{
    string fileName = "manager";
    string extension = ".txt";



    // Concatenate the file name components into a single string
    string fullFileName = fileName + to_string(mana_ger.username()) + extension;
    //cout << "File name: " << fullFileName << endl;
    ofstream file2;
    ifstream file1;
    file2.open(fullFileName,ios::out);

    for(int j=1; j<k; j++)
    {
        file2<<"Information of employee" <<j<<endl;
        file2<<"Username="<<emp_loyee[j].getuser()<<endl;
        //file<<"Password"<<emp_loyee[j].getpassword()<<endl;
        file2<<"Name="<<emp_loyee[j]. getname()<<endl;
        file2<<"Address="<<emp_loyee[j].  getaddress()<<endl;
        file2<<"Mobile="<<emp_loyee[j].  getmobile()<<endl;
        file2<<"Payment="<<emp_loyee[j].  getpayment()<<endl;
    }


    for(int i=1; i<l; i++)
    {
        file2<<"Information of customer "<<i<<endl;

        int n;
        n=cust_omer[i].getuser();
        // cout<<n<<endl;
        file2<<"ID="<<n<<endl;
        string s=cust_omer[i].filename();
//cout<<s<<endl;
        file1.open(s);
        while(file1)
        {
            char ch;
            file1.get(ch);
            file2.put(ch);
        }
        file1.close();

    }
    file2.close();

}
int main()
{

    int choice;


    static int emp=1;
    int man=1;
    bank *cus[size];
    bank *empl[size];
    bank *manag;
    static  int cust=1;

    int username;
    string password;
    string name;
    string address;
    string mobile_number;
    int deposit;
    int withdraw;
    manag=&mana_ger;


    while(1)
    {
        cout<<"    **************PRIME BANK*************"<<endl;
        cout<<"    1.Create an account"<<endl;
        cout<<"    2.If you have any created account ,please login "<<endl;

        cout<<"What do you want=";
        cin>>choice;
        if(choice==1)
        {
            cout<<"     1.As a Manager"<<endl;
            cout<<"     2.As a Employee"<<endl;
            cout<<"     3.As a customer "<<endl;
            cout<<"Enter your choice:"<<endl;
            int choice1;
            cin>>choice1;
            if(choice1==1)
            {
                cin>>mana_ger;
                cout<<endl;
                mana_ger.getman();
                //putting the information of customer in the employee
            }
            else if(choice1==2)
            {
                cin>>emp_loyee[emp];
                cout<<endl;
                //putting the information of customer in the employee
                emp_loyee[emp].getemp();


                get(emp,cust);
                enteringinformation(emp,cust);
                emp++;
                for(int i=1; i<emp; i++)
                {
                    empl[i]=&emp_loyee[i];
                }

            }
            else if(choice1==3)
            {
                cout<<"Please give the information:"<<endl;
                cout<<"Your username can only be digit"<<endl;
                cout<<"username=";
                cin>>username;
                while(1)
                {
                    cout<<"password=";
                    cin>>password;
                    int length;
                    length=password.size();
                    if(length<8)
                    {
                        cout<<"Your password is so weak give another password"<<endl;
                    }
                    else
                        break;
                }
                cout<<"Your Account Has been created as a customer"<<endl;
                cout<<"Now fill up the below information"<<endl;
                cout<<"Name=";
                cin>>name;

                cout<<"Address=";
                cin>>address;
                cout<<"Money=";
                cin>>deposit;
                while(1)
                {
                    cout<<"Mobile Number=";
                    cin>> mobile_number;
                    if(mobile_number.size()<11)
                        cout<<"Invalid Mobile Number";
                    else
                        break;

                }
//cust_omer[cust].signup(username,password);
                cust_omer[cust]=customer(username,password,name,address,mobile_number,deposit);
                cust++;
                for(int i=1; i<cust; i++)
                {
                    cus[i]=&cust_omer[i];
                }
                enteringinformation(emp,cust);
                get(emp,cust);


            }

        }
        else if(choice==2)
        {
            cout<<"    1.As a customer"<<endl;
            cout<<"    2.As a employee"<<endl;
            cout<<"    3.As a Manager"<<endl;
            int choice2;
            cout<<"Enter your choice:";
            cin>>choice2;
            if(choice2==1)
            {


                while(1)
                {
                    cout<<"Enter your username:";
                    cin>>username;
                    cout<<"Enter your password:";
                    cin>>password;
                    for(int i=1; i<cust; i++)
                    {
                        if(cust_omer[i].getuser()==username && cust_omer[i].getpass()==password)
                        {

                            cout<<"    1.Want to change password"<<endl;
                            cout<<"    2.Want to deposit money"<<endl;
                            cout<<"    3.Want to withdraw money"<<endl;
                            cout<<"    4.Want to transfer money"<<endl;
                            cout<<"    5.Want to show information"<<endl;

                            int choice3;
                            cout<<"Enter your choice:";
                            cin>>choice3;

                            if(choice3==1)
                            {
                                cout<<"Enter your new password:";
                                cin>>password;
                                cust_omer[i].passwordchange(password);
                                cout<<"Your Password is successfully changed"<<endl;

                            }
                            else if(choice3==2)
                            {
                                int D;
                                D=cust_omer[i].getmoney();
                                cout<<"Enter your deposited amount:";
                                cin>>deposit;
                                D=D+deposit;
//cout<<D<<endl;
                                cust_omer[i].setmoney(D);
                                enteringinformation(emp,cust);
                                get(emp,cust);


                            }
                            else if(choice3==3)
                            {
                                int D;
                                D=cust_omer[i].getmoney();
                                cout<<"Enter your withdraw amount:";
                                cin>>withdraw;
                                D=D-withdraw;
//cout<<D<<endl;
                                if(D>=50)
                                {
                                    cust_omer[i].setmoney(D);
                                    enteringinformation(emp,cust);
                                    get(emp,cust);
                                }
                                else
                                    cout<<"Your withdrawal may not occur"<<endl;

                            }
                            else if(choice3==4)
                            {
                                int D;
                                int newamount;
                                cout<<"Enter transfer amount of money:";
                                cin>>D;
                                newamount=cust_omer[i].getmoney()-D;


                                if(newamount>50)
                                {
                                    cust_omer[i].setmoney(newamount);
                                    cout<<"Enter your transfered username:";
                                    cin>>username;

                                    for(int i=1; i<cust; i++)
                                    {
                                        if(cust_omer[i].getuser()==username)
                                        {

                                            newamount=D+cust_omer[i].getmoney();
//cout<<D<<endl;
                                            cust_omer[i].setmoney(newamount);
                                        }
                                    }
                                    enteringinformation(emp,cust);
                                    get(emp,cust);
                                }
                                else
                                    cout<<"Transaction cannot be held";
                            }
                            else if(choice3==5)
                            {
                                details<bank>(cus[i]);
                            }
                        }

                        else if(i==(cust-1))
                        {
                            cout<<"No user exist and enter a valid username"<<endl;
                        }
                        break;
                    }
                    break;

                }
            }
            else if(choice2==2)
            {
                //cout<<"Showing customer information"<<endl;
                cout<<"Please give the below information for display your customer details information"<<endl;
                while(1)
                {
                    cout<<"Enter your username:";
                    cin>>username;
                    cout<<"Enter your password:";
                    cin>>password;

                    for(int i=1; i<emp; i++)
                    {
                        cout<< emp_loyee[i].getuser()<<endl;
                        cout<< emp_loyee[i].getpassword()<<endl;
                        if(  emp_loyee[i].getuser()==username &&   emp_loyee[i].getpassword()==password)
                        {
                            details<bank>(empl[i]);

                        }
                        else if(i==(emp-1))
                        {
                            cout<<"No ID match";
                            break;
                        }

                    }

                    break;


                }
            }
            else if(choice2==3)
            {
                cout<<"1.Want to increase or decrease employee payment"<<endl;
                cout<<"2.Want to know employee and customer information"<<endl;
                int choice5;
                cout<<"Enter your choice:";
                cin>>choice5;
                if(choice5==1)
                {

                    cout<<"Give employee username :";
                    cin>>username;
                    cout<<"1.For increment"<<endl;
                    cout<<"2.For decrement"<<endl;
                    int choice6;
                    cout<<"Enter your choice:";
                    cin>>choice6;
                    if(choice6==1)
                        for(int i=0; i<emp; i++)
                        {
                            {
                                if(emp_loyee[i].getuser()==username)
                                {
                                    int amount;
                                    cout<<"Enter the amount:";
                                    cin>>amount;
                                    amount=amount+emp_loyee[i].getpayment();
                                    emp_loyee[i].putpayment(amount);
                                    enteringinformation(emp,cust);

                                }
                            }
                        }
                    else if(choice6==2)
                        for(int i=0; i<emp; i++)
                        {
                            {
                                if(emp_loyee[i].getuser()==username)
                                {
                                    int amount;
                                    cout<<"Enter the amount:";
                                    cin>>amount;
                                    amount=emp_loyee[i].getpayment()-amount;
                                    emp_loyee[i].putpayment(amount);
                                    enteringinformation(emp,cust);

                                }
                            }
                        }
                }
                else if(choice5==2)
                {
                    cout<<"Please give the below information for display your employee and customer details information"<<endl;
                    while(1)
                    {
                        cout<<"Enter your username:";
                        cin>>username;
                        cout<<"Enter your password:";
                        cin>>password;


                        if(  mana_ger.username()==username &&  mana_ger.getpass()==password)
                        {
                            details<bank>(manag);

                        }
                        else
                        {
                            cout<<"No ID match";
                        }


                        break;


                    }

                }
            }
            else
                cout<<"No option match"<<endl;





        }
        else

        {

            cout<<"You are left  from bank website";
            break;
        }
    }





}
