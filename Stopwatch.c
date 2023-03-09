#include <stdio.h>
#include <conio.h>
#include <unistd.h>
//#include <stdlib.h>
#include <windows.h>
#define VK_KEY_S 0x53
#define VK_KEY_0  0x30
#define VK_KEY_2 0x32
#define VK_KEY_R  0x52
#define keyPressed -32767 

void gotoxy(int x,int y){
	COORD crd;
	crd.X=x;
	crd.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),crd );
}
void beep(){
	int i;
	for(i=0;i<8;i++){
		Beep(523, 500);
	}

}

int main() {
	system("color 3F");
	start:
	gotoxy(10,4);
	char choice;
	int mil = 0, sec = 0, min = 0, hour = 0,n,n2,n3;
	printf("Press 1 for Stopwatch ,2 for Alarm and 0 to exit: ");
	if(getch()=='1'){
	system("cls");
	gotoxy(10,4);
	printf("\n\n\t  (Press ESC to return)");
	printf("\n\n"
       "\t     ||||||  ||||||||   ||||   ||||||      ||        ||       ||       ||||||||  |||||||   ||     ||\n" 
       "\t     ||         ||     ||  ||  ||  ||      ||        ||      || ||        ||     |||       ||     ||\n"           
       "\t     ||||||     ||    |||  ||| |||||| ---  ||  ||||  ||    |||||||||      ||     |||       ||=====||\n"
       "\t         ||     ||     ||  ||  ||          || ||  || ||   ||       ||     ||     |||       ||     ||\n"
       "\t     ||||||     ||      ||||   ||          ||        ||  ||         ||    ||     |||||||   ||     ||\n\n" );
//	printf("\n\n   ------------------------------------------------Stopwatch------------------------------------------------\n");
	printf("\t\t\t\t   s=Start   ,    L-CONTROL=Stop   ,   r =Reset\n\n");
		
	
		choice =getch();
		if(choice == 's'){
			
	for(;;){
		label1:
		Sleep(10);
		mil++;
		label:
		printf("\r\t\t\t\t\t           %2d:%2d:%2d:%2d", hour, min, sec, mil);

		if (mil==99)
		{
			sec++;
			mil = 0;
		}
		if (min == 59) {
			hour++;
			min = 0;
			sec = 0;
			mil = 0;
		}
		if (sec == 59) {
			min++;
			sec = 0;
			mil = 0;
		}
		if (hour == 24) {
			min = 0;
			sec = 0;
			mil = 0;
			hour=0;
		}

			if(GetAsyncKeyState(VK_LCONTROL)==keyPressed){
					fflush(stdin);					
					choice =getch();
					if(choice == 's'){
						goto label;
					}
					else if(choice ==82){
						mil=0;min=0,sec=0,hour=0;
						printf("\r\t\t\t\t\t           %2d:%2d:%2d:%2d", 0, 0, 0, 0);
						choice = getch();
						if(choice ='s'){
							goto label1;
						}
					}
		}
		
		else if(GetAsyncKeyState(VK_KEY_R)==keyPressed){
					mil=0,min=0,sec=0,hour=0;
					printf("\r\t\t\t\t\t           %2d:%2d:%2d:%2d", 0, 0, 0, 0);			
					choice = getch();
					if(choice == 's'){
						goto label1;
				}
		}
		else if(GetAsyncKeyState(VK_ESCAPE)==keyPressed){
			system("cls");
			goto start;
			break;
		}
	
	}
}
	else if(GetAsyncKeyState(VK_ESCAPE)==keyPressed){
		system("cls");
			goto start;
			
	}
	else {
		printf("Press s to start");
		main();
	}
	}
	
	
	//First if Ended
	//ALARM
	else if(GetAsyncKeyState(VK_KEY_2)==keyPressed){
		
		system("cls");
		gotoxy(10,4);
		int timeHour,timeMin,timeSec,timeMil;
		printf("(Press ESC to return to menu \n\t  and any other key to continue.....)");
		printf("\n\n"
		"             ||        ||             ||         ||||||    ||     ||  \n" 
		"           ||  ||      ||           ||  ||       ||   ||   |||| ||||  \n"
		"         ||||||||||    ||         ||||||||||     ||||||    ||  || ||  \n"
		"        ||         ||  ||       ||          ||   ||   ||   ||     ||  \n"
		"        ||         ||  |||||||| ||          ||   ||    ||  ||     || \n\n");  
		
			if(getch()==27){
			system("cls");
			goto start;
			}
			else {
				printf("\n\t  Enter Hours: ");
				scanf("%d",&timeHour);
				printf("\t  Enter Minutes: ");
				scanf("%d",&timeMin);
				printf("\t  Enter Seconds: ");
				scanf("%d",&timeSec);
				printf("\t  Enter Miliseconds: ");
				scanf("%d",&timeMil);
			}
//		printf("\n\n\n\t  ------------------------------------------------Timer------------------------------------------------\n");
		
	
		
	int i;			
	for(;;){
		Sleep(10);
		mil++;
		timer_continue:
		printf("\r\t\t\t\t\t         %2d:%2d:%2d:%2d", hour, min, sec, mil);

		if (mil==99)
		{
			sec++;
			mil = 0;
		}
		if (min == 59) {
			hour++;
			min = 0;
			sec = 0;
			mil = 0;
		}
		if (sec == 59) {
			min++;
			sec = 0;
			mil = 0;
		}
		
		if (hour == 24) {
			min = 0;
			sec = 0;
			mil = 0;
			hour =0;
		}
		else if(hour==timeHour && min==timeMin && sec==timeSec && mil==timeMil){
			printf("\r\t\t\t\t\t         %2d:%2d:%2d:%2d", timeHour, timeMin, timeSec , timeMil);
			beep();
			sleep(3);
			system("cls");
			goto start;
			break;
		}
	}
		
	}
	else if(GetAsyncKeyState(VK_KEY_0)==keyPressed){
		exit(0);
	}
//		goto label1;
	

	

	

	
	return 0;
}

