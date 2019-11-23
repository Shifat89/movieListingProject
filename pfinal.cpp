#include<bits/stdc++.h>
#include <string>
#include "onlytousemultifile.h"
using namespace std;

//LOGIN(string)
int login()
{
    char username[10],password[10];
    cout<<"Log-in to proceed"<<"-----"<<endl;
    cout<<"ID::";
    cin>>username;
    if(strcmp(username,"Shifat")==0)
    {
        cout<<"Password::";
        cin>>password;
        if(strcmp(password,"abcd1234")==0)
        {
            cout<<"Username & Password matched.ACCESS ACCEPTED."<<endl;
            return 1;
        }
        else
        {
            cout<<"ACCESS DENIED.Try Again."<<endl;
            login();
        }
    }
    else
    {
        cout<<"ACCESS DENIED.Try Again."<<endl;
        login();
    }

}
//Structure
struct date
{
    int day;
    int month;
    int year;
};
string int_to_str(int num)
{
    stringstream ss;

    ss << num;

    return ss.str();
}

int str_to_int(string str)
{
    stringstream ss;
    ss<<str;  //write to ss
    int num;
    ss >> num; //read from ss

    return num;
}
//base class
class movie
{
public:
    string name;
    date D;
    int imdb;
    movie() //o argument constructor
    {
        name[0]='\0';
        D.day=0;
        D.month=0;
        D.year=0;
        imdb=0;
    }
    movie(string s,int d1,int m1,int y1,int r) //multiple argument constructor
    {
        name=s;
        D.day=d1;
        D.month=m1;
        D.year=y1;
        imdb=r;
    }

    void get()
    {
        cout<<"\nMovie Name: ";
        getline(cin,name);
        cout<<"\nRelease Date: ";
        cin>>D.day>>D.month>>D.year;
        cout<<"\nIMBD Rating: ";
        cin>>imdb;
    }

    virtual void show() //virtual function
    {
        cout<<"Movie Name-"<<name<<endl;
        cout<<"Release Date-"<<D.day<<"/"<<D.month<<"/"<<D.year<<endl;
        cout<<"IMDB Rating-"<<imdb<<endl;
    }

    string getst() // to save into a file as a string
    {
        string s;
        s=int_to_str(D.day)+" "+int_to_str(D.month)+" "+int_to_str(D.year)+" "+int_to_str(imdb)+" "+name;
        return s;
    }
};

//inheritance

class drama:public movie
{
public:
    string type;

    void get()
    {
        movie::get();
        getchar();
        cout<<"\nDrama Movie Ending Type(sad/happy/comedy/social issue): ";
        //getchar();
        getline(cin,type);
    }

    string getextra()
    {
        return type;
    }

    void show()
    {
        cout<<"Movie Name-"<<name<<endl;
        cout<<"Release Date-"<<D.day<<"/"<<D.month<<"/"<<D.year<<endl;
        cout<<"IMDB Rating-"<<imdb<<endl;
        cout<<"Ending Type(sad/happy/comedy/social issue)- "<<type<<endl;
    }
};

class war:public movie
{
public:
    string plot;

    void get()
    {
        movie::get();
        getchar();
        cout<<"\nName of the war this movie is based on: ";
        getline(cin,plot);
    }
    string getextra()
    {
        return plot;
    }
    void show()
    {
        cout<<"Name-"<<name<<endl;
        cout<<"Release Date-"<<D.day<<"/"<<D.month<<"/"<<D.year<<endl;
        cout<<"ImDb Rating-"<<imdb<<endl;
        cout<<"Name of the war this movie is based on- "<<plot<<endl;
    }

};

class biography:public movie
{
public:
    string PersonName;

    void get()
    {
        movie::get();
        getchar();
        cout<<"\nThe person this movie is based on: ";
        getline(cin,PersonName);
    }

    string getextra()
    {
        return PersonName;
    }

    void show()
    {
        cout<<"Name-"<<name<<endl;
        cout<<"Release Date-"<<D.day<<"/"<<D.month<<"/"<<D.year<<endl;
        cout<<"ImDb Rating-"<<imdb<<endl;
        cout<<"The person on whom the movie is based on- "<<PersonName<<endl;
    }

};
//use of STL
vector<drama>Dmov;
vector<war>Wmov;
vector<biography>Bmov;
//read from file
void takeDrama()
{
    drama dm;

    FILE * pFile;
    FILE * pFile2;
    pFile=fopen("DramaMovielist.txt","r");
    pFile2=fopen("DramaMovielistextra.txt","r");

    char c[1000];
    char c1[1000];
    while(1)
    {

        if ( fgets (c, 1000, pFile) != NULL )
        {

            fgets (c1, 1000, pFile2);
            stringstream ss(c);
            vector<string>v1;
            string w8outspace;
            while(ss >> w8outspace)
            {
                v1.push_back(w8outspace);
            }

            dm.D.day=str_to_int(v1[0]);
            dm.D.month=str_to_int(v1[1]);
            dm.D.year=str_to_int(v1[2]);
            dm.imdb=str_to_int(v1[3]);

            dm.name=v1[4];
            for(int i=5; i<v1.size(); i++)
            {
                dm.name=dm.name+" "+v1[i];
            }


            dm.type=c1;

            Dmov.push_back(dm);

        }
        else
        {

            break;
        }
    }

    fclose(pFile);

    fclose(pFile2);


}
void takeWar()
{
    war wm;

    FILE *pFile;
    FILE *pFile2;

    pFile=fopen("WarMovielist.txt","r");
    pFile2=fopen("WarMovielistextra.txt","r");

    char c[1000],c1[1000];

    while(1)
    {

        if(fgets(c,1000,pFile)!=NULL)
        {

            fgets(c1,1000,pFile2);

            stringstream ss(c);
            string w8outspace;
            vector<string>v1;
            while(ss>>w8outspace)
            {
                v1.push_back(w8outspace);
            }

            wm.D.day=str_to_int(v1[0]);
            wm.D.month=str_to_int(v1[1]);
            wm.D.year=str_to_int(v1[2]);
            wm.imdb=str_to_int(v1[3]);
            wm.name=v1[4];
            for(int i=5; i<v1.size(); i++)
            {
                wm.name=wm.name+" "+v1[i];
            }

            wm.plot=c1;

            Wmov.push_back(wm);
        }
        else
        {
            break;
        }
    }
    fclose(pFile);
    fclose(pFile2);

}
void takeBio()
{
    biography bm;

    FILE *pFile;
    FILE *pFile2;

    pFile=fopen("BioMovielist.txt","r");
    pFile2=fopen("BioMovielistextra.txt","r");

    char c[1000],c1[1000];

    while(1)
    {
        if(fgets(c,1000,pFile)!=NULL)
        {
            fgets(c1,1000,pFile2);

            stringstream ss(c);
            string w8outspace;
            vector<string>v1;
            while(ss>>w8outspace)
            {
                v1.push_back(w8outspace);
            }

            bm.D.day=str_to_int(v1[0]);
            bm.D.month=str_to_int(v1[1]);
            bm.D.year=str_to_int(v1[2]);
            bm.imdb=str_to_int(v1[3]);
            bm.name=v1[4];
            for(int i=5; i<v1.size(); i++)
            {
                bm.name=bm.name+" "+v1[i];
            }

            bm.PersonName=c1;

            Bmov.push_back(bm);
        }
        else
        {
            break;
        }
    }
    fclose(pFile);
    fclose(pFile2);
}
//SHOW MOVIES

void showDrama()
{

    if(Dmov.size()==0)
    {
        cout<<"List is empty.\n";
        return;
    }
    for(int i=0; i<Dmov.size(); i++)
    {
        cout<<i+1<<". "<<Dmov[i].name<<endl;
    }

    cout<<"Insert movie serial- ";
    int ms;
    cin>>ms;
    cout<<endl;
    cout<<"the movie you picked:"<<ms<<endl;
    for(int i=0; i<Dmov.size(); i++)
    {
        if(ms==i+1)
        {
            movie *m;
            m=&Dmov[i];  //base class pointer=inherited class obj
            m->show();  //  so call goes to inherited class (virtual show)
        }
    }
    cout<<endl;

}

void showWar()
{
    if(Wmov.size()==0)
    {
        cout<<"List is empty\n";
        return;
    }

    for(int i=0; i<Wmov.size(); i++)
    {
        cout<<i+1<<". "<<Wmov[i].name<<endl;
    }

    cout<<"Insert movie serial- ";
    int ms;
    cin>>ms;
    cout<<endl;
    cout<<"the movie you picked:"<<ms<<endl;
    for(int i=0; i<Wmov.size(); i++)
    {
        if(ms==i+1)
        {
            movie *m;

            m=&Wmov[i];
            m->show();  // virtual show
        }
    }
    cout<<endl;
}

void showBio()
{
    if(Bmov.size()==0)
    {
        cout<<"List is empty\n";
        return;
    }

    for(int i=0; i<Bmov.size(); i++)
    {
        cout<<i+1<<". "<<Bmov[i].name<<endl;
    }

    cout<<"Insert movie serial- ";
    int ms;
    cin>>ms;
    cout<<endl;
    cout<<"the movie you picked:"<<ms<<endl;
    for(int i=0; i<Bmov.size(); i++)
    {
        if(ms==i+1)
        {
            movie *m;

            m=&Bmov[i];
            m->show();  //virtual show
        }
    }
    cout<<endl;
}
//INPUT MOVIES
int inputDrama()
{
    drama dm;
    dm.get();
    int flag=0;
    for(int i=0; i<Dmov.size(); i++)
    {
        if(Dmov[i].name==dm.name)
        {
            flag=1;
            break;
        }
    }

    if(flag==0) Dmov.push_back(dm);
    return flag;
}

int inputWar()
{
    war wm;
    wm.get();
    int flag=0;
    for(int i=0; i<Wmov.size(); i++)
    {
        if(Wmov[i].name==wm.name)
        {
            flag=1;
            break;
        }
    }
    if(flag==0) Wmov.push_back(wm);
    return flag;
}

int inputBio()
{
    biography bm;
    bm.get();
    int flag=0;
    for(int i=0; i<Bmov.size(); i++)
    {
        if(Bmov[i].name==bm.name)
        {
            flag=1;
            break;
        }
    }
    if(flag==0) Bmov.push_back(bm);
    return flag;
}
//DELETE MOVIES

void deleteDrama()
{
    if(Dmov.size()==0)
    {
        cout<<"List is empty\n";
        return;
    }
    for(int i=0; i<Dmov.size(); i++)
    {
        cout<<i+1<<". "<<Dmov[i].name<<endl;
    }

    cout<<"Insert movie serial to delete- ";
    int ms;
    cin>>ms;
    cout<<endl;
    for(int i=0; i<Dmov.size(); i++)
    {

        if(ms==i+1)
        {
            Dmov.erase(Dmov.begin()+i);
            cout<<"Deleted\n";
        }
    }
    cout<<endl;
}

void deleteWar()
{
    if(Wmov.size()==0)
    {
        cout<<"List is empty\n";
        return;
    }
    for(int i=0; i<Wmov.size(); i++)
    {
        cout<<i+1<<". "<<Wmov[i].name<<endl;
    }

    cout<<"Insert movie serial to delete- ";
    int ms;
    cin>>ms;
    cout<<endl;
    for(int i=0; i<Wmov.size(); i++)
    {

        if(ms==i+1)
        {
            Wmov.erase(Wmov.begin()+i);
            cout<<"Deleted\n";
        }
    }
    cout<<endl;
}

void deleteBio()
{
    if(Bmov.size()==0)
    {
        cout<<"List is empty\n";
        return;
    }
    for(int i=0; i<Bmov.size(); i++)
    {
        cout<<i+1<<". "<<Bmov[i].name<<endl;
    }

    cout<<"Insert movie serial to delete- ";
    int ms;
    cin>>ms;
    cout<<endl;
    for(int i=0; i<Bmov.size(); i++)
    {

        if(ms==i+1)
        {
            Bmov.erase(Bmov.begin()+i);
            cout<<"Deleted\n";
        }
    }
    cout<<endl;
}
//write into files
void writeDrama()
{
    FILE * pFile;

    pFile=fopen("DramaMovielist.txt","w");
    pFile=fopen("DramaMovielist.txt","a");

    for(int i=0; i<Dmov.size(); i++)
    {
        string temp=Dmov[i].getst();
        char fwca[1000];
        for(int j=0; j<temp.size(); j++)
        {
            fwca[j]=temp[j];
        }

        fwca[temp.size()]='\n';
        fwca[temp.size()+1]='\0';
        fputs(fwca,pFile);
    }

    fclose(pFile);

    pFile=fopen("DramaMovielistextra.txt","w");
    pFile=fopen("DramaMovielistextra.txt","a");

    for(int i=0; i<Dmov.size(); i++)
    {
        string temp=Dmov[i].getextra();
        char fwca[1000];
        for(int j=0; j<temp.size(); j++)
        {
            fwca[j]=temp[j];
        }

        fwca[temp.size()]='\n';
        fwca[temp.size()+1]='\0';
        fputs(fwca,pFile);
    }
    fclose(pFile);
}


void writeWar()
{

    FILE * pFile;

    pFile=fopen("WarMovielist.txt","w");
    pFile=fopen("WarMovielist.txt","a");

    for(int i=0; i<Wmov.size(); i++)
    {
        string temp=Wmov[i].getst();
        char fwca[1000];
        for(int j=0; j<temp.size(); j++)
        {
            fwca[j]=temp[j];
        }

        fwca[temp.size()]='\n';
        fwca[temp.size()+1]='\0';

        fputs(fwca,pFile);
    }
    fclose(pFile);

    pFile=fopen("WarMovielistextra.txt","w");
    pFile=fopen("WarMovielistextra.txt","a");

    for(int i=0; i<Wmov.size(); i++)
    {
        string temp=Wmov[i].getextra();

        char fwca[1000];
        for(int j=0; j<temp.size(); j++)
        {
            fwca[j]=temp[j];
        }
        fwca[temp.size()]='\n';
        fwca[temp.size()+1]='\0';

        fputs(fwca,pFile);
    }
    fclose(pFile);
}


void writeBio()
{
    FILE * pFile;

    pFile=fopen("BioMovielist.txt","w");
    pFile=fopen("BioMovielist.txt","a");

    for(int i=0; i<Bmov.size(); i++)
    {
        string temp=Bmov[i].getst();
        char fwca[1000];
        for(int j=0; j<temp.size(); j++)
        {
            fwca[j]=temp[j];
        }

        fwca[temp.size()]='\n';
        fwca[temp.size()+1]='\0';

        fputs(fwca,pFile);
    }
    fclose(pFile);


    pFile=fopen("BioMovielistextra.txt","w");
    pFile=fopen("BioMovielistextra.txt","a");

    for(int i=0; i<Bmov.size(); i++)
    {
        string temp=Bmov[i].getextra();

        char fwca[1000];
        for(int j=0; j<temp.size(); j++)
        {
            fwca[j]=temp[j];
        }
       fwca[temp.size()]='\n';
        fwca[temp.size()+1]='\0';

        fputs(fwca,pFile);
    }
    fclose(pFile);
}
int main()
{
//to take from the file,read kora

    takeDrama();
    takeWar();
    takeBio();

 useMultiFile();
//login
    int a= login();
    while(1)
    {
        cout<<"****************************************************************************************************\n";
        int flag=0;
        int n,mt;
        cout<<"CHOOSE ANY ONE"<<endl;
        cout<<"(1)Show movie list\n(2)Insert a new movie in the existing list\n";
        cout<<"(3)Delete a movie from the list\n(4)Exit\n";

        cout<<"Your Choice::";
        cin>>n;
        cout<<endl;

        if(n==1) /// show movie
        {
            cout<<"(1)DRAMA Based Movie;\n(2)WAR Based Movie;\n(3)Biography Based Movie;\n";
            cout<<"Your Insertion for Movie type:\t";
            cin>>mt;
            cout<<endl;

            if(mt==1)
            {
                showDrama();
            }
            else if(mt==2)
            {
                showWar();
            }
            else
            {
                showBio();
            }

        }

        else if(n==2) /// insert movie
        {
            cout<<"(1)DRAMA Based Movie;\n(2)WAR Based Movie;\n(3)Biography Based Movie;\n";
            cout<<"Your Insertion for Movie type:\t";
            cin>>mt;
            getchar();
            cout<<endl;

            int p;
            if(mt==1)
            {
                p=inputDrama();
            }
            else if(mt==2)
            {
                p=inputWar();
            }
            else
            {
                p=inputBio();
            }

            if(p==0)cout<<"Inserted\n";
            else cout<<"Already Inserted\n";
        }

        else if(n==3)//delete movie
        {
            cout<<"(1)DRAMA Based Movie;\n(2)WAR Based Movie;\n(3)Biography Based Movie;\n";
            cout<<"Your Insertion for Movie type:\t";
            cin>>mt;
            cout<<endl;

            if(mt==1)deleteDrama();
            if(mt==2)deleteWar();
            if(mt==3)deleteBio();

            cout<<endl;
        }

        else if(n==4)
        {

            writeDrama();
            writeBio();
            writeWar();
            return 0;
        }

    }
}


