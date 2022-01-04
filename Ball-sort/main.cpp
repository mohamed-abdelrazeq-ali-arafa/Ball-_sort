#include<bits/stdc++.h>
using namespace std;
#define size 4
const int SIZE=5;
char grid [SIZE][SIZE];

class Stack
{

    char arr[size];
    int top = -1;

public:
    bool is_full()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
            return false;

    }

    bool is_empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;


    }
    void push(char value)
    {

        if (is_full())
        {


            return;

        }
        else
            top++;
        arr[top] = value;
    }
    char pop()
    {

        if (is_empty())
        {
            return 'F';
        }
        else
            return arr[top--];

    }


    char return_top()
    {
        if (is_empty())
        {
            return 'F';
        }
        else
        {
            return arr[top];
        }
    }
    void print()
    {
        for (int i = top; i >=0; --i)
        {
            cout <<"||"<<arr[i]<<"||"<<endl;
        }
    }
    void insert_random(Stack arr[])
    {
        char balls[]= {'r','g','b','r','g','b','r','g','b','r','g','b'};
        //initialize the random seed
        srand(time(NULL));
        random_shuffle(balls,balls+12);
        int s=0;

        for (int x = 0; x < 3; x++)
        {

            for (int i = 0; i < 4; i++)
            {

                arr[x].push(balls[s]);
                s++;
            }


        }
    }

    bool check_valid(int i, int j)
{
    if (i >= 0 && i < 5 && j >= 0 && j < 5 && i!=j)
    {
        return true;
    }
    else {
        return false;
    }
}
    bool move_balls(Stack arr[],int x,int y)
    {
        char temp1=arr[x].return_top(); // first element that will move
        char temp2=arr[y].return_top(); // first element in stack that will store in it

        if(temp1==temp2 || temp2=='F' ) // check if same color or second stack empty then store
        {
            if(arr[y].is_empty()||!arr[y].is_full()) // check stack empty or not full
            {

                arr[x].pop();
                arr[y].push(temp1);
                return true;
            }
        }
        else
           return false;

    }
    bool check_win(Stack arr[])
    {
        int win=0;
        for (int i = 0; i < 5; i++)
        {
            if(arr[i].is_full())
            {
                win++;
            }
        }
        if(win==3)
        {
            return true;
        }
        return false;

    }


    void print_grid(Stack arr[])
    {
        for (int i = 0; i < 5; i++)
        {

            cout<<"TUBE "<<i<<endl;;
            arr[i].print();
            cout<<endl;


        }
    }
    void clear_grid(Stack arr[]){
        for(int i =0; i < 5;i++){
            for (int j = top; j >=0; --j)
            {
                arr[i].pop();
            }
        }
    }
};
void play_game(Stack arr[],Stack s)
{
    cout<<"------------------------Welcome to Ball Sort game----------------------"<<endl;
    s.insert_random(arr);
    int from, to;
    s.print_grid(arr);
    while(true)
    {
        cout<<"Enter Tube that will take ball from  : ";
        cin>>from;
        cout<<"enter Tube that will insert ball in  : ";
        cin>>to;
        while(!s.check_valid(from,to)||arr[to].is_full()||arr[from].is_empty())
        {
            cout<<"Please Enter valid index"<<endl;
            cout<<"Enter Tube that will take ball from  : ";
            cin>>from;
            cout<<"Enter Tube that will insert ball in : ";
            cin>>to;
        }
        while(!s.move_balls(arr,from,to))
        {
            cout<<"Please Enter valid index"<<endl;
            cout<<"Enter Tube that will take ball from  : ";
            cin>>from;
            cout<<"enter Tube that will insert ball in  : ";
            cin>>to;
        }
        s.print_grid(arr);
        if(s.check_win(arr))
        {
            cout<<"CONGRATULATIONS YOU WON"<<endl;
            break;
        }
    }
}

int main()
{
    Stack s;
    Stack arr1[4];

    while(true){
    s.clear_grid(arr1);
    play_game(arr1,s);
    char c;
    cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
    cout<<"Thanks for playing game";

    return 0;
}
