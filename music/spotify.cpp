#include<iostream>
#include<fstream>
#include<string.h>
#include<map>
#include<vector>
#include <algorithm>
#include <windows.h>
//#include <initializer_list>
#define stringify( name ) # name
using namespace std;
enum COLUMNINDEX{THEME,TITLE,ARTIST,YEAR,SPOTIFY_URL};

COLUMNINDEX GetColumINdex(string user_column_name)
{


    map<string,COLUMNINDEX > mymap ;
    mymap["THEME"]=THEME;
    mymap["TITLE"]=TITLE;
    mymap["ARTIST"]=ARTIST;
    mymap["YEAR"]=YEAR;
    mymap["SPOTIFY_URL"]=SPOTIFY_URL;



    return mymap.find(user_column_name)->second;


}

vector<vector< string> > GetColumValue(ifstream & r)
{
        string user_col_name,user_col_value;
        int no_records_perPage;
        cout<<"Please enter the column to search(Theme,Title,Artist or Year) : ";
        cin>>user_col_name;
        transform(user_col_name.begin(), user_col_name.end(), user_col_name.begin(), ::toupper);
        int col_index=GetColumINdex(user_col_name);

        cout<<"Please enter the value in the "<<'"'<<user_col_name<<'"'<<" column to locate : ";
        cin>>user_col_value;
        cout<<"Please enter the maximum number of records to display per page(1 to 100) : "<<endl;
        cin>>no_records_perPage;
        cout<<"....Searching column"<<user_col_name<<" for iteam "<<'"'<<user_col_value<<'"'<<endl;

        transform(user_col_value.begin(), user_col_value.end(), user_col_value.begin(), ::toupper);

    vector<vector< string> > record ;
    string record_values[5];
    int counter =0;
    char stop;
    int page_no=0;
    while(r.good())
    {
        //cout<<"hyi 1"<<endl;
        for(int i=0;i<4;i++)
        getline(r,record_values[i],',');
        getline(r,record_values[4],'\n');
        transform(record_values[col_index].begin(), record_values[col_index].end(), record_values[col_index].begin(), ::toupper);
        //cout<<user_col_value<<endl;
        //cout<<record_values[col_index]<<endl;
       if(!(user_col_value.compare(record_values[col_index])))
       {
           //cout<<"hyi 2"<<endl;
           vector<string > x;

           x.push_back(record_values[1]);
           x.push_back(record_values[2]);
           x.push_back(record_values[3]);
           x.push_back(record_values[4]);
           record.push_back(x);
           counter++;
          // cout<<"hyi 1"<<endl;
        }
       if(counter==no_records_perPage)
       {
           //cout<<"hyi 4"<<endl;
           cout<<counter<<endl;
           for(int i=0;i<counter;i++)
           {
               //cout<<"hyi 5"<<endl;
               cout<<"TITLE : "<<record[page_no+i][0]<<endl;
               cout<<"ARTIST : "<<record[page_no+i][1]<<endl;
               cout<<"YEAR : "<<record[page_no+i][2]<<endl;
               cout<<endl;
           }
           page_no++;
           cout<<"Press any key to continue or x to Stop"<<endl;
           cin>>stop;

           if(stop=='x')
           {
          //     cout<<"hyi 5"<<endl;
               return record ;
           }
           else
           {
                counter=0;
                cout<<"hyi 6"<<endl;
           }

       }

    }

}

string GetSpotifyURL(vector<vector< string> > record ,int x)
{
    x--;
    for(int i = 0; i < record.size(); ++i)
    {
        {
            if(x==i)
                return record[i][3];
        }

    }
}
void LaunchSpotify(string url)
{

    if(!url.empty())
    {
        char c;
        cout<<"Attempt to go to Specify on exit(y/n)?"<<endl;
        cin>>c;
        if(c=='y')
                ShellExecuteA(NULL, NULL,url.c_str(), NULL, NULL , SW_SHOWNORMAL );
        else
            cout<<"Thank  you for using"<<endl;
    }


    else
        cout<<"Sorry!!! There is no link"<<endl;

}
int main()
{
    vector<vector< string> > record ;
    int record_no;
    ifstream ip("1000songs.csv");
    if(!ip.is_open())
        cout<<"Error : in Opening the file."<<endl;
    else
    {
    string col_name[5];
        if(ip.good())
        {
            for(int i=0;i<4;i++)
            getline(ip,col_name[i],',');
            getline(ip,col_name[4],'\n');
        }
        ifstream &temp_ip=ip;
        record=GetColumValue(temp_ip);
        cout<<"Choose Record No :"<<endl;
        cin>>record_no;
        string url=GetSpotifyURL(record,record_no);
        cout<<url<<endl;
        LaunchSpotify(url);
    }


}
