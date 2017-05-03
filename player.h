#include "iostream"
#include "time.h"

class player
{
static int hon;
int status;	//whether player is on the board or not
char name[20];  //name of player
char symbol;    //symbol of player
int color;      //colour of the player
int location;   //location of the player on the board
int honours;    //position of the player after the game
int timetoenter;

public:
void display();
void turn(int &);
int rethonours() {return honours;}

player() //constructor
{
status=0;
strcpy(name,'\0');
symbol='\0';
location=1;
honours=4;
color=0;
timetoenter=0;
}

void getinfo()
{cout<<"\n Name: ";gets(name);
cout<<"\n Enter your symbol(!,@,#,$,% or any symbol of your choice): ";cin>>symbol;
cout<<"\n Enter a number to get your colour(2,3,4 or 5): ";cin>>color;
textcolor(color);
cprintf("\n Your color");
cout<<endl<<endl;
}

void putinfo()
{
textcolor(color);
cprintf(name);
cprintf(" -> ");
putch(symbol);
}
int rettime()
{
return timetoenter;
}

~player(){}
};
int player::hon=1;
void player::display()
{
char str[3]={'\0'};
if(status==0)
{	textcolor(color);
	cout<<"\n ";
	cprintf(name);
	putch(':');
	cout<<"\n\n";
	//loop to display the 25 places on a player's board
	for(int i=0;i<25;++i)
	{
		if((i+1)==location)
		{	textcolor(15);
			cout<<"\t";
			str[0]=symbol;
			str[1]=' ';
			cprintf(str);
			textcolor(color);
		}
		else
		{	/*converts number to character and stores it in
			the string str[]*/
			int num=i+1;
			int rem;
			for(int j=1;j>=0;--j)
			{rem=num%10;
			str[j]=(char)(rem+48);//character equivalent of digit
			num/=10;
			}
			/*number to character convertion ends here. now str
			stores the required number in character format. this
			has been done to make the board look even with
			proper spacing*/
			cout<<"\t";
			cprintf(str);
		}
		if((i+1)%7==0)cout<<endl;
	}
	cout<<endl;
	cprintf(" --------------------------------------------------------------");
}
}

void player::turn(int &pob)
{
char ch[5]; //control variable. made in the form of array to prevent crashing.
int term1,term2,term3,term4;	//terms of the expression
int result,answer;              //result of the expression & player's answer.
int t;       			//stores the time taken to enter the answer.
time_t start,end,randtime;
if(status==0)
{	textcolor(color);
	cout<<"\n\n ";
	cprintf(name);
	cprintf("'s turn: ");
	cout<<endl;
	cout<<"\n";
	cprintf(" (Press any key to get the expression)");
	getch();
	cout<<"\n\n";
	cprintf(" Please wait...");sleep(1);
	//creating the terms of the expression
	time(&randtime);
	srand(randtime);
	term1=(rand()%100)+1;
	sleep(1);
	time(&randtime);
	srand(randtime);
	term2=(rand()%100)+1;
	sleep(1);
	time(&randtime);
	srand(randtime);
	term3=(rand()%20)+1;
	sleep(1);
	time(&randtime);
	srand(randtime);
	term4=(rand()%10)+1;
	//terms have been decided.
	result=term1+term2-term3*term4;//stores the result
	cout<<"\n\n Your expression is: \n "<<term1<<'+'<<term2<<'-'<<term3<<'*'<<term4<<"=_____";
	cout<<"\n\n ";
	cprintf("Your answer: ");
	time(&start);
	cin>>answer;
	time(&end);
	t=difftime(end,start);	 	//calculates time taken to answer
	timetoenter+=t;
	if(answer==result)
	{	cout<<"\n Correct answer...\n\n ";
		cprintf("Time taken to enter: ");
		cout<<timetoenter;
		cprintf(" seconds.");
		int temp=score((int)t);/*calculates the score based on the
		time taken to answer using the function score()*/
		cout<<"\n ";
		cprintf("Points awarded: ");
		cout<<temp;
		location=location+temp;		//shifts the player on the board
		if(location>25)
		{
			status=1;
			honours=hon;
			hon++;
			pob--;
			cout<<"\n\n ";
			cprintf("Congratulations ");
			cprintf(name);
			cprintf(". You are at position ");
			cout<<honours;
		}
		if(status==0)
		{	cout<<"\n\n ";
			cprintf("You will be shifted to ");
			cout<<location;
		}
		cout<<"\n\n (Press 'q' to quit to main menu or any other key to continue)";
		ch[0]=getch();
	}
	else
	{	cout<<"\n\n Wrong answer...";
		cout<<"\n\n (Press 'q' to quit to main menu or any other key to continue)";
		ch[0]=getch();
	}
	if(ch[0]=='q')main();
}
}
