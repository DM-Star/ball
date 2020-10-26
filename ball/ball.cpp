// ball.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "ball.h"
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include<cstdlib>
#include<cmath>
#include <fstream>
using namespace std;

#define MAX_LOADSTRING 100
#define MAXVX 9
// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名
HDC hDC,bDC,mDC;
HWND hWnd;
HBITMAP f[20],b[100],fra[10],frb[10],bg[10],ba[10],bal[10],bri[20],icon[20],item[30],num[10];
DWORD tPre, tNow;
int ballx=300,bally=580,ballvx=3,ballvy=-3,ballball=1,map[26][14],bricknum,stage,area,setob,pattern,score=0;

int ballx1,ballx2,ballx3,ballx4;
int bally1,bally2,bally3,bally4;
int batx=300,lbat=150,batv=0;
int xm,ym,ifbutton,button,face=3,frame=1,background=1,bat=1,pause=0;

struct item{
	int x;
	int y;
	int n;
	int it;
	struct item*next;
};
 //struct item*itemhead = new struct item,*p1,*p2,*p;
struct item*itemhead = (struct item *)malloc(sizeof(struct item));
struct ucinfo{
	int money;
	int common;
	int ice;
	int fire;
	int gold;
	int rainbow;
};
struct ucinfo ucinfo;
struct coinfo {
	int fire;
	int ice;
	int life;
	int stretch;
};
struct coinfo coinfo;
struct ulinfo{
	int pattern[5];
};
struct ulinfo ulinfo ;
struct urinfo{
	int adtimes;
	int grtimes;
	int adscore;
	int grscore;
	int liscore;
};
struct urinfo urinfo={0,0,0,0,0};

// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
void MyPaint(HDC hDC);
void TransparentBlt2( HDC hdc0,	int nX0,int nY0,int nW0,int nH0,HDC hdc1,int nX1,int nY1,int nW1,int nH1,UINT Tcol);

void save_to_file()
{
	ofstream outfile("userinfo.dat", ios::out);
	if (!outfile)
	{
		exit(1);
	}
	int x = ucinfo.money, temp;
	temp = (x - x % 100000) / 100000;
	outfile << temp << " ";
	x -= temp * 100000;
	temp = (x - x % 10000) / 10000;
	outfile << temp << " ";
	x -= temp * 10000;
	temp = (x - x % 1000) / 1000;
	outfile << temp << " ";
	x -= temp * 1000;
	temp = (x - x % 100) / 100;
	outfile << temp << " ";
	x -= temp * 100;
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";

	x = ucinfo.common;
	temp = (x - x % 1000) / 1000;
	outfile << temp << " ";
	x -= temp * 1000;
	temp = (x - x % 100) / 100;
	outfile << temp << " ";
	x -= temp * 100;
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";

	x = ucinfo.ice;
	temp = (x - x % 1000) / 1000;
	outfile << temp << " ";
	x -= temp * 1000;
	temp = (x - x % 100) / 100;
	outfile << temp << " ";
	x -= temp * 100;
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";

	x = ucinfo.fire;
	temp = (x - x % 1000) / 1000;
	outfile << temp << " ";
	x -= temp * 1000;
	temp = (x - x % 100) / 100;
	outfile << temp << " ";
	x -= temp * 100;
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";

	x = ucinfo.gold;
	temp = (x - x % 1000) / 1000;
	outfile << temp << " ";
	x -= temp * 1000;
	temp = (x - x % 100) / 100;
	outfile << temp << " ";
	x -= temp * 100;
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";

	x = ucinfo.rainbow;
	temp = (x - x % 1000) / 1000;
	outfile << temp << " ";
	x -= temp * 1000;
	temp = (x - x % 100) / 100;
	outfile << temp << " ";
	x -= temp * 100;
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";

	x = ulinfo.pattern[1];
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";

	x = ulinfo.pattern[2];
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";

	x = ulinfo.pattern[3];
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";

	x = ulinfo.pattern[4];
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";
	
	x=urinfo.adtimes;
	temp = (x - x % 100000) / 100000;
	outfile << temp << " ";
	x -= temp * 100000;
	temp = (x - x % 10000) / 10000;
	outfile << temp << " ";
	x -= temp * 10000;
	temp = (x - x % 1000) / 1000;
	outfile << temp << " ";
	x -= temp * 1000;
	temp = (x - x % 100) / 100;
	outfile << temp << " ";
	x -= temp * 100;
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";
	
	x=urinfo.grtimes;
	temp = (x - x % 100000) / 100000;
	outfile << temp << " ";
	x -= temp * 100000;
	temp = (x - x % 10000) / 10000;
	outfile << temp << " ";
	x -= temp * 10000;
	temp = (x - x % 1000) / 1000;
	outfile << temp << " ";
	x -= temp * 1000;
	temp = (x - x % 100) / 100;
	outfile << temp << " ";
	x -= temp * 100;
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";
	
	x=urinfo.adscore;
	temp = (x - x % 100000) / 100000;
	outfile << temp << " ";
	x -= temp * 100000;
	temp = (x - x % 10000) / 10000;
	outfile << temp << " ";
	x -= temp * 10000;
	temp = (x - x % 1000) / 1000;
	outfile << temp << " ";
	x -= temp * 1000;
	temp = (x - x % 100) / 100;
	outfile << temp << " ";
	x -= temp * 100;
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";
	
	x=urinfo.grscore;
	temp = (x - x % 100000) / 100000;
	outfile << temp << " ";
	x -= temp * 100000;
	temp = (x - x % 10000) / 10000;
	outfile << temp << " ";
	x -= temp * 10000;
	temp = (x - x % 1000) / 1000;
	outfile << temp << " ";
	x -= temp * 1000;
	temp = (x - x % 100) / 100;
	outfile << temp << " ";
	x -= temp * 100;
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";
	
	x=urinfo.liscore;
	temp = (x - x % 100000) / 100000;
	outfile << temp << " ";
	x -= temp * 100000;
	temp = (x - x % 10000) / 10000;
	outfile << temp << " ";
	x -= temp * 10000;
	temp = (x - x % 1000) / 1000;
	outfile << temp << " ";
	x -= temp * 1000;
	temp = (x - x % 100) / 100;
	outfile << temp << " ";
	x -= temp * 100;
	temp = (x - x % 10) / 10;
	outfile << temp << " ";
	x -= temp * 10;
	outfile << x << " ";

	outfile.close();
}

void get_from_file()
{
	ifstream infile("userinfo.dat", ios::in);
	if (!infile)
	{
		exit(1);
	}
	int x;
	infile >> x;
	ucinfo.money += x * 100000;
	infile >> x;
	ucinfo.money += x * 10000;
	infile >> x;
	ucinfo.money += x * 1000;
	infile >> x;
	ucinfo.money += x * 100;
	infile >> x;
	ucinfo.money += x * 10;
	infile >> x;
	ucinfo.money += x ;


	infile >> x;
	ucinfo.common += x * 1000;
	infile >> x;
	ucinfo.common += x * 100;
	infile >> x;
	ucinfo.common += x * 10;
	infile >> x;
	ucinfo.common += x;

	infile >> x;
	ucinfo.ice += x * 1000;
	infile >> x;
	ucinfo.ice += x * 100;
	infile >> x;
	ucinfo.ice += x * 10;
	infile >> x;
	ucinfo.ice += x;

	infile >> x;
	ucinfo.fire += x * 1000;
	infile >> x;
	ucinfo.fire += x * 100;
	infile >> x;
	ucinfo.fire += x * 10;
	infile >> x;
	ucinfo.fire += x;

	infile >> x;
	ucinfo.gold += x * 1000;
	infile >> x;
	ucinfo.gold += x * 100;
	infile >> x;
	ucinfo.gold += x * 10;
	infile >> x;
	ucinfo.gold += x;

	infile >> x;
	ucinfo.rainbow += x * 1000;
	infile >> x;
	ucinfo.rainbow += x * 100;
	infile >> x;
	ucinfo.rainbow += x * 10;
	infile >> x;
	ucinfo.rainbow += x;

	infile >> x;
	ulinfo.pattern[1] = x * 10;
	infile >> x;
	ulinfo.pattern[1] += x;

	infile >> x;
	ulinfo.pattern[2] = x * 10;
	infile >> x;
	ulinfo.pattern[2] += x;

	infile >> x;
	ulinfo.pattern[3] = x * 10;
	infile >> x;
	ulinfo.pattern[3] += x;

	infile >> x;
	ulinfo.pattern[4] = x * 10;
	infile >> x;
	ulinfo.pattern[4] += x;

	infile >> x;
	urinfo.adtimes += x * 100000;
	infile >> x;
	urinfo.adtimes += x * 10000;
	infile >> x;
	urinfo.adtimes += x * 1000;
	infile >> x;
	urinfo.adtimes += x * 100;	
	infile >> x;
	urinfo.adtimes += x * 10;
	infile >> x;
	urinfo.adtimes += x ;
	
	infile >> x;
	urinfo.grtimes += x * 100000;
	infile >> x;
	urinfo.grtimes += x * 10000;
	infile >> x;
	urinfo.grtimes += x * 1000;
	infile >> x;
	urinfo.grtimes += x * 100;	
	infile >> x;
	urinfo.grtimes += x * 10;
	infile >> x;
	urinfo.grtimes += x ;
	
	infile >> x;
	urinfo.adscore += x * 100000;
	infile >> x;
	urinfo.adscore += x * 10000;
	infile >> x;
	urinfo.adscore += x * 1000;
	infile >> x;
	urinfo.adscore += x * 100;	
	infile >> x;
	urinfo.adscore += x * 10;
	infile >> x;
	urinfo.adscore += x ;
	
	infile >> x;
	urinfo.grscore += x * 100000;
	infile >> x;
	urinfo.grscore += x * 10000;
	infile >> x;
	urinfo.grscore += x * 1000;
	infile >> x;
	urinfo.grscore += x * 100;	
	infile >> x;
	urinfo.grscore += x * 10;
	infile >> x;
	urinfo.grscore += x ;
	
	infile >> x;
	urinfo.liscore += x * 100000;
	infile >> x;
	urinfo.liscore += x * 10000;
	infile >> x;
	urinfo.liscore += x * 1000;
	infile >> x;
	urinfo.liscore += x * 100;	
	infile >> x;
	urinfo.liscore += x * 10;
	infile >> x;
	urinfo.liscore += x ;

	infile.close();
	//以下代码为了检验是否读取正确，可以删掉
}

int makearea(int x, int y, int i, int j){
	if (x <= 50 * j - 50){
		if (y <= 25 * i - 25) return 1;
		else if (y>=25 * i-1) return 6;
		else return 4;
	}
	else if (x>=50 * j-1){
		if (y <= 25 * i - 25) return 3;
		else if (y>25 * i-1) return 8;
		else return 5;
	}
	else {
		if (y <= 25 * i - 25) return 2;
		else if (y>=25 * i-1) return 7;
		else return 9;
	}
}

void setoff(){
	ballx = batx;
	bally = 580;
	ballvx = 3;
	ballvy = -9;
	if (pattern == 3) ballvy = -15;
	tNow = 0;
	struct item*p1, *p2;
	p1 = itemhead;
	if (p1->next != NULL) {
		p1 = p1->next;
		while (p1->next != NULL){
			p2 = p1;
			p1 = p1->next;
			free((void*)p2);
		}
		free((void*)p1);
	}
	itemhead->n = 0;
	itemhead->next = NULL;
	MyPaint(hDC);
	pause = 1;
	setob = 1;
}

void dropitem(int x, int y, int situation){
	struct item*p;
	p = itemhead;
	int n;
	while (p->next != NULL)
		p = p->next;
	if (situation == 1 && rand() % 100 <= 66){
		n = rand() % 100;
		if (n <= 10){
			itemhead->n++;
			p->next = (struct item *)malloc(sizeof(struct item));
			p = p->next;
			p->it = 1;
			p->next = NULL;
			p->x = x;
			p->y = y;
		}
		else if (n <= 20){
			itemhead->n++;
			p->next = (struct item *)malloc(sizeof(struct item));
			p = p->next;
			p->it = 2;
			p->next = NULL;
			p->x = x;
			p->y = y;
		}
		else if(n<=30) {
			itemhead->n++;
			p->next = (struct item *)malloc(sizeof(struct item));
			p = p->next;
			p->it = 9;
			p->next = NULL;
			p->x = x;
			p->y = y;
		}
		else if (n <= 40&&pattern!=2) {
			itemhead->n++;
			p->next = (struct item *)malloc(sizeof(struct item));
			p = p->next;
			p->it = 10;
			p->next = NULL;
			p->x = x;
			p->y = y;
		}
	}
	else if (situation == 2){
		n = rand() % 100;
		itemhead->n++;
		p->next = (struct item *)malloc(sizeof(struct item));
		p = p->next;
		if (pattern == 1){
			if (n <= 44){
				p->it = 3;
			}
			else if (n <= 74){
				p->it = 4;
			}
			else if (n <= 84){
				p->it = 5;
			}
			else if (n <= 94){
				p->it = 6;
			}
			else if (n <= 98){
				p->it = 7;
			}
			else if (n <= 99){
				p->it = 8;
			}
		}
		else if (pattern == 2){
			if (n <= 70){
				p->it = 3;
			}
			else if (n <= 82){
				p->it = 4;
			}
			else if (n <= 90){
				p->it = 5;
			}
			else if (n <= 98){
				p->it = 6;
			}
			else if (n <= 99){
				p->it = 7;
			}
		}
		else if (pattern == 3){
			if (n <= 35){
				p->it = 3;
			}
			else if (n <= 60){
				p->it = 4;
			}
			else if (n <= 75){
				p->it = 5;
			}
			else if (n <= 90){
				p->it = 6;
			}
			else if (n <= 96){
				p->it = 7;
			}
			else if (n <= 99){
				p->it = 8;
			}
		}
		else if (pattern == 4){
			if (n <= 19){
				p->it = 3;
			}
			else if (n <= 44){
				p->it = 4;
			}
			else if (n <= 64){
				p->it = 5;
			}
			else if (n <= 84){
				p->it = 6;
			}
			else if (n <= 94){
				p->it = 7;
			}
			else if (n <= 99){
				p->it = 8;
			}
		}
		p->next = NULL;
		p->x = x;
		p->y = y;
	}
	else if (situation == 3 && rand() % 100 <= 33){
		n = rand() % 100;
		if (pattern == 1){
			if (n <= 3){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 3;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 7){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 4;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 11){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 5;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 12){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 7;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 13){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 8;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 15){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 2;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 17){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 9;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 19){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 10;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
		}
		else if (pattern == 2){
			if (n <= 2){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 3;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 5){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 4;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 8){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 5;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 9){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 2;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 10){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 9;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
		}
		else if (pattern == 3){
			if (n <= 4){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 3;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 9){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 4;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 14){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 5;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 16){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 7;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 18){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 8;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 21){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 2;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 24){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 9;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 27){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 10;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
		}
		else if (pattern == 4){
			if (n <= 5){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 3;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 10){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 4;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 16){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 5;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 19){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 7;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 22){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 8;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 23){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 2;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 24){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 9;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 25){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 10;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
		}
	}
	else if (situation == 4 && rand() % 100<=33){
		n = rand() % 100;
		if (pattern == 1){
			if (n <= 3){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 3;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 7){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 4;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 11){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 6;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 12){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 7;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 13){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 8;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 15){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 2;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 17){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 9;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 19){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 10;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
		}
		else if (pattern == 2){
			if (n <= 2){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 3;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 5){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 4;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 8){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 6;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 9){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 2;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 10){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 9;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
		}
		else if (pattern == 3){
			if (n <= 4){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 3;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 9){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 4;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 14){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 6;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 16){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 7;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 18){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 8;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 21){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 2;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 24){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 9;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 27){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 10;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
		}
		else if (pattern == 4){
			if (n <= 5){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 3;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 10){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 4;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 16){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 6;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 19){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 7;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 22){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 8;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 23){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 2;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 24){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 9;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
			else if (n <= 25){
				itemhead->n++;
				p->next = (struct item *)malloc(sizeof(struct item));
				p = p->next;
				p->it = 10;
				p->next = NULL;
				p->x = x;
				p->y = y;
			}
		}
	}
}

void randbrick(int p){
	int i, j,t,b;
	if (p == 2){
		for (t = 0; t < 20;){
			i = rand() % 18 + 1;
			j = rand() % 12 + 1;
			if (map[i][j] == 0){
				t++;
				b = rand() % 9+1;
				map[i][j] = b;
				if (b <= 6) bricknum += b;
				else if (b == 7) bricknum++;
				else if (b == 8) bricknum++;
				else if (b == 9) bricknum++;
			}
		}
	}
	else if (p == 4){
		for (t = 0; t < 20;){
			i = rand() % 22 + 1;
			j = rand() % 12 + 1;
			if (map[i][j] == 0){
				t++;
				b = rand() % 7 + 3;
				map[i][j] = b;
				if (b <= 6) bricknum += b;
				else if (b == 7) bricknum++;
				else if (b == 8) bricknum++;
				else if (b == 9) bricknum++;
			}
		}
	}
}

void boom(int i, int j){
	int i1,j1;
	if (map[i][j] == 1) dropitem(50 * j - 25, 25 * i, 1);
	if (map[i][j] == 8) dropitem(50 * j - 25, 25 * i, 2);
	if (map[i][j] == 7) dropitem(50 * j - 25, 25 * i, 3);
	if (map[i][j] >= 2 && map[i][j] <= 6&&coinfo.fire>0) dropitem(50 * j - 25, 25 * i, 4);
	if (pattern == 2 && bricknum <= 60) randbrick(2);
	if (pattern == 4 && bricknum <= 80) randbrick(4);
	if(map[i][j]==9){
		for(i1=i-1;i1<=i+1;i1++){
			for(j1=j-1;j1<=j+1;j1++){
				if(map[i1][j1]>0&&map[i1][j1]<6){
					bricknum++;
					map[i1][j1]++;
					score=max(0,score-10);
				}
				else if(map[i1][j1]==7) map[i1][j1]=1;
			}
		}
		score+=25;
	}
	if(coinfo.ice>0){
		if(map[i][j]==1){
			map[i][j]--;
			bricknum--;
			score+=5;
		}
		else if(map[i][j]==7){
			map[i][j]=0;
			bricknum--;
			score+=5;
		}
		else if (map[i][j] == 8){
			map[i][j] = 0;
			bricknum--;
			score+=50;
		}
		else if(map[i][j]==9){
			map[i][j]=0;
			bricknum--;
		}
		for(i1=i-1;i1<=i+1;i1++){
			for(j1=j-1;j1<=j+1;j1++){
				if(map[i1][j1]>0&&map[i1][j1]<7){
					bricknum-=(map[i1][j1]-1);
					map[i1][j1]=7;
					score+=10;
				}
			}
		}
	}
	else if(coinfo.fire>=1){
		if(map[i][j]>=0&&map[i][j]<7){
			bricknum-=(map[i][j]);
			score+=map[i][j]*3;
			map[i][j]=0;
		}
		else if(map[i][j]>=7&&map[i][j]<=9){
			if(map[i][j]==7)score+=5;
			else if(map[i][j]==8)score+=50;
			else if(map[i][j]==8)score+=30;
			map[i][j]=0;
			bricknum--;
		}
	}
	else {
		if(map[i][j]>0&&map[i][j]<7){
			score+=map[i][j]*2;
			map[i][j]--;
			bricknum--;
		}
		else if(map[i][j]>=7&&map[i][j]<=9){
			if(map[i][j]==7)score+=3;
			else if(map[i][j]==8)score+=40;
			else if(map[i][j]==8)score+=20;
			map[i][j]=0;
			bricknum--;
		}
	}
}

void gameinitial(){
	int i,j;
	tNow=0;
	face=7;
	ballx=300;
	bally=580;
	ballvx=3;
	ballball=1;
	coinfo.fire = 0;
	coinfo.ice = 0;
	coinfo.stretch = 0;
	lbat = 150;
	if(pattern==1||pattern==3||pattern==4)
		if(coinfo.life==0)
			coinfo.life=3;
	if(pattern==2)coinfo.life=0;

	for(i=1;i<25;i++){
		for(j=1;j<13;j++){
			map[i][j]=0;
		}
	}
	if (pattern == 1 || pattern == 3){
		if (stage == 1){
			bricknum = 16;
			for (i = 5; i < 9; i++){
				for (j = 5; j < 9; j++)
					map[i][j] = 1;
			}
			map[5 + rand() % 4][5 + rand() % 4] = 8;
			map[5 + rand() % 4][5 + rand() % 4] = 8;
			map[5 + rand() % 4][5 + rand() % 4] = 8;
		}
		else if (stage == 2){
			bricknum = 58;
			for (i = 4; i < 7; i++){
				for (j = 4; j < 7; j++)
					map[i][j] = 1;
			}
			for (i = 4; i < 7; i++){
				for (j = 7; j < 10; j++)
					map[i][j] = 2;
			}
			for (i = 7; i < 10; i++){
				for (j = 4; j < 7; j++)
					map[i][j] = 2;
			}
			for (i = 7; i < 10; i++){
				for (j = 7; j<10; j++)
					map[i][j] = 1;
			}
			map[1][1] = map[1][2] = map[1][11] = map[1][12] = 8;
		}
		else if (stage == 3){
			bricknum = 61;
			for (i = 11; i>1; i -= 3){
				for (j = 2; j<12; j += 3)
					map[i][j] = 1;
			}
			for (i = 10; i>1; i -= 3){
				for (j = 3; j<12; j += 3)
					map[i][j] = 2;
			}
			for (i = 9; i>1; i -= 3){
				for (j = 4; j < 12; j += 3)
					map[i][j] = 3;
			}
		}
		else if (stage == 4){
			bricknum = 152;
			for (i = 2; i < 12; i++){
				for (j = 2; j < 12; j++)
					map[i][j] = 4;
			}
			for (i = 3; i < 11; i++){
				for (j = 3; j < 11; j++)
					map[i][j] = 3;
			}
			for (i = 4; i < 10; i++){
				for (j = 4; j < 10; j++)
					map[i][j] = 2;
			}
			for (i = 5; i < 9; i++){
				for (j = 5; j < 9; j++)
					map[i][j] = 1;
			}
			for (i = 1; i < 6; i++){
				for (j = 1; j < 13; j++)
					map[i][j] = 0;
			}
			for (j = 2, i = 6; j < 12; j++)
				map[i][j] = 8;
		}
		else if(stage==5){
			bricknum=116;
			for(i=3;i<14;i++){
				for(j=2;j<12;j++)
					map[i][j]=1;
			}
			map[3][4]=map[3][5]=map[3][8]=map[3][9]=map[4][3]=map[4][6]=map[4][7]=map[4][10]=map[5][2]=map[6][2]=map[7][2]=map[5][11]=map[6][11]=map[7][11]=map[6][5]=map[6][8]=map[8][3]=map[9][3]=map[8][10]=map[9][10]=map[9][6]=map[9][7]=map[12][5]=map[12][8]=map[13][6]=map[13][7]=map[10][4]=map[11][4]=map[10][9]=map[11][9]=9;
			map[1][1]=map[1][2]=map[2][1]=map[1][11]=map[1][12]=map[2][12]=8;
		}
		else if (stage == 6){
			bricknum = 179;
			for (i = 2; i<9; i++){
				for (j = 2; j<6; j++)
					map[i][j] = 5;
			}
			for (i = 2; i<9; i++){
				for (j = 8; j<12; j++)
					map[i][j] = 3;
			}
			for (i = 3; i <= 6; i += 3) map[i][3] = 8;
			for (i = 3; i <= 6; i += 3) map[i][4] = 9;
			for (i = 3; i <= 6; i += 3) map[i][9] = 8;
			for (i = 3; i <= 6; i += 3) map[i][10] = 9;
			for (i = 4; i <= 7; i += 3) map[i][3] = 9;
			for (i = 4; i <= 7; i += 3) map[i][4] = 8;
			for (i = 4; i <= 7; i += 3) map[i][9] = 9;
			for (i = 4; i <= 7; i += 3) map[i][10] = 8;
			map[2][5] = map[5][5] = map[8][5] = map[2][8] = map[2][11] = map[8][9] = map[8][10] = 0;
			for (i = 10; i <= 16; i++)map[i][2] = 2;
			for (i = 10; i <= 16; i++)map[i][8] = 1;
			for (j = 3; j <= 5; j++)map[16][j] = 2;
			for (j = 9; j <= 11; j++)map[16][j] = 1;

		}
		else if(stage==7){
			bricknum=122;
			map[13][6] = map[13][7] = 1;
			map[12][5] = map[12][8] = 2;
			map[12][4] = map[12][9] = 3;
			map[11][3] = map[11][10] = 4;
			map[10][3] = map[10][10] = 5;
			map[1][2] = map[1][11] = map[2][1] = map[2][12] = map[8][6] = map[8][7] = map[9][6] = map[9][7] = map[10][6] = map[10][7] = 6;
			for (i = 4; i<7; i++){
				for (j = 3; j<6; j++)
					map[i][j] = 9;
			}
			for (i = 4; i<7; i++){
				for (j = 8; j<11; j++)
					map[i][j] = 9;
			}
			map[11][4] = map[11][9] = map[13][8] = map[13][5] = 9;
			map[3][3] = map[3][4] = map[3][5] = map[3][8] = map[3][9] = map[3][10] = map[5][4] = map[5][9] = 7;
			map[1][1] = map[1][12] = map[8][4] = map[8][9] = 8;
		}
		else if (stage == 8){
			bricknum = 226;
			for (j = 5; j <= 8; j++)map[2][j] = 1;
			for (j = 4; j <= 9; j++)map[3][j] = 1;
			for (j = 3; j <= 10; j++)map[4][j] = 1;
			for (j = 3; j <= 10; j++)map[5][j] = 1;
			for (j = 3; j <= 10; j++)map[6][j] = 1;
			for (j = 3; j <= 10; j++)map[7][j] = 1;
			map[8][4] = map[8][8] = 1;
			for (i = 6; i<11; i++){
				for (j = 5; j<8; j++)
					map[i][j] = 4;
			}
			map[11][4] = map[11][5] = map[11][7] = map[11][8] = map[12][3] = map[12][4] = map[12][6] = map[12][8] = map[12][9] = map[13][2] = map[13][3] = map[13][5] = map[13][6] = map[13][7] = map[13][9] = map[13][10] = map[14][2] = map[14][5] = map[14][7] = map[14][10] = map[14][11] = map[15][1] = map[15][2] = map[15][4] = map[15][5] = map[15][7] = map[15][8] = map[15][9] = map[15][11] = map[15][12] = 4;
			map[5][6] = map[8][6] = map[11][6] = 8;
			map[12][5] = map[12][7] = map[13][4] = map[13][8] = map[14][3] = map[14][4] = map[14][8] = map[14][9] = map[15][3] = map[15][10] = 9;
		}
		else if (stage == 9){
			bricknum = 312;
			for (i = 5, j = 7; i <= 9; i++, j++) map[i][j] = 6;
			for (i = 6, j = 7; i <= 9; i++, j++) map[i][j] = 4;
			for (i = 7, j = 7; i <= 9; i++, j++) map[i][j] = 2;
			for (i = 8, j = 7; i <= 9; i++, j++) map[i][j] = 7;
			for (i = 10, j = 2; i <= 14; i++, j++) map[i][j] = 6;
			for (i = 10, j = 3; i <= 13; i++, j++) map[i][j] = 5;
			for (i = 10, j = 4; i <= 12; i++, j++) map[i][j] = 3;
			for (i = 10, j = 5; i <= 11; i++, j++) map[i][j] = 1;
			for (i = 9, j = 2; j <= 6; i--, j++) map[i][j] = 6;
			for (i = 9, j = 3; j <= 6; i--, j++) map[i][j] = 5;
			for (i = 9, j = 4; j <= 6; i--, j++) map[i][j] = 3;
			for (i = 9, j = 5; j <= 6; i--, j++) map[i][j] = 1;
			for (i = 14, j = 7; i >= 10; i--, j++) map[i][j] = 6;
			for (i = 13, j = 7; i >= 10; i--, j++) map[i][j] = 4;
			for (i = 12, j = 7; i >= 10; i--, j++) map[i][j] = 2;
			for (i = 11, j = 7; i >= 10; i--, j++) map[i][j] = 7;
			map[2][3] = map[2][5] = map[2][9] = map[9][7] = map[10][7] = 9;
			map[1][3] = map[1][4] = map[2][2] = map[3][3] = map[3][4] = 4;
			map[1][11] = map[2][10] = map[2][11] = map[2][12] = map[3][11] = 5;
			map[1][7] = map[2][6] = map[2][7] = map[2][8] = map[3][7] = 6;
			map[9][6] = map[10][6] = 8;
		}
		else if (stage == 10){
			bricknum = 330;
			for (i = 11; i <= 13; i++){
				for (j = 1; j <= 3; j++){
					map[i][j] = 1;
				}
			}
			for (i = 11; i <= 13; i++){
				for (j = 10; j <= 12; j++){
					map[i][j] = 2;
				}
			}
			for (i = 11; i <= 13; i++){
				for (j = 5; j <= 8; j++){
					map[i][j] = 3;
				}
			}
			for (i = 3; i <= 9; i++){
				for (j = 1; j <= 3; j++){
					map[i][j] = 4;
				}
			}
			for (i = 3; i <= 9; i++){
				for (j = 10; j <= 12; j++){
					map[i][j] = 5;
				}
			}
			for (i = 3; i <= 9; i++){
				for (j = 5; j <= 8; j++){
					map[i][j] = 6;
				}
			}
			for (i = 4; i <= 8; i += 2) map[i][2] = 9;
			for (i = 4; i <= 8; i += 2) map[i][6] = 9;
			for (i = 4; i <= 8; i += 2) map[i][7] = 8;
			for (i = 4; i <= 8; i += 2) map[i][11] = 9;
			for (i = 5; i <= 7; i += 2) map[i][2] = 8;
			for (i = 5; i <= 7; i += 2) map[i][6] = 8;
			for (i = 5; i <= 7; i += 2) map[i][7] = 9;
			for (i = 5; i <= 7; i += 2) map[i][11] = 8;
			map[12][2] = map[12][6] = map[12][7] = map[12][11] = 9;
		}
	}
	else if (pattern == 2){
		bricknum = 72;
		for (j = 1; j <= 12; j++) map[5][j] = 3;
		for (j = 1; j <= 12; j++) map[6][j] = 2;
		for (j = 1; j <= 12; j++) map[7][j] = 1;
	}
	else if (pattern == 4){
		bricknum = 0;
		randbrick(4);
	}
	setoff();

}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;
	memset(&msg, 0, sizeof(MSG));

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_BALL, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BALL));
	
	while(msg.message != WM_QUIT)	//消息循环
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	//处理消息
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			tNow = GetTickCount();
			if (tNow-tPre >= 10)	//每隔100毫秒进行画面刷新
			{
				MyPaint(hDC);
			}
			else
			{
				Sleep(1);
			}
		}
	}


	return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
//  注释:
//
//    仅当希望
//    此代码与添加到 Windows 95 中的“RegisterClassEx”
//    函数之前的 Win32 系统兼容时，才需要此函数及其用法。调用此函数十分重要，
//    这样应用程序就可以获得关联的
//    “格式正确的”小图标。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BALL));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_BALL);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
  // HWND hWnd;
	srand((unsigned)time(NULL));
   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 1008, 655, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   itemhead->next = NULL;
   itemhead->n = 0;

	hDC=GetDC(hWnd);
	mDC=CreateCompatibleDC(hDC);
	bDC=CreateCompatibleDC(hDC);
	HBITMAP bmp = CreateCompatibleBitmap(hDC, 1000, 600);
	SelectObject(mDC, bmp);
	f[3]=LoadBitmap(hInst,MAKEINTRESOURCE(FACE3));
	f[4] = LoadBitmap(hInst, MAKEINTRESOURCE(FACE4));
	f[5] = LoadBitmap(hInst, MAKEINTRESOURCE(FACE5));
	f[6] = LoadBitmap(hInst, MAKEINTRESOURCE(FACE6));
	f[9]=LoadBitmap(hInst,MAKEINTRESOURCE(FACE9));
	f[10]=LoadBitmap(hInst,MAKEINTRESOURCE(FACE10));
	f[11] = LoadBitmap(hInst, MAKEINTRESOURCE(FACE11));
	f[12] = LoadBitmap(hInst, MAKEINTRESOURCE(FACE12));
	f[13]=LoadBitmap(hInst,MAKEINTRESOURCE(FACE13));
	f[14]=LoadBitmap(hInst,MAKEINTRESOURCE(FACE14));
	f[15]=LoadBitmap(hInst,MAKEINTRESOURCE(FACE15));

	b[1]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON1));
	b[2]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON2));
	b[3]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON3));
	b[4]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON4));
	b[5]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON5));
	b[6]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON6));
	b[7]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON7));
	b[8]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON8));
	b[9]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON9));
	b[10]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON10));
	b[11]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON11));
	b[12]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON12));
	b[13]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON13));
	b[14]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON14));
	b[15]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON15));
	b[16]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON16));
	b[17]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON17));
	b[18]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON18));
	b[19]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON19));
	b[20]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON20));
	b[21]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON21));
	b[22]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON22));
	b[23]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON23));
	b[24]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON24));
	b[25]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON25));
	b[26]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON26));
	b[27]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON27));
	b[28]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON28));
	b[29]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON29));
	b[30]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON30));
	b[31]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON31));
	b[32]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON32));
	b[33]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON33));
	b[34]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON34));
	b[35]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON35));
	b[36]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON36));
	b[37]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON37));
	b[38]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON38));
	b[39]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON39));
	b[40]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON40));
	b[41]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON41));
	b[42]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON42));
	b[43]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON43));
	b[44]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON44));
	b[45]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON45));
	b[46]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON46));
	b[47]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON47));
	b[48]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON48));
	b[49]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON49));
	b[50]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON50));
	b[51]=LoadBitmap(hInst,MAKEINTRESOURCE(BUTTON51));
	b[52] = LoadBitmap(hInst, MAKEINTRESOURCE(BUTTON52));
	b[53] = LoadBitmap(hInst, MAKEINTRESOURCE(BUTTON53));

	fra[1]=LoadBitmap(hInst,MAKEINTRESOURCE(FRAMEA1));

	frb[1]=LoadBitmap(hInst,MAKEINTRESOURCE(FRAMEB1));

	bg[1]=LoadBitmap(hInst,MAKEINTRESOURCE(BG1));

	ba[1]=LoadBitmap(hInst,MAKEINTRESOURCE(BAT1));

	bal[1]=LoadBitmap(hInst,MAKEINTRESOURCE(BALL1));
	bal[8]=LoadBitmap(hInst,MAKEINTRESOURCE(BALLFIRE));
	bal[9]=LoadBitmap(hInst,MAKEINTRESOURCE(BALLICE));

	bri[1]=LoadBitmap(hInst,MAKEINTRESOURCE(BRICK1));
	bri[2]=LoadBitmap(hInst,MAKEINTRESOURCE(BRICK2));
	bri[3]=LoadBitmap(hInst,MAKEINTRESOURCE(BRICK3));
	bri[4]=LoadBitmap(hInst,MAKEINTRESOURCE(BRICK4));
	bri[5]=LoadBitmap(hInst,MAKEINTRESOURCE(BRICK5));
	bri[6]=LoadBitmap(hInst,MAKEINTRESOURCE(BRICK6));
	bri[7] = LoadBitmap(hInst, MAKEINTRESOURCE(BRICK7));
	bri[8] = LoadBitmap(hInst, MAKEINTRESOURCE(BRICK8));
	bri[9] = LoadBitmap(hInst, MAKEINTRESOURCE(BRICK9));

	icon[1]=LoadBitmap(hInst,MAKEINTRESOURCE(ICON1));
	icon[4] = LoadBitmap(hInst, MAKEINTRESOURCE(ICON4));
	icon[5] = LoadBitmap(hInst, MAKEINTRESOURCE(ICON5));
	icon[6] = LoadBitmap(hInst, MAKEINTRESOURCE(ICON6));
	icon[7] = LoadBitmap(hInst, MAKEINTRESOURCE(ICON7));
	icon[8] = LoadBitmap(hInst, MAKEINTRESOURCE(ICON8));
	icon[9] = LoadBitmap(hInst, MAKEINTRESOURCE(ICON9));
	icon[10] = LoadBitmap(hInst, MAKEINTRESOURCE(ICON10));

	num[0] = LoadBitmap(hInst, MAKEINTRESOURCE(NUM0));
	num[1] = LoadBitmap(hInst, MAKEINTRESOURCE(NUM1));
	num[2] = LoadBitmap(hInst, MAKEINTRESOURCE(NUM2));
	num[3] = LoadBitmap(hInst, MAKEINTRESOURCE(NUM3));
	num[4] = LoadBitmap(hInst, MAKEINTRESOURCE(NUM4));
	num[5] = LoadBitmap(hInst, MAKEINTRESOURCE(NUM5));
	num[6] = LoadBitmap(hInst, MAKEINTRESOURCE(NUM6));
	num[7] = LoadBitmap(hInst, MAKEINTRESOURCE(NUM7));
	num[8] = LoadBitmap(hInst, MAKEINTRESOURCE(NUM8));
	num[9] = LoadBitmap(hInst, MAKEINTRESOURCE(NUM9));

	item[1] = LoadBitmap(hInst, MAKEINTRESOURCE(ITEM1));
	item[2] = LoadBitmap(hInst, MAKEINTRESOURCE(ITEM2));
	item[3] = LoadBitmap(hInst, MAKEINTRESOURCE(ITEM3));
	item[4] = LoadBitmap(hInst, MAKEINTRESOURCE(ITEM4));
	item[5] = LoadBitmap(hInst, MAKEINTRESOURCE(ITEM5));
	item[6] = LoadBitmap(hInst, MAKEINTRESOURCE(ITEM6));
	item[7] = LoadBitmap(hInst, MAKEINTRESOURCE(ITEM7));
	item[8] = LoadBitmap(hInst, MAKEINTRESOURCE(ITEM8));
	item[9] = LoadBitmap(hInst, MAKEINTRESOURCE(ITEM9));
	item[10] = LoadBitmap(hInst, MAKEINTRESOURCE(ITEM10));

	get_from_file();

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_LBUTTONDOWN:
		if(ifbutton==1){
			if(face==3){
				if(button==2) face=4;
				else if(button==1) {
					if (ulinfo.pattern[1] == 1){
						pattern = 1;
						stage = 1;
						gameinitial();
						face = 7;
					}
					else if (ulinfo.pattern[1] <= 3){
						pattern = 1;
						face = 6;
					}
					else 
						face = 5;
				}
			}
			else if(face==4){
				if(button==9) face=3;
				else if(button==5) face=9;
				else if(button==6) face=10;
			}
			else if (face == 5){
				if (button == 32){
					pattern = 1;
					face = 6;
				}
				else if (button == 34){
					pattern = 2;
					gameinitial();
					face = 7;
				}
				else if (button == 36&&ulinfo.pattern[3]!=0){
					pattern = 3;
					if (ulinfo.pattern[3] == 1){
						stage = 1;
						gameinitial();
						face = 7;
					}
					else face = 6;
				}
				else if (button == 38 && ulinfo.pattern[4] != 0){
					pattern = 4;
					gameinitial();
					face = 7;
				}
				else if (button == 10){
					face = 3;
				}
			}
			else if (face == 6){
				if (button >= 21 && button <= 30 && ulinfo.pattern[pattern] >= button - 20){
					stage = button - 20;
					gameinitial();
					face = 7;
				}
			}
			else if(face==7){
				if (button == 8) {
					face = 3;
					coinfo.life = 0;
				}
				if (pause == 1){
					pause = 0;
					setob = 0;
				}
				if (button == 7) {
					if (pause == 0) pause = 1;
				}
			}
			else if(face==9){
				if(button==48) face=15;
				else if(button==49) face=14;
				else if (button == 50) {
					face = 4;
				}
			}
			else if(face==10){
				if(button==45) face=4;
			}
			else if(face==11){
				if(button==46) {
					stage++;
					face=7;
					gameinitial();
				}
				else if(button==47) {
					face=3;
				}
			}
			else if (face == 12){
				if (button == 53){
					if (pattern == 1 && ulinfo.pattern[3] == 0){
						ulinfo.pattern[3] = 1;
					}
					else if (pattern == 3 && ulinfo.pattern[4] == 0){
						ulinfo.pattern[4] = 1;
					}
					if(pattern==1&&score>urinfo.adscore)urinfo.adscore=score;
					if(pattern==3&&score>urinfo.grscore)urinfo.grscore=score;

					if(pattern==1) urinfo.adtimes++;
					if(pattern==3) urinfo.grtimes++;
						
					save_to_file();
					score=0;
					coinfo.life=0;
					face = 3;
				}
			}
			else if(face==13){
				if(button==51){
					gameinitial();
					face = 7;
				}
				else if(button==52){
					face=3;
				}
			}
			else if(face==14||face==15){
				if (button == 44) {
					face = 9;
					save_to_file();
				}
			}
		}
		break;
	case WM_MOUSEMOVE:
		xm=LOWORD(lParam);
		ym=HIWORD(lParam);
		button=0;
		if(face==3){
			if(xm>=350&&xm<=650){
				if(ym>=100&&ym<=200){
					button=1;
					ifbutton=1;
				}
				else if(ym>200&&ym<=300){
					button=2;
					ifbutton=1;
				}
				else if(ym>300&&ym<=400){
					button=3;
					ifbutton=1;
				}
			}
			else if(xm>=0&&xm<=100&&ym>=550&&ym<=600){
				button=9;
				ifbutton=1;
			}
		}
		else if(face==4){
			if(xm>=0&&xm<=100&&ym>=550&&ym<=600){
				button=9;
				ifbutton=1;
			}
			else if(xm>=450&&xm<=600&&ym>=100&&ym<=150){
				button=4;
				ifbutton=1;
			}
			else if(xm>=550&&xm<=700&&ym>=180&&ym<=230){
				button=5;
				ifbutton=1;
			}
			else if(xm>=650&&xm<=800&&ym>=260&&ym<=310){
				button=6;
				ifbutton=1;
			}
		}
		else if (face == 5){
			if (xm >= 150 && xm <= 300 && ym >= 50 && ym <= 100){
				button = 32;
				ifbutton = 1;
			}
			else if (xm >= 400 && xm <= 550 && ym >= 150 && ym <= 200){
				button = 34;
				ifbutton = 1;
			}
			else if (xm >= 650 && xm <= 800 && ym >= 250 && ym <=300){
				button = 36;
				ifbutton = 1;
			}
			else if (xm >= 850 && xm <= 1000 && ym >= 350 && ym <= 400){
				button = 38;
				ifbutton = 1;
			}
			else if (xm >=50 && xm <= 150 && ym >= 550 && ym <= 600){
				button = 10;
				ifbutton = 1;
			}
		}
		else if (face == 6){
			if (xm >= 50 && xm <= 100 && ym >= 50 && ym <= 100){
				button = 21;
				ifbutton = 1;
			}
			else if (xm >= 150 && xm <= 200 && ym >= 10 && ym <= 150){
				button = 22;
				ifbutton = 1;
			}
			else if (xm >= 200 && xm <= 250 && ym >= 200 && ym <= 250){
				button = 23;
				ifbutton = 1;
			}
			else if (xm >= 250 && xm <= 300 && ym >= 300 && ym <= 350){
				button = 24;
				ifbutton = 1;
			}
			else if (xm >= 350 && xm <= 400 && ym >= 350 && ym <= 400){
				button = 25;
				ifbutton = 1;
			}
			else if (xm >= 450 && xm <= 500 && ym >= 400 && ym <= 450){
				button = 26;
				ifbutton = 1;
			}
			else if (xm >= 550 && xm <= 600 && ym >= 350 && ym <= 400){
				button = 27;
				ifbutton = 1;
			}
			else if (xm >= 650 && xm <= 700 && ym >= 300 && ym <= 350){
				button = 28;
				ifbutton = 1;
			}
			else if (xm >= 750 && xm <= 800 && ym >= 400 && ym <= 450){
				button = 29;
				ifbutton = 1;
			}
			else if (xm >= 900 && xm <= 950 && ym >= 350 && ym <= 400){
				button = 30;
				ifbutton = 1;
			}
		}
		else if(face==7){
			if(xm>=610&&xm<800&&ym>=540&&ym<=590) {
				button=7;
				ifbutton=1;
			}
			else if(xm>=800&&xm<990&&ym>=540&&ym<=590){
				button=8;
				ifbutton=1;
			}
		}
		else if(face==9){
			if(xm>=200&&xm<350&&ym>=250&&ym<=300) {
				button=49;
				ifbutton=1;
			}
			else if(xm>=400&&xm<550&&ym>=250&&ym<=300) {
				button=48;
				ifbutton=1;
			}
			else if(xm>=0&&xm<100&&ym>=550&&ym<=600) {
				button=50;
				ifbutton=1;
			}
		}
		else if(face==10){
			if(xm>=50&&xm<150&&ym>=550&&ym<=600) {
				button=45;
				ifbutton=1;
			}
		}
		else if(face==11){
			if(xm>=350&&xm<400&&ym>=400&&ym<=450) {
				button=46;
				ifbutton=1;
			}
			else if(xm>=600&&xm<650&&ym>=400&&ym<=450) {
				button=47;
				ifbutton=1;
			}
		}
		else if (face == 12){
			if (xm >= 450 && xm<650 && ym >= 300 && ym <= 350) {
				button = 53;
				ifbutton = 1;
			}
		}
		else if(face==13){
			if(xm>=150&&xm<200&&ym>=350&&ym<=400) {
				button=51;
				ifbutton=1;
			}
			else if(xm>=350&&xm<400&&ym>=350&&ym<=400) {
				button=52;
				ifbutton=1;
			}
		}
		else if(face==14||face==15){
			if(xm>=60&&xm<190&&ym>=490&&ym<=540) {
				button=44;
				ifbutton=1;
			}
			else if(xm>=50&&xm<225&&ym>=50&&ym<=110) {
				button=41;
				ifbutton=1;
			}
			else if(xm>=50&&xm<225&&ym>=170&&ym<=230) {
				button=42;
				ifbutton=1;
			}
			else if(xm>=50&&xm<225&&ym>=280&&ym<=340) {
				button=43;
				ifbutton=1;
			}
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}


void MyPaint(HDC hdc)
{
	if (face == 7){
		if (setob == 1){
			ballx = max(lbat / 2 - MAXVX, min(600 + MAXVX - lbat / 2, xm));
		}
		SelectObject(bDC,bg[background]);
		BitBlt(mDC, 0, 0, 600, 600, bDC, 0, 0, SRCCOPY);
		BitBlt(mDC, 600, 0, 400, 600, bDC, 100, 0, SRCCOPY);
		if (tNow == 0) xm = 300;
		SelectObject(bDC,ba[bat]);
		TransparentBlt2(mDC, min(600 + MAXVX - lbat, max(xm - lbat / 2, -MAXVX))+5, 580, min(lbat, 600 - (min(xm, 600 + MAXVX - lbat / 2) - lbat / 2))-10, 10, bDC, 0, 0, 150, 10, RGB(0, 0, 0));

		SelectObject(bDC,bal[1]);
		TransparentBlt2(mDC, ballx-5,bally-5,10,10, bDC, 0, 0, 10, 10, RGB(255,255,255));


		if(coinfo.ice>0){
			SelectObject(bDC,bal[9]);
			TransparentBlt2(mDC, ballx1-5,bally1-5,10,10, bDC, 0, 0, 10, 10, RGB(255,255,255));
			SelectObject(bDC,bal[9]);
			TransparentBlt2(mDC, ballx2-5,bally2-5,10,10, bDC, 0, 0, 10, 10, RGB(255,255,255));
			SelectObject(bDC,bal[9]);
			TransparentBlt2(mDC, ballx3-5,bally3-5,10,10, bDC, 0, 0, 10, 10, RGB(255,255,255));
			SelectObject(bDC,bal[9]);
			TransparentBlt2(mDC, ballx4-5,bally4-5,10,10, bDC, 0, 0, 10, 10, RGB(255,255,255));
		}
		else if (coinfo.fire>0){
			SelectObject(bDC,bal[8]);
			TransparentBlt2(mDC, ballx1-5,bally1-5,10,10, bDC, 0, 0, 10, 10, RGB(255,255,255));
			SelectObject(bDC,bal[8]);
			TransparentBlt2(mDC, ballx2-5,bally2-5,10,10, bDC, 0, 0, 10, 10, RGB(255,255,255));
			SelectObject(bDC,bal[8]);
			TransparentBlt2(mDC, ballx3-5,bally3-5,10,10, bDC, 0, 0, 10, 10, RGB(255,255,255));
			SelectObject(bDC,bal[8]);
			TransparentBlt2(mDC, ballx4-5,bally4-5,10,10, bDC, 0, 0, 10, 10, RGB(255,255,255));
		}

		int i,j;
		for(i=1;i<25;i++){
			for(j=1;j<13;j++){
				if(bri[map[i][j]]!=0){
					SelectObject(bDC,bri[map[i][j]]);
					BitBlt(mDC,j*50-50,i*25-25,50,25,bDC,0,0,SRCCOPY);
				}
			}
		}

		struct item*p;
		if (itemhead->n != 0){
			p = itemhead;
			while (p->next != NULL){
				p = p->next;
				SelectObject(bDC, item[p->it]);
				if (p->it == 1 || p->it == 2)TransparentBlt2(mDC, p->x - 10, p->y - 10, 20, 20, bDC, 0, 0, 10, 10, RGB(255, 255, 255));
				else if (p->it >=3)TransparentBlt2(mDC, p->x - 12, p->y - 12, 25, 25, bDC, 0, 0, 25, 25, RGB(255, 255, 255));
			}
		}

		SelectObject(bDC,fra[frame]);
		TransparentBlt2(mDC, 0, 0, 600, 600, bDC, 0, 0, 600, 600, RGB(255,255,255));
		SelectObject(bDC,frb[frame]);
		TransparentBlt2(mDC, 600, 0, 400, 600, bDC, 0, 0, 400, 600, RGB(255,255,255));

		SelectObject(bDC,b[7]);
		BitBlt(mDC, 610, 540, 800, 590, bDC, 0, 0, SRCCOPY);
		SelectObject(bDC,b[8]);
		BitBlt(mDC, 800, 540, 990, 590, bDC, 0, 0, SRCCOPY);
	}
	else if(face==13){
		SelectObject(bDC,f[face]);
		BitBlt(mDC,100,150,400,300,bDC,0,0,SRCCOPY);
	}
	else {
		SelectObject(bDC,f[face]);
		BitBlt(mDC,0,0,1000,600,bDC,0,0,SRCCOPY);
	}
	
	if (face == 6){
		SelectObject(bDC, b[11]);
		BitBlt(mDC, 50, 50, 50, 50, bDC, 0, 0, SRCCOPY);
		SelectObject(bDC, b[12]);
		BitBlt(mDC, 150, 100, 50, 50, bDC, 0, 0, SRCCOPY);
		SelectObject(bDC, b[13]);
		BitBlt(mDC, 200, 200, 50, 50, bDC, 0, 0, SRCCOPY);
		SelectObject(bDC, b[14]);
		BitBlt(mDC, 250, 300, 50, 50, bDC, 0, 0, SRCCOPY);
		SelectObject(bDC, b[15]);
		BitBlt(mDC, 350, 350, 50, 50, bDC, 0, 0, SRCCOPY);
		SelectObject(bDC, b[16]);
		BitBlt(mDC, 450, 400, 50, 50, bDC, 0, 0, SRCCOPY);
		SelectObject(bDC, b[17]);
		BitBlt(mDC, 550, 350, 50, 50, bDC, 0, 0, SRCCOPY);
		SelectObject(bDC, b[18]);
		BitBlt(mDC, 650, 300, 50, 50, bDC, 0, 0, SRCCOPY);
		SelectObject(bDC, b[19]);
		BitBlt(mDC, 750, 400, 50, 50, bDC, 0, 0, SRCCOPY);
		SelectObject(bDC, b[20]);
		BitBlt(mDC, 900, 350, 50, 50, bDC, 0, 0, SRCCOPY);
	}
	else if (face == 11){
		if (ulinfo.pattern[2] == 0 &&pattern == 1 &&stage>=3){
			SelectObject(bDC, icon[6]);
			BitBlt(mDC, 370, 180, 260, 66, bDC, 0, 0, SRCCOPY);
		}
	}
	else if (face == 12){
		if (pattern == 1 && ulinfo.pattern[3] == 0){
			SelectObject(bDC, icon[7]);
			BitBlt(mDC, 420, 200, 260, 66, bDC, 0, 0, SRCCOPY);
		}
		else if (pattern == 3 && ulinfo.pattern[4] == 0){
			SelectObject(bDC, icon[8]);
			BitBlt(mDC, 420, 200, 260, 66, bDC, 0, 0, SRCCOPY);
		}
	}


	if(ifbutton){
		if(face==3){
			if(button==1){
				SelectObject(bDC,b[1]);
				BitBlt(mDC,350,100,300,100,bDC,0,0,SRCCOPY);
			}
			else if(button==2){
				SelectObject(bDC,b[2]);
				BitBlt(mDC,350,200,300,100,bDC,0,0,SRCCOPY);
			}
			else if(button==3){
				SelectObject(bDC,b[3]);
				BitBlt(mDC,350,300,300,100,bDC,0,0,SRCCOPY);
			}
			else if(button==9){
				SelectObject(bDC,b[9]);
				BitBlt(mDC,0,550,100,50,bDC,0,0,SRCCOPY);
			}
		}
		else if(face==4){
			if(button==9){
				SelectObject(bDC,b[9]);
				BitBlt(mDC,0,550,100,50,bDC,0,0,SRCCOPY);
			}
			else if(button==4){
				SelectObject(bDC,b[4]);
				BitBlt(mDC,450,100,150,50,bDC,0,0,SRCCOPY);
			}
			else if(button==5){
				SelectObject(bDC,b[5]);
				BitBlt(mDC,550,180,150,50,bDC,0,0,SRCCOPY);
			}
			else if(button==6){
				SelectObject(bDC,b[6]);
				BitBlt(mDC,650,260,150,50,bDC,0,0,SRCCOPY);
			}
		}
		else if (face == 5){
			if (button == 32){
				SelectObject(bDC, b[32]);
				BitBlt(mDC, 150, 50, 150, 50, bDC, 0, 0, SRCCOPY);
			}
			else if (button == 34){
				SelectObject(bDC, b[34]);
				BitBlt(mDC, 400, 150, 150, 50, bDC, 0, 0, SRCCOPY);
			}
			else if (button == 36){
				SelectObject(bDC, b[36]);
				BitBlt(mDC, 650, 250, 150, 50, bDC, 0, 0, SRCCOPY);
			}
			else if (button == 38){
				SelectObject(bDC, b[38]);
				BitBlt(mDC, 850, 350, 150, 50, bDC, 0, 0, SRCCOPY);
			}
			else if (button == 10){
				SelectObject(bDC, b[10]);
				BitBlt(mDC, 50, 550, 100, 50, bDC, 0, 0, SRCCOPY);
			}
			if (ulinfo.pattern[3] == 0){
				SelectObject(bDC, b[35]);
				BitBlt(mDC, 650, 250, 150, 50, bDC, 0, 0, SRCCOPY);
			}
			if (ulinfo.pattern[4] == 0){
				SelectObject(bDC, b[37]);
				BitBlt(mDC, 850, 350, 150, 50, bDC, 0, 0, SRCCOPY);
			}
		}
		else if (face == 6){
			if (ulinfo.pattern[pattern] >= button - 20){
				if (button == 21){
					SelectObject(bDC, b[21]);
					BitBlt(mDC, 50, 50, 50, 50, bDC, 0, 0, SRCCOPY);
				}
				else if (button == 22){
					SelectObject(bDC, b[22]);
					BitBlt(mDC, 150, 100, 50, 50, bDC, 0, 0, SRCCOPY);
				}
				else if (button == 23){
					SelectObject(bDC, b[23]);
					BitBlt(mDC, 200, 200, 50, 50, bDC, 0, 0, SRCCOPY);
				}
				else if (button == 24){
					SelectObject(bDC, b[24]);
					BitBlt(mDC, 250, 300, 50, 50, bDC, 0, 0, SRCCOPY);
				}
				else if (button == 25){
					SelectObject(bDC, b[25]);
					BitBlt(mDC, 350, 350, 50, 50, bDC, 0, 0, SRCCOPY);
				}
				else if (button == 26){
					SelectObject(bDC, b[26]);
					BitBlt(mDC, 450, 400, 50, 50, bDC, 0, 0, SRCCOPY);
				}
				else if (button == 27){
					SelectObject(bDC, b[27]);
					BitBlt(mDC, 550, 350, 50, 50, bDC, 0, 0, SRCCOPY);
				}
				else if (button == 28){
					SelectObject(bDC, b[28]);
					BitBlt(mDC, 650, 300, 50, 50, bDC, 0, 0, SRCCOPY);
				}
				else if (button == 29){
					SelectObject(bDC, b[29]);
					BitBlt(mDC, 750, 400, 50, 50, bDC, 0, 0, SRCCOPY);
				}
				else if (button == 30){
					SelectObject(bDC, b[30]);
					BitBlt(mDC, 900, 350, 50, 50, bDC, 0, 0, SRCCOPY);
				}
			}
		}
		else if(face==9){
			if(button==48){
				SelectObject(bDC,b[48]);
				BitBlt(mDC,400,250,150,50,bDC,0,0,SRCCOPY);
			}
			else if(button==49){
				SelectObject(bDC,b[49]);
				BitBlt(mDC,200,250,150,50,bDC,0,0,SRCCOPY);
			}
			else if(button==50){
				SelectObject(bDC,b[50]);
				BitBlt(mDC,0,550,100,50,bDC,0,0,SRCCOPY);
			}
		}
		else if(face==10){
			if(button==45){
				SelectObject(bDC,b[45]);
				BitBlt(mDC,50,550,100,50,bDC,0,0,SRCCOPY);
			}
		}
		else if (face==11){
			if(button==46){
				SelectObject(bDC,b[46]);
				BitBlt(mDC,350,400,50,50,bDC,0,0,SRCCOPY);
			}
			if(button==47){
				SelectObject(bDC,b[47]);
				BitBlt(mDC,600,400,50,50,bDC,0,0,SRCCOPY);
			}
		}
		else if (face == 12){
			if (button == 53){
				SelectObject(bDC, b[53]);
				BitBlt(mDC, 450, 300, 200, 50, bDC, 0, 0, SRCCOPY);
			}
		}
		else if(face==13){
			if(button==51){
				SelectObject(bDC,b[51]);
				BitBlt(mDC,150,350,50,50,bDC,0,0,SRCCOPY);
			}
			else if(button==52){
				SelectObject(bDC,b[52]);
				BitBlt(mDC,350,350,50,50,bDC,0,0,SRCCOPY);
			}
		}
		else if(face==14||face==15){
			if(button==41){
				SelectObject(bDC,b[41]);
				BitBlt(mDC,53,57,180,65,bDC,0,0,SRCCOPY);
			}
			else if(button==42){
				SelectObject(bDC,b[42]);
				BitBlt(mDC,53,170,180,65,bDC,0,0,SRCCOPY);
			}
			else if(button==43){
				SelectObject(bDC,b[43]);
				BitBlt(mDC,53,285,175,65,bDC,0,0,SRCCOPY);
			}
			else if(button==44){
				SelectObject(bDC,b[44]);
				BitBlt(mDC,63,490,130,53,bDC,0,0,SRCCOPY);
			}
		}
	}

	if(face==7||face==14||face==15){
		SelectObject(bDC,icon[1]);
		TransparentBlt2(mDC, 850, 10, 25, 25, bDC, 0, 0, 25, 25, RGB(255,255,255));
		int t1,t2,i;
		t1 = ucinfo.money;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 950-15*i, 10, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}
	}
	if(face==10){
		int t1, t2, i;
		t1 = urinfo.adtimes;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 815 - 15 * i, 120, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}
		t1 = urinfo.grtimes;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 815 - 15 * i, 180, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}
		t1 = urinfo.adscore;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 815 - 15 * i, 240, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}
		t1 = urinfo.grscore;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 815 - 15 * i, 300, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}
		t1 = urinfo.liscore;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 815 - 15 * i, 360, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}
	}
	if (face == 14 || face == 15){
		int t1, t2, i;
		SelectObject(bDC, item[4]);
		TransparentBlt2(mDC, 850, 50, 25, 25, bDC, 0, 0, 25, 25, RGB(255, 255, 255));
		t1 = ucinfo.common;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 950 - 15 * i, 50, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}

		SelectObject(bDC, item[5]);
		TransparentBlt2(mDC, 850, 90, 25, 25, bDC, 0, 0, 25, 25, RGB(255, 255, 255));
		t1 = ucinfo.ice;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 950 - 15 * i, 90, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}

		SelectObject(bDC, item[6]);
		TransparentBlt2(mDC, 850, 130, 25, 25, bDC, 0, 0, 25, 25, RGB(255, 255, 255));
		t1 = ucinfo.fire;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 950 - 15 * i, 130, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}

		SelectObject(bDC, item[7]);
		TransparentBlt2(mDC, 850, 170, 25, 25, bDC, 0, 0, 25, 25, RGB(255, 255, 255));
		t1 = ucinfo.gold;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 950 - 15 * i, 170, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}

		SelectObject(bDC, item[8]);
		TransparentBlt2(mDC, 850, 210, 25, 25, bDC, 0, 0, 25, 25, RGB(255, 255, 255));
		t1 = ucinfo.rainbow;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 950 - 15 * i, 210, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}
	}

	if (face == 7){
		int i;
		SelectObject(bDC, item[1]);
		for (i = 0; i < coinfo.fire; i++) TransparentBlt2(mDC, 620 + 25 * i, 80, 25, 25, bDC, 0, 0, 10, 10, RGB(255, 255, 255));
		SelectObject(bDC, item[2]);
		for (i = 0; i < coinfo.ice; i++) TransparentBlt2(mDC, 620 + 25 * i, 120, 25, 25, bDC, 0, 0, 10, 10, RGB(255, 255, 255));
		SelectObject(bDC, icon[4]);
		for (i = 0; i < coinfo.life; i++) TransparentBlt2(mDC, 620 + 25 * i, 160, 25, 25, bDC, 0, 0, 25, 25, RGB(255, 255, 255));
		SelectObject(bDC, icon[5]);
		for (i = 0; i < coinfo.stretch; i++) TransparentBlt2(mDC, 620 + 25 * i, 200, 25, 25, bDC, 0, 0, 25, 25, RGB(255, 255, 255));
		SelectObject(bDC,icon[9]);
		TransparentBlt2(mDC, 620 , 240, 100, 50, bDC, 0, 0, 100, 50, RGB(255, 255, 255));;
		SelectObject(bDC,icon[10]);
		BitBlt(mDC,740,254,100,30,bDC,0,0,SRCCOPY);
		int t1, t2;
		t1 = score;
		for (i = 0; i < 6; i++){
			t2 = t1 % 10;
			SelectObject(bDC, num[t2]);
			TransparentBlt2(mDC, 826 - 17 * i, 257, 15, 25, bDC, 0, 0, 15, 25, RGB(255, 255, 255));
			t1 = (t1 - t2) / 10;
		}
	}

	BitBlt(hDC,0,0,1000,600,mDC,0,0,SRCCOPY);

	if(face==7&&pause==0){
		//xm=ballx;
		if(bricknum<=0){
			if(stage!=10){
				if (ulinfo.pattern[pattern] == stage) ulinfo.pattern[pattern]++;
				if (ulinfo.pattern[2] == 0 && stage >= 3) ulinfo.pattern[2]++;
				face=11;
				if(pattern==1&&score>urinfo.adscore)urinfo.adscore=score;
				if(pattern==3&&score>urinfo.grscore)urinfo.grscore=score;
				if(pattern==4&&score>urinfo.liscore)urinfo.liscore=score;
				save_to_file();
				
			}
			else {
				face = 12;
			}
		}

		struct item*p1, *p2;
		p1 = itemhead;
		p2 = p1;
		while (p1->next != NULL){
			p1 = p1->next;
			(p1->y) += 5;
			if (p1->y >= 580){
				if ((batx - p1->x)*(batx - p1->x) <= lbat*lbat/4){
					if (p1->it == 1){
						coinfo.fire +=3;
						coinfo.ice = 0;
					}
					else if (p1->it == 2){
						coinfo.fire = 0;
						coinfo.ice += 5;
					}
					else if (p1->it == 3){
						ucinfo.money += 1;
					}
					else if (p1->it == 4){
						ucinfo.common += 1;
					}
					else if (p1->it == 5){
						ucinfo.ice += 1;
					}
					else if (p1->it == 6){
						ucinfo.fire += 1;
					}
					else if (p1->it == 7){
						ucinfo.gold += 1;
					}
					else if (p1->it == 8){
						ucinfo.rainbow += 1;
					}
					else if (p1->it == 9){
						if (coinfo.stretch == 0) lbat += 100;
						coinfo.stretch += 5;
					}
					else if (p1->it == 10){
						coinfo.life += 1;
					}
				}
				p2->next = p1->next;
				free((void*) p1);
				p1 = p2;
				itemhead->n--;
			}
			p2 = p1;
		}
		
		ballx4=ballx3;
		ballx3=ballx2;
		ballx2=ballx1;
		ballx1=ballx;
		bally4=bally3;
		bally3=bally2;
		bally2=bally1;
		bally1=bally;


		int batnew=max(lbat/2-MAXVX,min(600+MAXVX-lbat/2,xm));
		batv=batnew-batx;
		batx=batnew;

		if (ballx + ballvx >= 600){
			ballvx = -ballvx;
			ballx = 1200 - ballx;
		}
		else if (ballx + ballvx <= 0){
			ballvx = -ballvx;
			ballx = - ballx;
		}

		if (pattern == 3&&tNow%9==8){
			ballvy += 1;
		}

		if(bally+ballvy>=580){
			if(ballx+ballvx>=min(batx,batx-lbat/2)&&ballx+ballvx<=max(batx,batx+lbat/2)){
				ballvx=max(-MAXVX,min(MAXVX,ballvx+batv/2));
				if(ballvy>=3&&ballvy<=6&&pattern!=3){
					ballvy=min(6,max(3,3+rand()%4));
				}
				else if (pattern==3){
					ballvy = min(12, max(10, 10 + rand() % 3));
				}
				ballvy=-ballvy;
				bally = 1160 - bally;
				if (coinfo.fire > 0) coinfo.fire--;
				if (coinfo.ice > 0) coinfo.ice--;
				if (coinfo.stretch > 0){
					coinfo.stretch--;
					if (coinfo.stretch == 0) lbat -= 100;
				}
			}
			else {
				coinfo.fire = 0;
				coinfo.ice = 0;
				if (coinfo.stretch > 0) lbat -= 100;
				coinfo.stretch = 0;
				if(pattern!=2){
					coinfo.life--;
					score=max(0,score-50);
				}
				if(pattern!=2&&coinfo.life>0)
					setoff();
				if(pattern!=2&&coinfo.life==0){
					face=13;
					if(pattern==1&&score>urinfo.adscore)urinfo.adscore=score;
					if(pattern==4&&score>urinfo.liscore)urinfo.liscore=score;
					if(pattern==3&&score>urinfo.grscore)urinfo.grscore=score;
					save_to_file();
					score=0;
				}
				if (pattern == 2) setoff();
			
			}
		}
		else if (bally + ballvy <= 0){
			ballvy = -ballvy;
			bally = -bally;
		}

		int i=(bally+ballvy)/25+1,j=(ballx+ballvx)/50+1;
		int xn = ballx + ballvx, yn = bally + ballvy;
		area = makearea(ballx, bally, i, j);

		if(coinfo.fire>0){
			if (area == 1){
				if (ballvx*(25 * i - 25 - bally) <= ballvy*(50 * j - 50 - ballx)){
					if (map[i][j - 1] != 0){
						boom(i, j - 1);
					}
				}
				else{
					if (map[i - 1][j] != 0){
						boom(i - 1, j);
					}
				}
			}
			else if (area == 3){
				if (ballvx*(25 * i - 25 - bally) >= ballvy*(50 * j-1 - ballx)){
					if (map[i][j + 1] != 0){
						boom(i, j + 1);
					}
				}
				else{
					if (map[i - 1][j] != 0){
						boom(i - 1, j);
					}
				}
			}
			else if (area == 8){
				if (ballvx*(25 * i -1- bally) <= ballvy*(50 * j -1- ballx)){
					if (map[i][j + 1] != 0){
						boom(i, j + 1);
					}
				}
				else{
					if (map[i + 1][j] != 0){
						boom(i + 1, j);
					}
				}
			}
			else if (area == 6){
				if (ballvx*(25 * i-1 - bally) >= ballvy*(50 * j - 50 - ballx)){
					if (map[i][j - 1] != 0){
						boom(i, j - 1);
					}
				}
				else{
					if (map[i + 1][j] != 0){
						boom(i + 1, j);
					}
				}
			}
			else if (map[i][j] != 0) boom(i,j);
		}
		else if (area == 1){
			if (ballvx*(25 * i - 25 - bally) <= ballvy*(50 * j - 50 - ballx)){
				if (map[i][j - 1] != 0){
					ballvy = -ballvy;
					yn = 50 * i - 50 - yn;
					boom(i, j - 1);
					if (map[i - 1][j] != 0){
						ballvx = -ballvx;
						xn = 100 * j - 100 - xn;
						boom(i - 1, j);
					}
				}
				else if (map[i][j] != 0){
					ballvx = -ballvx;
					xn = 100 * j - 100 - xn;
					boom(i, j);
				}
			}
			else{
				if (map[i - 1][j] != 0){
					ballvx = -ballvx;
					xn = 100 * j - 100 - xn;
					boom(i - 1, j);
					if (map[i][j - 1] != 0){
						ballvy = -ballvy;
						yn = 50 * i - 50 - yn;
						boom(i, j - 1);
					}
				}
				else if (map[i][j] != 0){
					ballvy = -ballvy;
					yn = 50 * i - 50 - yn;
					boom(i, j);
				}
			}
		}
		else if (area == 3){
			if (ballvx*(25 * i - 25 - bally) >= ballvy*(50 * j-1 - ballx)){
				if (map[i][j + 1] != 0){
					ballvy = -ballvy;
					yn = 50 * i - 50 - yn;
					boom(i, j + 1);
					if (map[i - 1][j] != 0){
						ballvx = -ballvx;
						xn = 100 * j-1 - xn;
						boom(i - 1, j);
					}
				}
				else if (map[i][j] != 0){
					ballvx = -ballvx;
					xn = 100 * j -1- xn;
					boom(i, j);
				}
			}
			else{
				if (map[i - 1][j] != 0){
					ballvx = -ballvx;
					xn = 100 * j-1 - xn;
					boom(i - 1, j);
					if (map[i][j + 1] != 0){
						ballvy = -ballvy;
						yn = 50 * i - 50 - yn;
						boom(i, j + 1);
					}
				}
				else if (map[i][j] != 0){
					ballvy = -ballvy;
					yn = 50 * i - 50 - yn;
					boom(i, j);
				}
			}
		}
		else if (area == 8){
			if (ballvx*(25 * i -1- bally) <= ballvy*(50 * j -1- ballx)){
				if (map[i][j + 1] != 0){
					ballvy = -ballvy;
					yn = 50 * i -1- yn;
					boom(i, j + 1);
					if (map[i + 1][j] != 0){
						ballvx = -ballvx;
						xn = 100 * j-1 - xn;
						boom(i + 1, j);
					}
				}
				else if (map[i][j] != 0){
					ballvx = -ballvx;
					xn = 100 * j-1 - xn;
					boom(i, j);
				}
			}
			else{
				if (map[i + 1][j] != 0){
					ballvx = -ballvx;
					xn = 100 * j-1 - xn;
					boom(i + 1, j);
					if (map[i][j + 1] != 0){
						ballvy = -ballvy;
						yn = 50 * i-1 - yn;
						boom(i, j + 1);
					}
				}
				else if (map[i][j] != 0){
					ballvy = -ballvy;
					yn = 50 * i-1 - yn;
					boom(i, j);
				}
			}
		}
		else if (area == 6){
			if (ballvx*(25 * i-1 - bally) >= ballvy*(50 * j - 50 - ballx)){
				if (map[i][j - 1] != 0){
					ballvy = -ballvy;
					yn = 50 * i-1 - yn;
					boom(i, j - 1);
					if (map[i + 1][j] != 0){
						ballvx = -ballvx;
						xn = 100 * j - 100 - xn;
						boom(i + 1, j);
					}
				}
				else if (map[i][j] != 0){
					ballvx = -ballvx;
					xn = 100 * j - 100 - xn;
					boom(i, j);
				}
			}
			else{
				if (map[i + 1][j] != 0){
					ballvx = -ballvx;
					xn = 100 * j - 100 - xn;
					boom(i + 1, j);
					if (map[i][j - 1] != 0){
						ballvy = -ballvy;
						yn = 50 * i-1 - yn;
						boom(i, j - 1);
					}
				}
				else if (map[i][j] != 0){
					ballvy = -ballvy;
					yn = 50 * i-1 - yn;
					boom(i, j);
				}
			}
		}
		else if (map[i][j] != 0){
			if (area == 2){
				ballvy = -ballvy;
				yn = 50 * i - 50 - yn;
			}
			else if (area == 4){
				ballvx = -ballvx;
				xn = 100 * j - 100 - xn;
			}
			else if (area == 7){
				ballvy = -ballvy;
				yn = 50 * i-1 - yn;
			}
			else if (area == 5){
				ballvx = -ballvx;
				xn = 100 * j-1 - xn;
			}
			boom(i,j);
		}
		if (xn >= 600){
			ballvx = -ballvx;
			xn = 1200 - xn;
		}
		else if (xn <= 0){
			ballvx = -ballvx;
			xn = -xn;
		}

		/*if (yn >= 580){
			if (xn >= batx - lbat / 2 && xn <= batx + lbat / 2){
				ballvx = max(-20, min(20, ballvx + batv / 2));
				ballvy = -ballvy;
				yn = 1160 - yn;
			}
			else {
				xn = batx;
				yn = 580;
				ballvx = 5;
				ballvy = -5;
				tNow = 0;
			}
		}
		else if (yn <= 0){
			ballvy = -ballvy;
			yn = -yn;
		}*/

		ballx=xn;bally=yn;
	}
	tPre = GetTickCount();
}

void TransparentBlt2( HDC hdc0,	int nX0,int nY0,int nW0,int nH0,HDC hdc1,int nX1,int nY1,int nW1,int nH1,UINT Tcol)
{	
	HBITMAP hBMP   =CreateCompatibleBitmap(hdc0,nW0, nH0);
	HBITMAP mBMP   =CreateBitmap(nW0,nH0,1,1,NULL);	
	HDC		hDC    =CreateCompatibleDC(hdc0);
	HDC		mDC    =CreateCompatibleDC(hdc0);
	SelectObject(hDC, hBMP);
	SelectObject(mDC, mBMP);
	if (nW0==nW1&&nH0==nH1)
		BitBlt(hDC,0,0,nW0,nH0,hdc1,nX1,nY1,SRCCOPY);
	else
		StretchBlt(hDC,0,0,nW0,nH0,hdc1,nX1,nY1,nW1,nH1,SRCCOPY);

	SetBkColor(hDC, Tcol);
	BitBlt(mDC,0,0,nW0,nH0,hDC,0,0,SRCCOPY);
	SetBkColor(hDC, RGB(0,0,0));
	SetTextColor(hDC, RGB(255,255,255));
	BitBlt(hDC,0,0,nW0,nH0,mDC,0,0,SRCAND);
	SetBkColor(hdc0,RGB(255,255,255));
	SetTextColor(hdc0,RGB(0,0,0));

	BitBlt(hdc0,nX0,nY0,nW0,nH0,mDC,0,0,SRCAND);
	BitBlt(hdc0,nX0,nY0,nW0,nH0,hDC,0,0,SRCPAINT);

	DeleteDC(hDC);
	DeleteDC(mDC);
	DeleteObject(hBMP);
	DeleteObject(mBMP);
}