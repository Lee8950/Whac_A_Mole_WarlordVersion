#include<bits/stdc++.h>
#include<conio.h>
#include "wheel_date.h"
#include "wheel_std.h"
#include<windows.h>
#include<unistd.h>
#include<mmsystem.h>
#pragma comment(lib, "Winmm.lib")
using namespace ecl;

void getSomeBlocks(){
	cout<<"\t\t\t";
}

class board{
	private:
		int score;
		bool isMouseOnTheBlock[9];
		
		void clearTheBoard(){
			memset(isMouseOnTheBlock,0,9);
		}
		
		void generateMouse(){
			srand(time(NULL));
			isMouseOnTheBlock[rand()%9]=1;
		}
		
	public:
		
		board(){
			memset(isMouseOnTheBlock,0,9);
			score=0;
			generateMouse();
		}
			
		bool hitTheMouse(int spot){
			if(isMouseOnTheBlock[spot]==0){
				score--;
				return false;
			}
			if(isMouseOnTheBlock[spot]==1){
				score++;
				clearTheBoard();
				generateMouse();
				return true;
			}
		}
		
		void printTheBoard(){
			system("cls");
			cout<<endl<<endl<<endl<<endl;
			getSomeBlocks();
			for(int i=0;i<9;i++){
				if(isMouseOnTheBlock[i]==1)
					cout<<"军阀"<<"\t";
				else
					cout<<"."<<"\t";
				if((i+1)%3==0){
					cout<<endl;
					getSomeBlocks();
				}
			}
			cout<<"已消灭军阀："<<score<<endl<<endl;
			getSomeBlocks();
		}
};

int main()
{
	system("color a");
	PlaySound("musicmainmenu.wav",NULL,SND_ASYNC);
	board Coard;
	Date timer;
	char ch;
	time_t begin=timer.getTime(true);
	while(1)
	{
		if(timer.getTime(true)-begin>60)
			break;
		if(kbhit())
		{
			ch=_getch();
			switch(ch)
			{
				case '7':Coard.hitTheMouse(0);break;
				case '8':Coard.hitTheMouse(1);break;
				case '9':Coard.hitTheMouse(2);break;
				case '4':Coard.hitTheMouse(3);break;
				case '5':Coard.hitTheMouse(4);break;
				case '6':Coard.hitTheMouse(5);break;
				case '1':Coard.hitTheMouse(6);break;
				case '2':Coard.hitTheMouse(7);break;
				case '3':Coard.hitTheMouse(8);break;
				default:break;
			}
		}
		Coard.printTheBoard();
		cout<<60-timer.getTime()+begin<<" second(s) left."<<endl;
		usleep(1000);
	}
	getSomeBlocks();
	cout<<"Game is Over";
	return 0;
}
