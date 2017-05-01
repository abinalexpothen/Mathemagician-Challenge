#include "iostream"
#include "process"
#include "stdlib"
#include "string"
#include "stdio"
#include "conio"
#include "time"
#include "player"


void welcomescreen(void);
void instructions(void);
void gamebody(void);
int score(int);

void main()
{
clrscr();
welcomescreen();
getch();
}

void instructions()
{
option:
textcolor(2);
clrscr();
cout<<"\n 1.How to play"<<endl<<endl;
cout<<" 2.Scoring criteria"<<endl<<endl;
cout<<" 3.Back to main menu"<<endl<<endl;
int choice;
cout<<"\n  Enter your option: ";
cin>>choice;
if(choice==1)
{textcolor(15);
clrscr();
char str[]={"\n\t\t     $ The MATHEMAGICIAN CHALLENGE RULES $\n \nThere can be a maximum number of four players. The players get to choose their \n\nsymbol and then start their game.The MATHEMAGICIAN CHALLENGE board appears on\n \nthe screen. Every player starts at 1 and the one to cross 25 first will win the\n \ngame. A mathematical expression will be put in front of you and points will be\n \nawarded according to the time taken to solve the expression.\n \n\nPress any key to continue...."};
for(int i=0;str[i]!='\0';i++)
{
cout<<str[i];
delay(50);
}
getch();
goto option;
}
else if(choice==2)
{textcolor(15);
clrscr();
char str2[]={"\n\t\t\t$ THE SCORING CRITERIA $\n\nPoints will be awarded according to the time taken to solve the expression.\n \nIf the time taken is less than 10 seconds then 6 points will be awarded.\n \nIf the time taken is between 10-20 seconds then 5 points will be awarded.\n \nIf the time taken is between 20-30 seconds then 4 points will be awarded.\n \nIf the time taken is between 30-40 seconds then 3 points will be awarded.\n \nIf the time taken is between 40-50 seconds then 2 points will be awarded.\n \nIf the time taken is more 50 seconds then 1 point will be awarded.\n \nNo points are awarded for a wrong answer.\n \n\nPress any key to continue.... "};
for(int k=0;str2[k]!='\0';k++)
{
cout<<str2[k];
delay(50);
}
getch();
goto option;
}
else if(choice==3)
main();
else
{textcolor(4);
cout<<"\n\t";
cprintf("wrong option...rolling back to main menu...");
sleep(2);
main();
}
}

void welcomescreen()
{
char ch[20]={'/0'};
textcolor(15);
clrscr();
cout<<endl;
cprintf(" THE MATHEMAGICIAN CHALLENGE");
cout<<endl;
cprintf(" ---------------------------");
cout<<endl;
cprintf(" by Abin Alex Pothen and Rowan Menezes ");
textcolor(7);
cout<<endl<<endl<<endl;
cprintf(" Please select your option:");
cout<<endl<<endl;
cprintf(" 1.Instructions");
cout<<endl<<endl;
cprintf(" 2.Start the game");
cout<<endl<<endl;
cprintf(" 3.Exit");
cout<<endl<<endl;
textcolor(13);
cprintf(" You can quit to main menu from any part of the program by entering 'q' ");
cout<<endl;
Option:
textcolor(2);
cout<<endl<<endl;
cprintf(" Enter your option: ");
gets(ch);
if(ch[0]=='1')instructions();
else if(ch[0]=='2')gamebody();
else if(ch[0]=='3')exit(0);
else if(ch[0]=='q')welcomescreen();
else
{
textcolor(4);
cout<<endl;
cprintf(" Wrong option...reenter");
cout<<endl;
goto Option;
}
}

void gamebody()
{
player p[4];
char ch[5];
int nop;	//number of players
int pob;	//players on the board
int first;
//for getting the number of players
playerlist:
cout<<"\n\n";
textcolor(2);
cprintf(" Enter the number of players(min 2 and max 4): ");
Option:
gets(ch);
if(ch[0]=='q')main();
if(!(ch[0]=='2'||ch[0]=='3'||ch[0]=='4'))
{
textcolor(4);
cout<<endl;
cprintf("\n Wrong option...reenter:");
goto Option;
}
nop=ch[0]-48;
pob=nop;

//for getting the name and symbol of the players

textcolor(15);
clrscr();
cout<<"\n Enter the players:";
cout<<"\n ------------------\n";
for(int i=0;i<nop;++i)
{cout<<"\n Player "<<i+1;
 cout<<"\n ---------";
 p[i].getinfo();
}
textcolor(15);
clrscr();
cout<<"\n Player list:";
cout<<"\n ------------\n";
for(i=0;i<nop;++i)
{cout<<' '<<(i+1)<<'.';p[i].putinfo();cout<<endl;
}
cout<<"\n Enter any key to continue or 'e' to reenter the list: ";ch[0]=getch();
if(ch[0]=='q')main();
if(ch[0]=='e')goto playerlist;

//game body starts here
while(pob!=1)
{for(int k=0;k<nop;++k)
	{	if(pob==1)break;
		textcolor(14);
		clrscr();
		for(int j=0;j<nop;++j) p[j].display();
		p[k].turn(pob);
	}
}
//game body ends

//for displaying the positions
textcolor(14);
clrscr();
cout<<"\n Player Positions:";
cout<<"\n -----------------\n";
for(i=1;i<=nop;++i)
	for(int j=0;j<nop;++j)
	{	int temp=p[j].rethonours();
		if(temp==i)
		{	cout<<' '<<(i+1)<<'.';p[i].putinfo();cout<<endl;
			if(i==1)first=i;
		}
	}
sleep(1);
cout<<"\n\n ";
p[first].putinfo();
cprintf(" is the mathemagician ... Great Job ..");
cout<<"\n";
cprintf("Total time taken : ");
cout<<p[first].rettime();
cout<<"\n\n (Press any key to continue)";
getch();
textcolor(14);
}

int score(int x)
{int a;
if(x<10) a=6;
else if(x<20) a=5;
else if(x<30) a=4;
else if(x<40) a=3;
else if(x<50) a=2;
else a=1;
return a;
}
