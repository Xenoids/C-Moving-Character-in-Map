#include <stdio.h> // buat semua library
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

FILE* fs;
FILE* fp;
char map[100][100];
char name[100];
int point = 0;
int level = 1;
void title()
{
	 printf(" /\\   |~) _  _ _ |_  _  _\n");
     printf("/~~\\  |_)(_)| | ||_)(/_|\n\n");
}

	int Ypos = 1;
	int Xpos = 1;



void wall()
{
	//int count = srand(9,8)
//	int upper = 18
//	int lower = 9
//	int num = (rand() % )
//	int Y,X;
//	map[Y][X]
}

void player()
{
	//char move;
	map[Ypos][Xpos] = '@';
	for(int i=2;i<15;i+=2)
	{
		for(int j=4;j<31;j+=4)
		{
			map[i][j] ='#';
		}
	}
	bool cek = false;
	if(kbhit()){
			switch(getch()){
		case 'w': // atas
//			if(Ypos < 0 || Ypos > 17 || Xpos < 0 || Xpos > 34){
//				return;
//			}
			map[Ypos][Xpos] = ' ';
			if(Ypos > 1 && Xpos % 4 != 0 ){
				Ypos--;
			}
			map[Ypos][Xpos] = '@';
			break;
		case 's': // bawah
			
			map[Ypos][Xpos] = ' ';
			if(Ypos < 15 && Xpos % 4 != 0)
			{
				Ypos++;
			}
			map[Ypos][Xpos] = '@';	
		
			break;
		case 'a': // kiri
			
			map[Ypos][Xpos] = ' ';
			if(Xpos > 1  && map[Ypos][Xpos-1] != '#')
			{
				Xpos--;
			}
			map[Ypos][Xpos] = '@';	
		
			break;
			
		case 'd': // kanan
	
			map[Ypos][Xpos] = ' ';
			if(Xpos < 31 && map[Ypos][Xpos+1] != '#') 
			{
				Xpos++;
			}
			map[Ypos][Xpos] = '@';
			
			break;
	}

		//default:
		//player();
			
	}
}



//void player(int y, int x);
//void moves(int y,int x)
//{
//	//char move;
//	//scanf("%c",&move);
//	//fflush(stdin);
//	if(kbhit()){
//		switch(getch())
//		{
//		case 'w':
//	//	if()
//		map[y][x] =' ';
//		player(y-1,x);
//		break;
//		
//		case 's':
//		map[y][x] = ' ';
//		player(y+1,x);
//		break;
//		
//		case 'a':
//		map[y][x] = ' ';
//		player(y,x-1);
//		break;
//		
//		case 'd':
//		map[y][x] = ' ';
//		player(y,x+1);
//		break;
//		}
//	}
//}

void readmap()
{
//	bool cek = false;
	printf("\tLEVEL : %d\n",level);
	FILE* fp = fopen("map.txt","r");
	
//	if(cek == false){
		for(int i=0;i<17;i++)
	{
		for(int j=0;j<34;j++)
		{
			fscanf(fp,"%c",&map[i][j]);
		}
	}
	
//	}

//	cek = true;
	
//	if(cek == true)
//	{
	//	player(1,1);
//		for(int i=0;i<17;i++)
//	{
//		for(int j=0;j<34;j++)
//		{
//			printf("%c",map[i][j]);
//		}
//	}
		
//	}	
			
	fclose(fp);
}
void pause();

void printmap()
{
//	player(1,1);
	
		for(int i=0;i<17;i++)
	{
		for(int j=0;j<34;j++)
		{
			printf("%c",map[i][j]);
		}
	}
}

void save()
{
	FILE* fs = fopen("save.txt","a");
	char* p;
	bool test = false;
	do{
	test = false;
	printf("\nENTER NAME : ");
	scanf("%[^\n]",name);
	getchar();
	p = strstr(name," ");
	if(p) test = true;
	else test = false;
	//printf("%d",test); CHECK
	
	if(strlen(name)<2 || test == true) 
	{
		printf("INVALID NAME!\n");
		fflush(stdin);
		printf(" [Enter] to continue!");
		getchar();
	}
	}while(strlen(name)<2 || test == true);
	printf("SUCCESS SAVE!\n\n");
	printf("PRESS [ENTER] TO CONTINUE!");
	getchar();
	fprintf(fs,"%s#%d\n",name,point);
	fclose(fs);
}

void addsave()
{
	FILE* fs = fopen("save.txt","a");	
}

void View()
{
	FILE* fs = fopen("save.txt","r");
	title();
	puts("+------------------------------------+---------+");
	puts("|                NAME                |  SCORE  |");
	puts("+------------------------------------+---------+");
	while(!feof(fs)){
	fscanf(fs,"%[^#]#%d\n",name,&point);
	printf("|%-7s                             | %-4d    |\n",name,point);
	}
	puts("+------------------------------------+---------+");
	getchar();
	fclose(fs);	
}

void keyboard()
{
	if(kbhit() && getch() == 27 )
    {
    	system("cls");
    	pause();
	}
}


int main()
{
	char fps[100];
	point = 0;
	title();
	printf("Enter Desired FPS : ");
    scanf("%s",fps);
    getchar();
      if((fp= fopen("map.txt","r"))== NULL)
      {
      	printf("\nMAP NOT FOUND!");
      	getchar();
      	exit(1);
	  }
      if((fs = fopen("save.txt","r"))==NULL)
    {
    	printf("\nSAVEFILE NOT FOUND!\nCREATING A NEW ONE!");
    	getchar();
    	addsave();
	}
    system("cls");
   // player(1,1);
   	readmap();
    do{
    system("cls");
    player();
   	printmap();
   	keyboard();
	printf("\nPOINT : %d\n",point);
	}while(1);
	return 0;
}

//void player(int y,int x)
//{
//		if(y < 0 || y > 17 || x < 0 || x > 34){
//				return;
//			}
//		if(map[y][x] == '#' || map[y][x] == '|' || map[y][x] == '-'){
//			return;
//		}
//		map[y][x] = '@';
//		moves(y,x);
//}
void pause()
{
	int choice;
	do{
	system("cls");
	title();
	puts("1. Back");
	puts("2. View Highscores");
	puts("3. Exit");
	printf(">>");
	scanf("%d",&choice);
	getchar();
	}while(choice >3 || choice < 1);
	switch(choice)
	{
		case 1:
		return;	
		break;
		
		case 2:
		View();	
		break;
		
		case 3:
		save();	
		exit(1);
		break;
	}
}


