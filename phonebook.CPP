#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
class record
{
	char name[50];
	char num[20];
public:
	void setData()
	{
		char temp1[50];
		char temp2[20];
		cout<<"Enter Name:\t";
		cin>>temp1;
		strcpy(name,temp1);
		cout<<"Enter Number:\t";
		cin>>temp2;
		strcpy(num,temp2);
	}
	void getData()
	{
		cout<<"Name:\t"<<name<<endl;
		cout<<"Number:\t "<<num<<endl;
	}
	char * getName()
	{
		return(name);
	}
	char * getNum()
	{
		return(num);
	}
};
int convert(char x)
{
	switch(x)
	{
		case '1':
				return 1;
		case '2':
				return 2;
		case '3':
				return 3;
		case '4':
				return 4;
		case '5':
				return 5;
		case '6':
				return 6;
		case '7':
				return 7;
		case '8':
				return 8;
		default:
				return 9;
	}
}
void writeFile()
{
	record data;
	data.setData();
	ofstream ob;
	ob.open("record.dat",ios::out|ios::binary|ios::app);
	ob.write((char *)&data, sizeof(data));
	ob.close();
}
void readFile()
{
	record data;
	ifstream ob;
	ob.open("record.dat",ios::binary);
	while(ob.read((char *) &data, sizeof(data)))
	{
		data.getData();
	}
	ob.close();
}
void sort(record ar[], int size)
{
	int swaped=1;
	record temp;
	for(int i=1;i<size&&swaped==1;i++)
	{
		swaped=0;
		for(int j=0;j<size-i;j++)
		{
			if(strcmpi(ar[j].getName(),ar[j+1].getName())>0)
			{
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
				swaped=1;
			}
		}
	}

}
void remove(record ar[], int size, int index)
{
	clrscr();
	int i;
	ar[index].getData();
	cout<<"Do you want to delete this Contact(1/0): ";
	cin>>i;
	switch(i)
	{
		case 1:
			ofstream ob;
			ob.open("record.dat",ios::binary | ios::trunc);
			int t=0;
			while(t<size)
			{
				if(t!=index)
				{
					ob.write((char *)&ar[t],sizeof(ar[t]));
				}
				t++;
			}
			ob.close();
			cout<<"\n Data removed successfully. Press any key to continue";
			getch();
			break;
	}

}

void clearLine(int y)
{
	for(int i=8;i<=y;i++)
	{
		gotoxy(1,i);
		clreol();
	}
}
void search(){
	record data[100];
	ifstream ob;
	ob.open("record.dat",ios::binary);
	int i=0;
	while(ob.read((char *) &data[i], sizeof(data[i])))
	{
		i++;
	}
	ob.close();
	sort(data,i);
	char str[100],ch;
	int k=0,x2=1,y2=8,x1,y1,low=0,high=i,temp,j=0;
	cout<<"Enter the Serial number if you want to remove that contact\n";
	cout<<"Enter 0 to Exit from Search\n\n";
	cout<<"Enter the name to Search:"<<endl;
	x1=wherex();
	y1=wherey();
	j=0;
	while(j<i && j<9)
	{
		gotoxy(x2,y2);
		cout<<j+1<<"\t"<<data[j].getName();
		gotoxy(20,y2);
		cout<<data[j].getNum();
		j++;
		y2++;
	}
	do
	{
		gotoxy(x1,y1);
		ch=getche();
		x1=wherex();
		y1=wherey();
		if(ch==8)
		{
			k--;
			str[k]='\0';
			x1=wherex();
			cout<<" ";
			gotoxy(x1,y1);
			low=0;
			high=i;
		}
		else if(ch>64 && ch<91 || ch>96 && ch<123)
		{
			str[k]=ch;
			k++;
			str[k]='\0';
		}
		else if(ch>48 && ch<58)
		{
			remove(data,i,low+convert(ch)-1);
			break;
		}
		clearLine(y2);
		y2=8;
		while(strncmpi(str,data[low].getName(),k)!=0&&low<high)
		{
			low++;
		}
		temp=low;
		j=1;
		while(strncmpi(str,data[temp].getName(),k)==0 && temp<high && temp<10)
		{
			gotoxy(x2,y2);
			cout<<j<<"\t"<<data[temp].getName();
			gotoxy(20,y2);
			cout<<data[temp].getNum();
			j++;
			temp++;
			y2++;
		}
		high=temp;
	}while(ch!='0');

}

void main()
{
int choice,temp=1;
while(temp)
{
clrscr();
//fstream ob;
//record data;
cout<<"1: Add Contacts\n";
cout<<"2: Search Contacts\n";
cout<<"3: Delete Contacts\n";
cout<<"4: Exit\n";
cout<<"Enter your choice: ";
cin>>choice;
cout<<"\n\n";
switch(choice)
{
	case 1:
		writeFile();
		break;
	case 2:
		clrscr();
		search();
		break;
	case 3:
		clrscr();
		search();
		break;
	case 4:

		cout<<"\n\nPress any key to Exit.";
		getch();
		return;
}
clrscr();
cout<<"\n\nDo you want to perform more operation: \n";
cout<<"0: No\n";
cout<<"1: Yes\n";
cout<<"Your Choice: ";
cin>>temp;
}
getch();
}