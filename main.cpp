#include <bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<string.h>

using namespace std;

class student
{
    char hno[20];
    string name;
    int pno;
public:
    void createstudent()
    {
        system("cls");
        cout<<"\t\tNEW STUDENT ENTRY\n";
        cout<<"\tENTER HALLTICKET : ";
        cin>>hno;
        cout<<endl;
        cout<<"\tENTER NAME : ";
        cin>>name;
        cout<<endl;
        cout<<"\tENTER CONTACT NO. : ";
        cin>>pno;
        cout<<endl;
        cout<<"\tDATA CREATED";
    }
    void showstudent()
    {
        cout<<"\t\tSTUDENT DETAIL\n";
        cout<<"\tHALL TICKET : "<<hno<<endl;
        cout<<"\tNAME : ";
        cout<<name;
        cout<<endl;
        cout<<"\tCONTACT no. : "<<pno<<endl;
        getch();

    }
    void modifystudent()
    {
        cout<<"\tHALLTICKET NO> : "<<hno<<endl;
        cout<<"\tENTER NAME : ";
        cin>>name;
        cout<<"\tENTER CONTACT NO. : ";
        cin>>pno;
        cout<<endl;
    }
    char* hallno()
    {
        return hno;
    }
    void report()
    {
        cout<<"\t"<<hno<<"                   "<<name<<"               "<<pno<<endl;
    }
};
fstream fp,fp1;
student st;

void rstu()
{
    char ch;
    fp.open("student.dat",ios::out|ios::app);
    do{
        system("cls");
        st.createstudent();
        fp.write((char*)&st,sizeof(student));
        cout<<"\tDO YOU WANT TO ADD MORE RECORD..(y/n)?";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void dispsstu(char n[])
{
    int flag=0;
    fp.open("student.dat",ios::in);

    while(fp.read((char*)&st,sizeof(student))){
        if(strcmp(st.hallno(),n)==0){
            st.showstudent();
            flag=1;
        }
    }
    fp.close();
    if(flag==0){
        cout<<"\tSTUDENT DOESNOT EXISTS\n";
        getch();
    }
}

void modstu()
{
    char n[20];
    int found=0;
    system("cls");
    cout<<"\t\tMODIFY STUDENT RECORD\n";
    cout<<"\tENTER HALL TICKET NO. : ";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&&found==0){
        if(strcmp(st.hallno(),n)==0){
            st.showstudent();
            cout<<"\t\tENTER NEW DETAiLS OF STUDENT"<<endl;
            st.modifystudent();
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(student));
            cout<<"\t\tRECOrd UPDATed\n";
            found=1;
        }
    }
    fp.close();
    if(found==0){
        cout<<"\t\tRECORD NOT FOUND\n";
    }
    getch();
}

void delstu()
{
    char n[20];
    int flag=0;
    system("cls");
    cout<<"\t\tDELETE STUDENT...\n";
    cout<<"\tENTER HALL TICKET NO. : ";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(student))){
        if(strcmp(st.hallno(),n)!=0){
            fp2.write((char*)&st,sizeof(student));
        }
        else{
            flag=1;
        }
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("temp.dat","student.dat");
    if(flag==1){
        cout<<"\t\tRECORD DELETED\n";
    }
    else{
        cout<<"\t\tRECORD NOT FOUND\n";
    }
    getch();
}

void dispastu()
{
    system("cls");
    fp.open("student.dat",ios::in);
    if(!fp){
        cout<<"FILE COULD NOT BE OPEN\n";
        getch();
        return;
    }
    cout<<"\t\tSTUDENT LIST\n";
    cout<<"==========================================================="<<endl;
    cout<<"\tHALLTICKET NO."<<"         "<<"NAME"<<"               "<<"PNO"<<endl;
    cout<<"==========================================================="<<endl;
    while(fp.read((char*)&st,sizeof(student))){
        st.report();
    }
    fp.close();
    getch();
}

void gotoxy(short x, short y)           //definition of gotoxy function//
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void display()
{
    gotoxy(30,10);
    cout<<"PROJECT ON HOSTEL MANAGEMENT";
    gotoxy(30,11);
    cout<<"BY ANKIT THAPA";
    gotoxy(30,12);
    cout<<"loading...";
    gotoxy(30,13);
    for(int i=0;i<=30;i++){
        cout<<"\xB2";
        Sleep(300);
    }
    gotoxy(30,15);
    cout<<"Succefully loaded\n";
    gotoxy(30,16);
    cout<<"press enter";
    getch();
    cout<<endl;
    string username,pass;
    start:
    system("cls");
    gotoxy(40,8);
    cout<<"LOGIN DETAILS";
    gotoxy(25,9);
    cout<<"============================================";
    gotoxy(30,10);
    cout<<"ENTER USERNAME : ";
    cin>>username;
    gotoxy(30,11);
    cout<<"ENTER PASSWORD : ";
    cin>>pass;
    if(username=="Ankit"&&pass=="1234"){
        gotoxy(30,13);
        cout<<"VALIDATION SUCCESfULL\n";
        gotoxy(30,14);
        cout<<"press 'ENTER' to continue\n";
        getch();
    }
    else{
        system("cls");
        gotoxy(30,13);
        cout<<"WRONG USERNAME OR PASSWORD\n";
        gotoxy(30,15);
        cout<<"press 1 to enter again or any other no. to exit : ";
        int n;
        cin>>n;
        if(n==1)
            goto start;
        else
            exit(0);
    }
}

void admin()
{
    start:
    system("cls");
    int inp;
    cout<<"\t\tADMINISTRATOR MENU\n";
    cout<<"\t1. REGISTER STUDENT\n";
    cout<<"\t2. DISPLAY ALL STUDENT RECORD\n";
    cout<<"\t3. DISPLAY SPECFIC STUDENT RECORD\n";
    cout<<"\t4. MODIFY STUDENT RECORD\n";
    cout<<"\t5. DELETE STUDENT RECORD\n";
    cout<<"\t6. PREVIOUS MENU\n";
    cout<<"\tENTER CHOICE(1-6) : ";
    cin>>inp;
    switch(inp)
    {
    case 1:
        rstu();
        break;
    case 2:
        dispastu();
        break;
    case 3:
        char a[20];
        system("cls");
        cout<<"\tENTER HALLTICKET : ";
        cin>> a;
        dispsstu(a);
        break;
    case 4:
        modstu();
        break;
    case 5:
        delstu();
        break;
    case 6:
        return;
    default:
        cout<<"WRONG ENTRY";
        goto start;

    }
    admin();
}



int main()
{
    char ch;
    //displaywellcom();
    display();
    do{
        system("cls");
        cout<<"\t1. Adminstrator menu\n";
        cout<<"\t2. Student detail\n";
        cout<<"\t3. Exit\t"<<endl;
        cout<<"\t";
        ch=getche();
        cout<<endl;
        switch(ch){
    case '1':
        admin();
        break;
    case '2':
        //sdetail();
    case '3':
        exit(0);
    default:
        cout<<"\tWRONG ENTRY";
    }
    }while(ch!='3');

    return 0;
}
