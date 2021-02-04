//#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<iostream.h>
#include<ctype.h>
//using namespace std;

class input
{
	char str1[26];
	public:	input()
		{
			strcpy(str1,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		}
		friend char findinput(char ch,input I);
};

class r3
{
	char str1[2][26];
	public:	r3()
		{
			strcpy(str1[0],"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
			strcpy(str1[1],"BDFHJLCPRTXVZNYEIWGAKMUSQO");
		}
		void disp()
		{
			cout<<endl<<str1[0]<<endl;
		}
		void set(char ch);
		friend int findr3(int n,r3 R);
		friend void rotater3(r3 &R);
};

class r2
{
	char str1[2][26];
	public:	r2()
		{
			strcpy(str1[0],"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
			strcpy(str1[1],"AJDKSIRUXBLHWTMCQGZNPYFVOE");
		}
		void set(char ch);
		friend int findr2(int n,r2 R);
		friend void rotater2(r2 &R);
};

class r1
{
	char str1[2][26];
	public:	r1()
		{
			strcpy(str1[0],"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
			strcpy(str1[1],"EKMFLGDQVZNTOWYHXUSPAIBRCJ");
		}

		void set(char ch);
		friend int findr1(int n,r1 R);
		friend void rotater1(r1 &R);
};

class reflector
{

	public:
		char str1[26];
		reflector()
		{
			strcpy(str1,"ABCDEFGDIJKGMKMIEBFTCVVJAT");
		}
		friend int findreflector(int n);
};

r1 obj1;
r2 obj2;
r3 obj3;
reflector obj4;
input obj5;

void rotater3(r3 &R)
{
	int j;
	char t1,t2;
	t1=R.str1[0][0];
	if(t1=='V')
	{
		rotater2(obj2);
	}
	t2=R.str1[1][0];
	for(j=0;j<26;j++)
	{
		R.str1[0][j]=R.str1[0][j+1];
		R.str1[1][j]=R.str1[1][j+1];
	}
	R.str1[0][25]=t1;
	R.str1[1][25]=t2;
}

void rotater2(r2 &R)
{
	int j;
	char t1,t2;
	t1=R.str1[0][0];
	if(t1=='E')
	{
		rotater1(obj1);
	}
	t2=R.str1[1][0];
	for(j=0;j<26;j++)
	{
		R.str1[0][j]=R.str1[0][j+1];
		R.str1[1][j]=R.str1[1][j+1];
	}
	R.str1[0][25]=t1;
	R.str1[1][25]=t2;
}

void rotater1(r1 &R)
{
	int j;
	char t1,t2;
	t1=R.str1[0][0];
	t2=R.str1[1][0];
	for(j=0;j<26;j++)
	{
		R.str1[0][j]=R.str1[0][j+1];
		R.str1[1][j]=R.str1[1][j+1];
	}
	R.str1[0][25]=t1;
	R.str1[1][25]=t2;
}

int findreflector(int n,reflector R)
{
	int i;
	char t;
	t=R.str1[n];
	for(i=0;i<26;i++)
	{
		if(i!=n)
		if(R.str1[i]==t)
		{
			break;	
		}
	}
	return i;
}

int findr1(int n,r1 R)
{
	int i;
	char t;
	t=R.str1[1][n];
	for(i=0;i<26;i++)
	{
		if(R.str1[0][i]==t)
			break;
	}
	i=findreflector(i,obj4);
	t=R.str1[0][i];
	for(i=0;i<26;i++)
	{
		if(R.str1[1][i]==t)
			break;
	}
	return i;
}

void r1::set(char ch)
{
	int count=0;
	int i=0,j=0;
	char t1,t2;
	while(1)
	{
		if(str1[0][i]==ch)
			break;
		count++;
		i++;
	}	
	for(i=0;i<count;i++)
	{
		t1=str1[0][0];
		t2=str1[1][0];
		for(j=0;j<26;j++)
		{
			str1[0][j]=str1[0][j+1];
			str1[1][j]=str1[1][j+1];
		}
		str1[0][25]=t1;
		str1[1][25]=t2;
	}
}

void r2::set(char ch)
{
	int count=0;
	int i=0,j=0;
	char t1,t2;
	while(1)
	{
		if(str1[0][i]==ch)
			break;
		count++;
		i++;
	}	
	for(i=0;i<count;i++)
	{
		t1=str1[0][0];
		t2=str1[1][0];
		for(j=0;j<26;j++)
		{
			str1[0][j]=str1[0][j+1];
			str1[1][j]=str1[1][j+1];
		}
		str1[0][25]=t1;
		str1[1][25]=t2;
	}
}

int findr2(int n,r2 R)
{
	int i;
	char t;
	t=R.str1[1][n];
	for(i=0;i<26;i++)
	{
		if(R.str1[0][i]==t)
			break;
	}
	i=findr1(i,obj1);
	t=R.str1[0][i];
	for(i=0;i<26;i++)
	{
		if(R.str1[1][i]==t)
			break;
	}
	return i;
}

void r3::set(char ch)
{
	int count=0;
	int i=0,j=0;
	char t1,t2;
	while(1)
	{
		if(str1[0][i]==ch)
			break;
		count++;
		i++;
	}	
	for(i=0;i<count;i++)
	{
		t1=str1[0][0];
		t2=str1[1][0];
		for(j=0;j<26;j++)
		{
			str1[0][j]=str1[0][j+1];
			str1[1][j]=str1[1][j+1];
		}
		str1[0][25]=t1;
		str1[1][25]=t2;
	}
}

int findr3(int n,r3 R)
{
	int i;
	char t;
	t=R.str1[1][n];
	for(i=0;i<26;i++)
	{
		if(R.str1[0][i]==t)
			break;
	}
	i=findr2(i,obj2);
	t=R.str1[0][i];
	for(i=0;i<26;i++)
	{
		if(R.str1[1][i]==t)
			break;
	}
	return i;
}

char findinput(char ch,input I)
{
	int i;
	char t;
	for(i=0;i<26;i++)
	{
		if(I.str1[i]==ch)
			break;
	}
	if(i==26)
	{
		printf("\nblank space encountered (error program terminated)\n");
		exit(0);
	}
	i=findr3(i,obj3);
	return I.str1[i];
}
void draw();
char msg[50],code[50],str[26];
char ch1,ch2,ch3;

int check(char ch)
{
	int i;
	for(i=0;i<26;i++)
	{
		if(ch==str[i])
		     return 1;
	}
	return 0;
}

int main()
{
	int i,f1,f2,f3;
	strcpy(str,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	do
	{
	system("CLS");
	cout<<"\n\t\t\tENIGMA MACHINE\n";
	cout<<"\n\n\n\t\tENTER THE ROTOR COMBINATION\n";
	cout<<"\nROTOR 1: ";
	cin>>ch1;
	ch1=toupper(ch1);
	cout<<"\nROTOR 2: ";
	cin>>ch2;
	ch2=toupper(ch2);
	cout<<"\nROTOR 3: ";
	cin>>ch3;
	ch3=toupper(ch3);
	f1=f2=f3=0;
	for(i=0;i<26;i++)
	{
		if(ch1==str[i])
			f1=1;
		if(ch2==str[i])
			f2=1;
		if(ch3==str[i])
			f3=1;
	}
	if(f1==1 && f2==1 && f3==1)
	{
	obj1.set(ch1);
	obj2.set(ch2);
	obj3.set(ch3);

	draw();

	system("cls");

//	cout<<"\nenter the message to encrypt or decrypt without blank space\n";
//	cin>>msg;
//	i=0;
//	while(msg[i]!='\0')
//	{
//		msg[i]=toupper(msg[i]);
//		rotater3(obj3);
//		code[i]=findinput(msg[i],obj5);
//		i++;
//	}
//	code[i]='\0';

	cout<<"\nMessage:  "<<msg;
	cout<<"\ncode:  "<<code;
	cout<<"\nencript another message(1/0)\n";
	cin>>i;
	}
	else
	{
		cout<<"\nEnter valid roter combination\n";
		i=1;
		getch();
	}
	}while(i==1);
	getch();
	return 0;
}

void draw()
{
	int gd=DETECT,gm,i,j=0,x,f1,f2;
	char ch,str1[10],str2[9],str3[7];
	strcpy(str1,"QWERTYUIOP");
	strcpy(str2,"ASDFGHJKL");
	strcpy(str3,"ZXCVBNM");
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	do
	{
		settextstyle(8,0,3);
		switch(ch1)
		{
			case 'A':outtextxy(250,46,"A");break;
			case 'B':outtextxy(250,46,"B");break;
			case 'C':outtextxy(250,46,"C");break;
			case 'D':outtextxy(250,46,"D");break;
			case 'E':outtextxy(250,46,"E");break;
			case 'F':outtextxy(250,46,"F");break;
			case 'G':outtextxy(250,46,"G");break;
			case 'H':outtextxy(250,46,"H");break;
			case 'I':outtextxy(250,46,"I");break;
			case 'J':outtextxy(250,46,"J");break;
			case 'K':outtextxy(250,46,"K");break;
			case 'L':outtextxy(250,46,"L");break;
			case 'M':outtextxy(250,46,"M");break;
			case 'N':outtextxy(250,46,"N");break;
			case 'O':outtextxy(250,46,"O");break;
			case 'P':outtextxy(250,46,"P");break;
			case 'Q':outtextxy(250,46,"Q");break;
			case 'R':outtextxy(250,46,"R");break;
			case 'S':outtextxy(250,46,"S");break;
			case 'T':outtextxy(250,46,"T");break;
			case 'U':outtextxy(250,46,"U");break;
			case 'V':outtextxy(250,46,"V");break;
			case 'W':outtextxy(250,46,"W");break;
			case 'X':outtextxy(250,46,"X");break;
			case 'Y':outtextxy(250,46,"Y");break;
			case 'Z':outtextxy(250,46,"Z");break;
		}
		switch(ch2)
		{
			case 'A':outtextxy(310,46,"A");break;
			case 'B':outtextxy(310,46,"B");break;
			case 'C':outtextxy(310,46,"C");break;
			case 'D':outtextxy(310,46,"D");break;
			case 'E':outtextxy(310,46,"E");break;
			case 'F':outtextxy(310,46,"F");break;
			case 'G':outtextxy(310,46,"G");break;
			case 'H':outtextxy(310,46,"H");break;
			case 'I':outtextxy(310,46,"I");break;
			case 'J':outtextxy(310,46,"J");break;
			case 'K':outtextxy(310,46,"K");break;
			case 'L':outtextxy(310,46,"L");break;
			case 'M':outtextxy(310,46,"M");break;
			case 'N':outtextxy(310,46,"N");break;
			case 'O':outtextxy(310,46,"O");break;
			case 'P':outtextxy(310,46,"P");break;
			case 'Q':outtextxy(310,46,"Q");break;
			case 'R':outtextxy(310,46,"R");break;
			case 'S':outtextxy(310,46,"S");break;
			case 'T':outtextxy(310,46,"T");break;
			case 'U':outtextxy(310,46,"U");break;
			case 'V':outtextxy(310,46,"V");break;
			case 'W':outtextxy(310,46,"W");break;
			case 'X':outtextxy(310,46,"X");break;
			case 'Y':outtextxy(310,46,"Y");break;
			case 'Z':outtextxy(310,46,"Z");break;
		}
		switch(ch3)
		{
			case 'A':outtextxy(370,46,"A");break;
			case 'B':outtextxy(370,46,"B");break;
			case 'C':outtextxy(370,46,"C");break;
			case 'D':outtextxy(370,46,"D");break;
			case 'E':outtextxy(370,46,"E");break;
			case 'F':outtextxy(370,46,"F");break;
			case 'G':outtextxy(370,46,"G");break;
			case 'H':outtextxy(370,46,"H");break;
			case 'I':outtextxy(370,46,"I");break;
			case 'J':outtextxy(370,46,"J");break;
			case 'K':outtextxy(370,46,"K");break;
			case 'L':outtextxy(370,46,"L");break;
			case 'M':outtextxy(370,46,"M");break;
			case 'N':outtextxy(370,46,"N");break;
			case 'O':outtextxy(370,46,"O");break;
			case 'P':outtextxy(370,46,"P");break;
			case 'Q':outtextxy(370,46,"Q");break;
			case 'R':outtextxy(370,46,"R");break;
			case 'S':outtextxy(370,46,"S");break;
			case 'T':outtextxy(370,46,"T");break;
			case 'U':outtextxy(370,46,"U");break;
			case 'V':outtextxy(370,46,"V");break;
			case 'W':outtextxy(370,46,"W");break;
			case 'X':outtextxy(370,46,"X");break;
			case 'Y':outtextxy(370,46,"Y");break;
			case 'Z':outtextxy(370,46,"Z");break;
		}
		
		settextstyle(11,0,1);
		outtextxy(450,150,"ENTER 0 WHEN FINISHED");
		outtextxy(0,175,"ENTER THE MESSAGE TO ENCRYPT OR DECRYPT WITHOUT BLACK SPACE");
		
		for(i=60;i<=600;i+=60)
		{
			circle(i,250,20);
			//floodfill(i,250,15);
		}
		for(i=90;i<=600;i+=60)
		{ 
			circle(i,300,20);
		}
		for(i=120;i<=480;i+=60)
		{
			circle(i,350,20);
		}
		
		rectangle(240,50,280,90);
		rectangle(300,50,340,90);
		rectangle(360,50,400,90);
		
		settextstyle(1,0,1);
		
		outtextxy(54,238,"Q");
		outtextxy(115,238,"W");
		outtextxy(175,238,"E");
		outtextxy(235,238,"R");
		outtextxy(295,238,"T");
		outtextxy(355,238,"Y");
		outtextxy(415,238,"U");
		outtextxy(480,238,"I");
		outtextxy(537,238,"O");
		outtextxy(597,238,"P");
		
		outtextxy(85,288,"A");
		outtextxy(145,288,"S");
		outtextxy(205,288,"D");
		outtextxy(265,288,"F");
		outtextxy(325,288,"G");
		outtextxy(385,288,"H");
		outtextxy(445,288,"J");
		outtextxy(505,288,"K");
		outtextxy(565,288,"L");
		
		outtextxy(115,338,"Z");
		outtextxy(175,338,"X");
		outtextxy(235,338,"C");
		outtextxy(295,338,"V");
		outtextxy(355,338,"B");
		outtextxy(415,338,"N");
		outtextxy(475,338,"M");
		f1=f2=0;
		
		for(i=0;i<10;i++)
		{
			if(ch==str1[i])
			{
				x=60*(i+1);
				setfillstyle(SOLID_FILL,8);
				f1=1;
				floodfill(x,242,15);
			}
		}
		if(f1==0)
		{
			for(i=0;i<9;i++)
			{
				if(ch==str2[i])
				{
					setfillstyle(SOLID_FILL,8);
					x=90+(60*i);
					f2=1;
					floodfill(x,292,15);
				}
			}
		}
		if(f1==0 && f2==0)
			for(i=0;i<7;i++)
			{
				if(ch==str3[i])
				{
					setfillstyle(SOLID_FILL,8);
					x=120+(60*i);
					floodfill(x,342,15);
				}
			}
		//floodfill(60,250,15);
		ch=getche();
		ch=toupper(ch);
		
		if(check(ch))
		{
			msg[j]=ch;
			rotater3(obj3);
			code[j]=findinput(ch,obj5);
			ch=code[j];
			j++;
		}
	
		clrscr();
	}while(ch!='0');
	msg[j]='\0';
	code[j]='\0';
	//closegraph();
}
