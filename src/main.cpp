#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <ctime> 

#define LIVE_CELL 0xB2
#define DEAD_CELL 0x20

#define N 30
#define M 10
#define NUM 100

class cell
 {
  public:
   cell(void); 
   unsigned char get_state(void) { return old_state; }
   void report_to_cell(int n) { change_state(n); }
   void refresh(void) { old_state = new_state; }
  private:
   unsigned char new_state;
   unsigned char old_state;
   void change_state(int n)
    {
      if(old_state == LIVE_CELL)
       {
        if(n<2) new_state = DEAD_CELL; 
        if(n>3) new_state = DEAD_CELL;
       }
      if(old_state == DEAD_CELL)
       {
        if(n==3) new_state = LIVE_CELL;
       }  
    }                  
 };

int get_neighbor_num(int, int);

cell colony[M][N];

int main(int argc, char *argv[])
{
    /*for(int i=0; i<M; i++)
      for(int j=0; j<N; j++)
       { colony[i][j].set_state(DEAD_CELL); colony[i][j].refresh(); }     
    
    int k=0;
    srand(time(NULL));
    while(k<NUM)
     {
       int x = rand()%N;
       int y = rand()%M;
       if(colony[y][x].get_state() == DEAD_CELL)
        {
         colony[y][x].set_state(LIVE_CELL);
         colony[y][x].refresh();
         k++;
        }    
     }*/
    
     system("cls"); 
     srand(time(NULL)); 
       for(int i=0; i<M; i++)
        {
         for(int j=0; j<N; j++)
          { 
           printf(" %c", colony[i][j].get_state());
          }
         printf("\n\n"); 
        }
       system("PAUSE");
        
    char ch;    
    while(ch!='q')
     {
       ch = getch();
       //usleep(200000);     
       system("cls");
       for(int i=0; i<M; i++)
        {
         for(int j=0; j<N; j++)
          { 
           colony[i][j].refresh();
           printf(" %c", colony[i][j].get_state());
          }
         printf("\n\n"); 
        }
        
       for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
         { 
          colony[i][j].report_to_cell(get_neighbor_num(j, i));
         }
       //system("PAUSE");  
     }
    return EXIT_SUCCESS;
}

int get_neighbor_num(int x, int y)
 {
  int num=0;
  if(x>=0 && x<N && y>=0 && y<M)
   {
     if(colony[y-1][x-1].get_state() == LIVE_CELL) num++;
     if(colony[y-1][x].get_state() == LIVE_CELL) num++;     
     if(colony[y-1][x+1].get_state() == LIVE_CELL) num++;     
     if(colony[y][x+1].get_state() == LIVE_CELL) num++;     
     if(colony[y+1][x+1].get_state() == LIVE_CELL) num++;     
     if(colony[y+1][x].get_state() == LIVE_CELL) num++;     
     if(colony[y+1][x-1].get_state() == LIVE_CELL) num++;     
     if(colony[y][x-1].get_state() == LIVE_CELL) num++;     
     return num;
   } else return -1;
 }

cell::cell(void)
 {
   //srand(time(NULL));
   if((rand()%10)>5) new_state = LIVE_CELL;
    else new_state = DEAD_CELL;
   refresh(); 
 }      
