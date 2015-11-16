#include <string>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <fstream>


using namespace std;

struct Student
{
	string first_name;

        string last_name;
	string email;
	string number;
};

class ContactList
{
public:
    void show_lines();
    void contact_menu(Student *, int);
    void contact_display(Student *, int);
    void contact_add(Student *, int);
    void contact_delete(Student *, int);
    void contact_modify(Student *, int);
    void contact_end(string, string);
    void contact_sort(Student *, int);
    void contact_search(Student *, int);
};

class ReadWrite
{
public:
    int counter(string);
    string setcontent(string, int,int,int);
    void write(Student *, int);


};
ReadWrite rrr;///class definition for the read and write functions of the file.
ContactList ret;///One class definition for the whole file///

void ContactList::contact_search(Student *sets, int length)
{
    cout<<"Enter your search criteria"<<endl;
    string check;
        cin>>check;
        cout<<endl;
        bool notfound = true;
        while (notfound)
        {
            for ( int i = 0; i < length; i++)
            {
                if (((check[0] == sets[i].first_name[0]) && (check[1] == sets[i].first_name[1]))||((check[0] == sets[i].last_name[0]) && (check[1] == sets[i].last_name[1]))||((check[0] == sets[i].email[0]) && (check[1] == sets[i].email[1]))||((check[0] == sets[i].number[0]) && (check[1] == sets[i].number[1])) )
                {
                    cout<<"were you looking for "<<sets[i].first_name<<" "<<sets[i].last_name<<"?"<<endl;
                    char choice;
                    cout<<"Y/N: ";
                    cin>>choice;
                    if (choice == 'Y' || choice == 'y')
                    {
                        cout<<sets[i].first_name<<endl;
                        cout<<sets[i].last_name<<endl;
                        cout<<sets[i].number<<endl;
                        cout<<sets[i].email<<endl;
                        notfound = false;
                    }
                else cout<<". . ."<<endl;

                    notfound = true;
                    break;
                }


            }
            notfound = false;
        }
        system("Pause");
        system("cls");
    ret.contact_menu(sets, length);

}

void ContactList::contact_delete(Student * sets, int length)
{
    ret.show_lines();
    for ( int i = 0 ; i < length ; i++)
    {
        cout<<i+1<<": "<<sets[i].first_name<<", "<<sets[i].last_name<<endl;
        cout<<endl;
    }

    int choice;
    cout<<"Which one would you like to delete?"<<endl;
    cin>>choice;
    int newlength = length-1;

    delete &sets[choice-1];
    rrr.write(sets, newlength);
            system("Pause");
        system("cls");

    ret.contact_menu(sets, newlength);


}

void ContactList::contact_modify(Student * sets, int length)
{
            ret.show_lines();
for ( int i = 0 ; i < length ; i++)
{
    cout<<i+1<<": "<<sets[i].first_name<<", "<<sets[i].last_name<<endl;
        cout<<endl;
}
int choice;
    cout<<"Which one would you like to modify?"<<endl;
    cin>>choice;

    string newfirst;
    string newlast;
    string newnumber;
    string newemail;

    cout<<"New first: ";
    cin>>newfirst;
    cout<<endl;
    cout<<"New Last: ";
    cin>>newlast;
    cout<<endl;
    cout<<"New number: ";
    cin>>newnumber;
    cout<<endl;
    cout<<"New email: ";
    cin>>newemail;
    cout<<endl;

    sets[choice-1].first_name = newfirst;
    sets[choice-1].last_name = newlast;
    sets[choice-1].email = newemail;
    sets[choice-1].number = newnumber;

rrr.write(sets, length);
        system("Pause");
        system("cls");
    ret.contact_menu(sets, length);

}
void ContactList::show_lines()
{
    for (int i = 0; i < 25; i ++ )
    {
        cout<<"~";
        Sleep(65);
    }cout<<endl;

}

void ContactList::contact_end(string first, string second)
{

        for (int i = 0; i < first.length(); i ++ )
    {
        cout<<first[i];
        Sleep(65);
    }cout<<endl;
    cout<<endl;
    for (int j = 0 ; j < second.length(); j ++)
    {
        cout<<second[j];
        Sleep(65);
    }cout<<endl;
            system("Pause");
        system("cls");

}

void ContactList::contact_add(Student * sets, int length)
{
    cout<<"Adding a Contact"<<endl;
    Student* newsets = new Student[25];
    for (int i = 0; i < length; i ++)
    {
        newsets[i].first_name=sets[i].first_name;
        newsets[i].last_name=sets[i].last_name ;
        newsets[i].email=sets[i].email;
        newsets[i].number=sets[i].number ;
    }

    for (int j = length; j < length+1; j ++)
    {
        cout<<"First Name: ";
        cin>>newsets[j].first_name;
        cout<<"Last Name: ";
        cin>>newsets[j].last_name;
        cout<<"Number: ";
        cin>>newsets[j].number;
        cout<<"Email: ";
        cin>>newsets[j].email;
    }

    delete[] sets;

int newlength = length +1;
rrr.write(newsets, newlength);
        system("Pause");
        system("cls");
ret.contact_display(newsets, newlength);

}

void ContactList::contact_menu(Student * sets, int length)
{
    int choice;
    cout<<"Contact List - Main Menu"<<endl<<endl;
    ret.show_lines();
    cout<<"[1] Show All Contacts"<<endl;
    cout<<"[2] Add a Contact"<<endl;
    cout<<"[3] Delete a Contact"<<endl;
    cout<<"[4] Modify a contact"<<endl;
    cout<<"[5] Sort and View "<<endl;
    cout<<"[6] Search Contact List"<<endl;
    cout<<"[7] Close Contact List"<<endl;
    cout<<"Choice: ";
    cin>> choice;
    system("Pause");
    system("cls");


    cout<<endl;

    switch (choice)
    {
    case 1:
        {
        ret.contact_display(sets, length);
        break;
        }
    case 2:
        {
        ret.contact_add(sets, length);
        system("Pause");

        break;
        }
    case 3:
        {
        cout<<"[3] Delete a Contact"<<endl;
        ret.contact_delete(sets, length);
        break;
        }
    case 4:
        {
        cout<<"[4] Modify a contact"<<endl;
        ret.contact_modify(sets, length);
        break;
        }
    case 5:
        {
        cout<<"[5] Sort and View"<<endl;
        ret.contact_sort(sets, length);
        break;
        }
    case 6:
        {
            cout<<"Search Contact List"<<endl;
            ret.contact_search(sets, length);
            break;
        }
    default:
        {
        cout<<"[7] Close Contact List"<<endl;
        string bye= "End of My Program";
        string by= "Benjamin Horn";
        ret.contact_end(bye, by);
        system("Pause");
        system("cls");
        break;
        }
    }

}

void ContactList::contact_display(Student * sets, int length)
{
    cout<<"Displaying all Contacts"<<endl<<endl;
    ret.show_lines();
    for ( int i = 0 ; i < length ; i++)
    {
        cout<<"Contact: "<<i+1<<endl;
        cout<<sets[i].first_name<<endl;
        cout<<sets[i].last_name<<endl;
        cout<<sets[i].number<<endl;
        cout<<sets[i].email<<endl;
        cout<<endl;
}

    ret.show_lines();
        system("Pause");
        system("cls");
ret.contact_menu( sets, length);

}


void ContactList::contact_sort(Student * sets1, int length)//incredibly inefficient
{

    ret.show_lines();
    cout<<"choose what to view by"<<endl;
    cout<<"[1] first"<<endl;
    cout<<"[2] last"<<endl;
    cout<<"[3] email"<<endl;
    cout<<"[4] number"<<endl;
    int choice;
    cout<<"Choice: ";
    cin>>choice;
    cout<<endl;


string tempfirst;
string templast;
string tempnumber;
string tempemail;


switch(choice)
{
case 1:
    {
        cout<<"Sorting by First name . . ."<<endl;
            	for(int i=0; i< (length - 1); ++i)
	{
		for(int j = i + 1; j > 0; --j)
		{
			if(sets1[j].first_name < sets1[j-1].first_name)
			{
				//Swaps the values
				tempfirst = sets1[j].first_name;
				templast = sets1[j].last_name;
				tempemail = sets1[j].email;
				tempnumber = sets1[j].number;

				sets1[j].first_name = sets1[j - 1].first_name;
				sets1[j].last_name = sets1[j - 1].last_name;
				sets1[j].email = sets1[j - 1].email;
				sets1[j].number = sets1[j - 1].number;

				sets1[j - 1].first_name = tempfirst;
				sets1[j-1].last_name = templast;
				sets1[j - 1].email = tempemail;
				sets1[j-1].number = tempnumber;
			}

		}
	}
    break;
    }

case 2:
    {
        cout<<"sorting by last name. . ."<<endl;
            	for(int i=0; i< (length - 1); ++i)
	{
		for(int j = i + 1; j > 0; --j)
		{
			if(sets1[j].last_name < sets1[j-1].last_name)
			{
				//Swaps the values
				tempfirst = sets1[j].first_name;
				templast = sets1[j].last_name;
				tempemail = sets1[j].email;
				tempnumber = sets1[j].number;

				sets1[j].first_name = sets1[j - 1].first_name;
				sets1[j].last_name = sets1[j - 1].last_name;
				sets1[j].email = sets1[j - 1].email;
				sets1[j].number = sets1[j - 1].number;

				sets1[j - 1].first_name = tempfirst;
				sets1[j-1].last_name = templast;
				sets1[j - 1].email = tempemail;
				sets1[j-1].number = tempnumber;
			}

		}
	}
    break;
    }
case 3:
    {
        cout<<"sorting by email . . . "<<endl;

            	for(int i=0; i< (length - 1); ++i)
	{
		for(int j = i + 1; j > 0; --j)
		{
			if(sets1[j].email < sets1[j-1].email)
			{
				//Swaps the values
				tempfirst = sets1[j].first_name;
				templast = sets1[j].last_name;
				tempemail = sets1[j].email;
				tempnumber = sets1[j].number;

				sets1[j].first_name = sets1[j - 1].first_name;
				sets1[j].last_name = sets1[j - 1].last_name;
				sets1[j].email = sets1[j - 1].email;
				sets1[j].number = sets1[j - 1].number;

				sets1[j - 1].first_name = tempfirst;
				sets1[j-1].last_name = templast;
				sets1[j - 1].email = tempemail;
				sets1[j-1].number = tempnumber;
			}

		}
	}
    break;
    }

case 4:

    {
        cout<<"sorting  by number . . ."<<endl;
             	for(int i=0; i< (length - 1); ++i)
	{
		for(int j = i + 1; j > 0; --j)
		{
			if(sets1[j].number < sets1[j-1].number)
			{
				//Swaps the values
				tempfirst = sets1[j].first_name;
				templast = sets1[j].last_name;
				tempemail = sets1[j].email;
				tempnumber = sets1[j].number;

				sets1[j].first_name = sets1[j - 1].first_name;
				sets1[j].last_name = sets1[j - 1].last_name;
				sets1[j].email = sets1[j - 1].email;
				sets1[j].number = sets1[j - 1].number;

				sets1[j - 1].first_name = tempfirst;
				sets1[j-1].last_name = templast;
				sets1[j - 1].email = tempemail;
				sets1[j-1].number = tempnumber;
			}

		}
	}
    break;
    }


}


	cout<<endl;
    cout<<"Sorted List"<<endl;
	for (int z = 0; z < 5; z ++)
    {
        cout<<z+1<<endl;
        cout<<sets1[z].first_name<<endl;
        cout<<sets1[z].last_name<<endl;
        cout<<sets1[z].number<<endl;
        cout<<sets1[z].email<<endl;
    }

        system("Pause");

        system("cls");

    rrr.write(sets1, length);
ret.contact_menu(sets1, length);


}

int ReadWrite::counter(string filename)
{
int entries;
string line;
  ifstream myfile (filename.c_str());
  if (myfile.is_open())
  {
      cout<<"Contacts Opened Successfully"<<endl;

    for ( entries = 0; getline(myfile, line); entries++)
    {
    }

    if (entries == 0)
    {
        cout<<"No current contacts, start by adding some"<<endl;
    }

    return entries;
    myfile.close();
  }
  else cout << "Unable to open Contact List File"<<endl;

}

string ReadWrite::setcontent(string filename,int entries, int selection, int which)
{
    string content[entries];
string line;
ifstream myfile (filename.c_str());

  if (myfile.is_open())
  {

    for ( entries = 0; getline(myfile, line); entries++ )
    {
        content[entries]=line;
    }
    myfile.close();
  }

    string arr[4];///this splits it up and return appropriate value
    int i = 0;
    stringstream str(content[selection]);
    while (str.good() && i < 4)
    {
        str >> arr[i];
        ++i;
    }
return arr[which];
}

void ReadWrite::write(Student * sets1, int length)
{
    ofstream myfile;
  myfile.open ("ContactList.txt");
  for (int i = 0; i <length; i++)
  {
  myfile << sets1[i].first_name +   " " +  sets1[i].last_name + " " +  sets1[i].email + " " + sets1[i].number + " ";
  myfile<<endl;
  }

  myfile.close();
}



int main()
{

    string filename= ("ContactList.txt");
    int entries = rrr.counter(filename);

    system("Pause");
        system("cls");

	Student* sets = new Student[entries];

    for ( int i = 0 ; i < entries ; i++)
    {
        sets[i].first_name = rrr.setcontent(filename, entries, i , 0);
        sets[i].last_name =rrr.setcontent(filename, entries, i , 1);
        sets[i].email= rrr.setcontent(filename, entries, i , 2);
        sets[i].number =rrr.setcontent(filename, entries, i , 3);


    }

    ret.contact_menu(sets, entries);


	return 0;
}
