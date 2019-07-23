#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<conio.h>
#include<fstream>
using namespace std;
struct snake
{
    int x;
    int y;
    char value;
};
/*bool test(char arr[][15],vector<struct snake> & snk_body,char t,int fx,int fy)
{
     int dir=0;
    bool flg=0;
    bool l=0;
    if(t=='w')
    {
        dir=0;
    }
    if(t=='a')
    {
        dir=1;
    }
    if(t=='s')
    {
        dir=2;
    }
    if(t=='d')
    {
        dir=3;
    }
    int ax=0,ay=0;
    if(dir==0)
    {
        ax=snk_body[0].x-1;
        ay=snk_body[0].y;
        if(ax==fx&&ay==fy)
        {
        flg=1;
            struct snake a;
            a.x=-1;
            a.y=-1;
            a.value='<';
            snk_body[snk_body.size()-1].value='~';
            snk_body.push_back(a);
        }
        else
        {
            for(int x=0;x<snk_body.size();x++)
            {
                if(snk_body[x].x==ax&&snk_body[x].y==ay)
                {
                    l=1;
                    break;
                }
            }

        }
    }
    else if(dir==1)
    {
         ax=snk_body[0].x;
        ay=snk_body[0].y-1;
        if(ay==fy&&ax==fx)
        {
            flg=1;
            struct snake a;
            a.x=-1;
            a.y=-1;
            a.value='<';
            snk_body[snk_body.size()-1].value='~';
            snk_body.push_back(a);
        }
        else
        {
            for(int x=0;x<snk_body.size();x++)
            {
                if(snk_body[x].x==ax&&snk_body[x].y==ay)
                {
                    l=1;
                    break;
                }
            }
        }
    }
    else if(dir==2)
    {
         ax=snk_body[0].x+1;
        ay=snk_body[0].y;
        if(ax==fx&&ay==fy)
        {
            flg=1;
            struct snake a;
            a.x=-1;
            a.y=-1;
            a.value='<';
            snk_body[snk_body.size()-1].value='~';
            snk_body.push_back(a);
        }
        else
        {
            for(int x=0;x<snk_body.size();x++)
            {
                if(snk_body[x].x==ax&&snk_body[x].y==ay)
                {
                    l=1;
                    break;
                }
            }
        }
    }
    else
    {
         ax=snk_body[0].x;
        ay=snk_body[0].y+1;
        if(ay==fy&&ax==fx)
        {
            flg=1;
            struct snake a;
            a.x=-1;
            a.y=-1;
            a.value='<';
            snk_body[snk_body.size()-1].value='~';
            snk_body.push_back(a);
        }
        else
        {
            for(int x=0;x<snk_body.size();x++)
            {
                if(snk_body[x].x==ax&&snk_body[x].y==ay)
                {
                    l=1;
                    break;
                }
            }
        }
    }
    if(l==1)
    {
        return 1;
    }
}*/
int main()
{
int darr[15][15];
        bool hj=0;
    cout<<"Do you want to load from old file(1/0)"<<endl;
    cin>>hj;
    system("cls");
    char arr[15][15];
    for(int x=0;x<15;x++)
    {
        for(int y=0;y<15;y++)
        {
            arr[x][y]=' ';
        }
    }
    struct snake H,T,B;
    H.x=0;
    H.y=2;
    H.value='<';
    B.x=0;
    B.y=1;
    B.value='~';
    T.x=0;
    T.y=0;
    T.value='>';
    vector<struct snake> snk_body;
    snk_body.push_back(H);
    snk_body.push_back(B);
    snk_body.push_back(T);
    int fx=10;
    int fy=10;
    char fvalue=149;
      char t='w';
      ifstream fin("snksave.txt",ios::in);
      if(hj==1&&fin.eof()==0)
      {
          char ghj;
        snk_body.clear();

        for(int x=0;x<15;x++)
        {
            for(int y=0;y<15;y++)
            {
                fin>>ghj;
                if(ghj=='z')
                {
                    arr[x][y]=' ';
                }
                else if(ghj=='.')
                {
                    fx=x;
                    fy=y;
                    arr[x][y]='.';
                }
                else
                {
                    arr[x][y]=ghj;
                }
            }
        }

        while(fin.eof()==0)
        {
            struct snake d;
            fin>>d.x>>ghj>>d.y>>ghj>>d.value;
            d.value='~';
            snk_body.push_back(d);
        }
        snk_body[0].value='<';
        snk_body[snk_body.size()-1].value='>';
      }
      fin.close();
      for(int x=0;x<15;x++)
      {
          for(int y=0;y<15;y++)
          {
              cout<<arr[x][y]<<" ";
          }
          cout<<endl;
      }
      char prev='w';
while(true)
{

    int dir=0;
    bool flg=0;
    bool l=0;
int cv=30000000;
while(cv--);
if(kbhit())
{
    t=getch();
}
    if(t=='w')
    {
        dir=0;
    }
    if(t=='a')
    {
        dir=1;
    }
    if(t=='s')
    {
        dir=2;
    }
    if(t=='d')
    {
        dir=3;
    }
    if(t=='p')
    {
        char ghj=0;
        ofstream fout("snksave.txt");
        for(int x=0;x<15;x++)
        {
            for(int y=0;y<15;y++)
            {
                if(arr[x][y]==' ')
                {
                fout<<'z';
                }
                else
                {
                    fout<<arr[x][y];
                }

            }
        }
        for(int x=0;x<snk_body.size();x++)
        {
            fout<<snk_body[x].x<<"-"<<snk_body[x].y<<"-"<<snk_body[x].value;
        }
        fout.close();
        exit(0);
    }
    int ax=0,ay=0;
    if(dir==0)
    {
        ax=snk_body[0].x-1;
        ay=snk_body[0].y;
        if(ax==fx&&ay==fy)
        {
        flg=1;
            struct snake a;
            a.x=-1;
            a.y=-1;
            a.value='<';
            snk_body[snk_body.size()-1].value='~';
            snk_body.push_back(a);
        }
        else
        {
            for(int x=0;x<snk_body.size()-1;x++)
            {
                if(snk_body[x].x==ax&&snk_body[x].y==ay)
                {
                    l=1;
                    break;
                }
            }
        }
    }
    else if(dir==1)
    {
         ax=snk_body[0].x;
        ay=snk_body[0].y-1;
        if(ay==fy&&ax==fx)
        {
            flg=1;
            struct snake a;
            a.x=-1;
            a.y=-1;
            a.value='<';
            snk_body[snk_body.size()-1].value='~';
            snk_body.push_back(a);
        }
        else
        {
            for(int x=0;x<snk_body.size()-1;x++)
            {
                if(snk_body[x].x==ax&&snk_body[x].y==ay)
                {
                    l=1;
                    break;
                }
            }
        }
    }
    else if(dir==2)
    {
         ax=snk_body[0].x+1;
        ay=snk_body[0].y;
        if(ax==fx&&ay==fy)
        {
            flg=1;
            struct snake a;
            a.x=-1;
            a.y=-1;
            a.value='<';
            snk_body[snk_body.size()-1].value='~';
            snk_body.push_back(a);
        }
        else
        {
            for(int x=0;x<snk_body.size()-1;x++)
            {
                if(snk_body[x].x==ax&&snk_body[x].y==ay)
                {
                    l=1;
                    break;
                }
            }
        }
    }
    else
    {
         ax=snk_body[0].x;
        ay=snk_body[0].y+1;
        if(ay==fy&&ax==fx)
        {
            flg=1;
            struct snake a;
            a.x=-1;
            a.y=-1;
            a.value='<';
            snk_body[snk_body.size()-1].value='~';
            snk_body.push_back(a);
        }
        else
        {
            for(int x=0;x<snk_body.size()-1;x++)
            {
                if(snk_body[x].x==ax&&snk_body[x].y==ay)
                {
                    l=1;
                    break;
                }
            }
        }
    }
    if(l==1)
    {
        /*if(test(arr,snk_body,'w',fx,fy)&&test(arr,snk_body,'a',fx,fy)&&test(arr,snk_body,'s',fx,fy)&&test(arr,snk_body,'d',fx,fy))
        {
            cout<<"you lost"<<endl;
            break;
        }*/
        if(t!=prev)
        {
            t=prev;
            continue;
        }
        cout<<"you lost"<<endl;
        break;
    }
    for(int x=snk_body.size()-1;x>0;x--)
    {
        snk_body[x].x=snk_body[x-1].x;
        snk_body[x].y=snk_body[x-1].y;
    }
    if(dir==0)
    {
        snk_body[0].x-=1;
    }
    else if(dir==1)
    {
        snk_body[0].y-=1;
    }
    else if(dir==2)
    {
        snk_body[0].x+=1;
    }
    else
    {
        snk_body[0].y+=1;
    }
    if(snk_body[0].x<0)
    {
        snk_body[0].x+=15;
    }
    else if(snk_body[0].y<0)
    {
        snk_body[0].y+=15;
    }
    else if(snk_body[0].x>14)
    {
        snk_body[0].x-=15;
    }
    else if(snk_body[0].y>14)
    {
        snk_body[0].y-=15;
    }
    for(int x=0;x<15;x++)
    {
        for(int y=0;y<15;y++)
        {
            arr[x][y]=' ';
        }
    }
    if(flg!=1)
    {
    arr[fx][fy]=fvalue;
    }
    else
    {
      srand(time(NULL));
     /* for(int x=0;x<15;x++)
      {
          for(int y=0;y<15;y++)
          {
              if(arr[x][y]!=' ')
              {
                  darr[x][y]=-203929383;
              }
              else
              {
                  darr[x][y]=0;
              }
          }
      }
      for(int x=1;x<14;x++)
      {
          for(int y=)
      }*/
      do{
      fx=rand()%15;
      fy=rand()%15;
    }while(arr[fx][fy]!=' ');

    }
    for(int x=0;x<snk_body.size();x++)
    {
        arr[snk_body[x].x][snk_body[x].y]=snk_body[x].value;
    }
    system("cls");
    for(int x=0;x<15;x++)
    {
        for(int y=0;y<15;y++)
        {
            cout<<arr[x][y]<<" ";
        }
        cout<<endl;
    }
    prev=t;
}
    return 0;
}
