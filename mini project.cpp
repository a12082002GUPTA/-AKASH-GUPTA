#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
using namespace std;
class employee
{
   string name;
   int code;
   string address;
   string contact;
   string date;
   string designation;
   string grade;
   long int loan;
   long int salary;
   long int house_allowance;
   int days;
   int hours;
   long int net_allowance;
   public:
       void add_member()
       {
           fflush(stdin);
           cout<<"enter employee name\n";
           getline(cin,name);
           cout<<"enter employee code\n";
           cin>>code;
           fflush(stdin);
           cout<<"enter employee address\n";
           getline(cin,address);
           cout<<"enter contact number of the employee\n";
           cin>>contact;
         fflush(stdin);
           cout <<"enter date of joining date of employee\n";
           getline(cin,date);
           fflush(stdin);
           cout<<"enter designation of the employee\n";
           getline(cin,designation);
           fflush(stdin);
           cout<<"enter grade of the employee\n";
           cin>>grade;
           cout<<"enter loan given to the employee\n";
           cin>>loan;
           cout<<"enter salary given to the employee\n";
           cin>>salary;
           cout<<"enter house allowance of the employee\n";
           cin>>house_allowance;
       }
       void display()
       {    cout<<"NAME IS - "<<name;
            cout<<"\n";
            cout<<"EMPLOYEE CODE IS "<<code;
            cout<<"\n";
            cout<<"ADDRESS IS "<<address;
            cout<<"\n";
            cout<<"CONTACT NUMBER IS "<<contact;
            cout<<"\n";
            cout<<"joining date is "<<date;
            cout<<"\n";
            cout<<"DESIGNATION IS "<<designation;
            cout<<"\n";
            cout<<"GRADE OF EMPLOYEE IS "<<grade;
            cout<<"\n";
            cout<<"LOAN GIVEN TO EMPLOYEE IS "<<loan;
            cout<<"\n";
            cout<<"SALARY OF EMPLOYEE IS "<<salary;
            cout<<"\n";
            cout<<"HOUSE ALLOWANCE GIVEN IS "<<house_allowance;
       }
       void storeDetails()
       {
           ofstream of;
           of.open("Employee Details.dat",ios::app|ios::binary);
           of.write((char*)this,sizeof(*this));
           of.close();
       }
       void readDetails()
       {
           ifstream If;
           int flag=0;
           If.open("Employee Details.dat",ios::in|ios::binary);
           If.read((char*)this,sizeof(*this));
           while(!If.eof())
           {
               display();
               If.read((char*)this,sizeof(*this));
               cout<<"\n-------------------------------------------------------------\n";
               flag++;


}
if(flag==0)
{
    cout<<"NO RECORD IS THERE\n";
}

If.close();
}
void search(int ch)
{
    int count=0;
    ifstream of;
    of.open("Employee Details.dat",ios::in|ios::binary);
    of.read((char*)this,sizeof(*this));
    while(!of.eof())
    {
        if(ch==code)
        {
            display();
            count++;
        }
        of.read((char*)this,sizeof(*this));
    }
    of.close();
      if(count==0)
            cout<<"no record found";
}
void delete_employee(int ch)
{
    ifstream fin;
        ofstream fout;
        int flag=0;
        fin.open("Employee Details.dat",ios::in|ios::binary);
        fout.open("tempfile.dat",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(ch!=code)
            {
              fout.write((char*)this,sizeof(*this));
            }
            else
                flag++;
            fin.read((char*)this,sizeof(*this));
        }
       fin.close() ;
       fout.close();
       if(flag==0)
        cout<<"employee not found\n";
       else
        cout<<"employee successfully deleted\n";
       remove("Employee Details.dat");
       rename("tempfile.dat","Employee Details.dat");
}

  void update(int ch)
  {
      fstream file;
      int flag=0;
      file.open("Employee Details.dat",ios::in|ios::out|ios::ate|ios::binary);
      file.seekg(0);
      file.read((char*)this,sizeof(*this));
      while(!file.eof())
      {
         if(ch==code)
          {
              add_member();
              file.seekp(file.tellp()-sizeof(*this));
              file.write((char*)this,sizeof(*this));
              flag++;
          }
          file.read((char*)this,sizeof(*this));
      }
      if(flag==0)
      {
          cout<<"employee not found\n";
      }
      else
      {
          cout<<"updation completed";
      }
      file.close();
  }
  void display1()
  {
    do{
      cout<<"NO OF WORKING DAYS OF EMPLOYEE IN A MONTH ARE:- ";
      cin>>days;
      cout<<"\n";
      cout<<"No of over time hours are:- ";
      cin>>hours;
      cout<<"\n";
      net_allowance=house_allowance+salary+(30-days)*50+hours*1000;
      system("cls");
      cout<<"NAME IS - "<<name;
      cout<<"\n";
      cout<<"EMPLOYEE CODE- "<<code;
      cout<<"\n";
      cout<<"NO OF WORKING DAYS OF EMPLOYEE IN A MONTH ARE:- "<<days<<"\n";
      cout<<"salary given is "<<salary<<"\n";
      cout<<"net salary is"<<net_allowance<<"\n";
    }while(0);
  }
  void print(int ch)
  {
      ifstream file;
      int flag=0;
      file.open("Employee Details.dat",ios::in|ios::binary);
      file.read((char*)this,sizeof(*this));
      if(!file)
        cout<<"file not exist";
      while(!file.eof())
      {
          if(ch==code)
          {
              display1();
              flag++;
          }
          file.read((char*)this,sizeof(*this));
      }
      file.close();
      if(flag==0)
      {
          cout<<"employee not found\n";
      }
      else
      {
          cout<<"printing completed";
      }

  }
};
int main()
{
    employee emp;
    int x,ch,chs;
    while(1){
           abc: cout<<"------------EMPLOYEE DETAILS-------------\n ";
    cout<<"enter 1 to add to new employee\n";
    cout<<"enter 2 to modify employee record\n";
    cout<<"enter 3 to delete a record\n";
    cout<<"enter 4 to print a employee salary slip\n";
    cout<<"enter 5 to display a employee record\n";
    cout<<"enter 6 to display all employees record \n";
    cin>>x;
    switch(x)
    {
    case 1:    system("cls");
             emp.add_member();
             emp.storeDetails();
             system("cls");
             break;
    case 2:
        system("cls");
         cout<<"enter employee you want to update: ";
    cin>>ch;
    emp.update(ch);
     cout<<"\n1.home page\n";
             cout<<"2.exit\n";
             cin>>chs;
             switch(chs)
             {
                 case 1:  system("cls");
                     goto abc;
                break;
                  case 2: exit(0);
             }
    break;
    case 3: system("cls");
    cout<<"enter employee you want to remove: ";
    cin>>ch;
    emp.delete_employee(ch);
    cout<<"\n1.home page\n";
             cout<<"2.exit\n";
             cin>>chs;
             switch(chs)
             {
                 case 1:  system("cls");
                     goto abc;
                break;
                  case 2: exit(0);
             }
    break;
    case 4:
        system("cls");
        cout<<"enter employee for whom you want to print salary: ";
    cin>>ch;
    emp.print(ch);
    cout<<"\n1.home page\n";
             cout<<"2.exit\n";
             cin>>chs;
             switch(chs)
             {
                 case 1:  system("cls");
                     goto abc;
                break;
                  case 2: exit(0);
             }
      break;
    case 5:
         system("cls");
        cout<<"enter employee code you want to search : ";
        cin>>ch;
            emp.search(ch);
            cout<<"\n1.home page\n";
             cout<<"2.exit\n";
             cin>>chs;
             switch(chs)
             {
                 case 1:  system("cls");
                     goto abc;
                break;
                  case 2: exit(0);
             }
            break;
    case 6:
           system("cls");
            emp.readDetails();
            cout<<"1.home page\n";
             cout<<"2.exit\n";
             cin>>chs;
             switch(chs)
             {
                 case 1:  system("cls");
                     goto abc;
                break;
                  case 2: exit(0);
             }
            break;
    }
}
}
