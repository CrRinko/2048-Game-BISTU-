#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define Max(a,b) (a>b?a:b)

int graph[4][4],max=0,win=0,countinue=0;

void print(){
	int i,j;
	system("cls");
	printf("2048 Game Designed by CrRinko.\n\n");
	for(i=0;i<=3;i++){
		printf("-");
		for(j=0;j<=3;j++){
			printf("-----");
		}
		printf("\n");
		for(j=0;j<=3;j++){
			if(graph[i][j]!=0)
				printf("|%4d",graph[i][j]);
			else printf("|    ");
		}
		printf("|\n");
	}
	printf("-");
	for(j=0;j<=3;j++){
		printf("-----");
	}
	printf("\n\n");
	printf("Max=%d\n\n",max);
	printf("Press Key 'wasd' to control.\nPress Esc to Exit.\n\n");
	return;
}

int add(char c){
	int x,y;
	int i,j;
	int flag=0;
	if(!(c=='w'||c=='s'||c=='a'||c=='d')) return 0;
	if(max==2048&&countinue==0) return 1;
	for(i=0;i<=3;i++){
		if(flag==1) break;
		for(j=0;j<=3;j++){
			if(graph[i][j]==0){
				flag=1;
				break;
			}
		}
	}
	srand((int)time(NULL));
	if(flag==1){
		do{
			x=rand()%4;
			y=rand()%4;
		}while(graph[x][y]!=0);
		graph[x][y]=(rand()%2+1)*2;
	}
	if(flag==0)return 1;
	else return 0;
}

void up(){
	int i,j,k;
	for(k=0;k<=3;k++){
		for(i=0;i<=3;i++){
			if(graph[i][k]==0){
				for(j=i+1;j<=3;j++){
					if(graph[j][k]!=0){
						graph[i][k]=graph[j][k];
						graph[j][k]=0;
						break;
					}
				}
			}
		}
		for(i=0;i<=2;i++){
			if(graph[i][k]==graph[i+1][k]||graph[i][k]==0){
				graph[i][k]+=graph[i+1][k];
				max=Max(max,graph[i][k]);
				graph[i+1][k]=0;
			}
		}
	}
	return;
}

void down(){
	int i,j,k;
	for(k=0;k<=3;k++){
		for(i=3;i>=0;i--){
			if(graph[i][k]==0){
				for(j=i-1;j>=0;j--){
					if(graph[j][k]!=0){
						graph[i][k]=graph[j][k];
						graph[j][k]=0;
						break;
					}
				}
			}
		}
		for(i=3;i>=1;i--){
			if(graph[i][k]==graph[i-1][k]||graph[i][k]==0){
				graph[i][k]+=graph[i-1][k];
				max=Max(max,graph[i][k]);
				graph[i-1][k]=0;
			}
		}
	}
	return;
}

void left(){
	int i,j,k;
	for(k=0;k<=3;k++){
		for(i=0;i<=3;i++){
			if(graph[k][i]==0){
				for(j=i+1;j<=3;j++){
					if(graph[k][j]!=0){
						graph[k][i]=graph[k][j];
						graph[k][j]=0;
						break;
					}
				}
			}
		}
		for(i=0;i<=2;i++){
			if(graph[k][i]==graph[k][i+1]||graph[k][i]==0){
				graph[k][i]+=graph[k][i+1];
				max=Max(max,graph[k][i]);
				graph[k][i+1]=0;
			}
		}
	}
	return;
}

void right(){
	int i,j,k;
	for(k=0;k<=3;k++){
		for(i=3;i>=0;i--){
			if(graph[k][i]==0){
				for(j=i-1;j>=0;j--){
					if(graph[k][j]!=0){
						graph[k][i]=graph[k][j];
						graph[k][j]=0;
						break;
					}
				}
			}
		}
		for(i=3;i>=1;i--){
			if(graph[k][i]==graph[k][i-1]||graph[k][i]==0){
				graph[k][i]+=graph[k][i-1];
				max=Max(max,graph[k][i]);
				graph[k][i-1]=0;
			}
		}
	}
	return;
}

int main(){
	char com;
	memset(graph,0,sizeof(graph));
	add('w');
	add('w');
st:	do{
		print();
		fflush(stdin);
		com=getch();
		switch(com){
			case 'w': up();break;
			case 's': down();break;
			case 'a': left();break;
			case 'd': right();break;
			case 27: 
				system("cls");
				printf("Thanks for Playing! >_<\n\n");
				printf("Press Enter to Exit.\n");
				getchar();
				return 0;
			default:
				system("cls");
				printf("Error: Press Key 'wasd' to control.\nPress any key to countinue.\n");
				getch();
				break;
		}
	}while(add(com)==0);
	print();
	if(max==2048){
		printf("You Win! :-)\n\n");
		printf("Do you want to countinue? (y/n)");
		com=getchar();
		if(com=='y'||com=='Y'){
			countinue=1;
			goto st;
		}
	}
	else printf("Game Over! :-(\n\n");
	printf("Thanks for Playing! >_<\n\n");
	printf("Press Enter to Exit.\n");
	getchar();
	return 0;
}