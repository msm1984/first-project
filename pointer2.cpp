#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <synchapi.h>
using namespace std;
int d;
void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
class entity{
public:
    char x;
    char y;
public:
    virtual void Move(){
        return;
    }
    virtual void draw(){
        return;
    }

};
class Man: public entity{
public:
    Man(){
        x = 5;
        y = 10;
    }
    void Move(){
        while (1){
            if (kbhit()){
                switch(getch()){
                case 'a':
                    if(x>0){
                    x--;
                    break;
                    }

                case 'd':
                    if(x<10){
                    x++;
                    break;
                    }

                }
            }

        return;
        }
    }
    void draw(){
        gotoxy(x,y);
        cout << '@';
    }
};
class item:public entity{
public:
     void item1(){
        srand(time(0));
        x = rand()%10;
        y = 0;
    }
    void Move(){
        if(y != 9){
            y++;
        }
    }
    void check1(item & d){
        if(y == 9){
            d.item1();
            return;
        }
    }
    void draw(){
        gotoxy(x,y);
        cout << '#';
    }
};
class Manage{
 public:
  void point(Man m, item i){
    if(i.y == 9 && m.x == i.x){
        d++;
    }
  }
  bool gameover(Man m, item i){
    if(i.y == 9 && m.x != i.x){
        return false;
    }
    else{
        return true;
    }
  }
};

int main()
{
    entity *e;
    entity *a;
    item i;
    Man m;
    e = &i;
    a = &m;
    i.item1();
    Manage s;
    while(1){
        a->Move();
        e->Move();
        system("cls");
        e->draw();
        a->draw();
        //i.draw();
        s.point(m, i);
        if(s.gameover(m, i) == false){
            system("cls");
            cout << "game over" << endl;
            cout << "your score is: " << d << endl;
            break;
        }
        i.check1(i);
        Sleep(500);
    }
    return 0;
}
