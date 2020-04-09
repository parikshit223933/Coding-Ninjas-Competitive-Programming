#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
using namespace std;
int **make_move(int **board, int x, int y, int player, int ischeck)
{
    //ek case wo hoga jab hum board mei keval check kar rahe hein ki hum e move karna hai ya nahi
    //doosra case wo ho sakta hai ki hum board mei actually move kar rahe hein
    int **new_board;

    if (ischeck) //new_board points towards the board, if you make any changes, they will be reflwcted in the original board
    {
        new_board = board;
    }
    else //here, we are copying all the values of the vboard in our new_board. original board wont be affected upon changing the new_board
    {
        new_board = new int *[4];
        for (int i = 0; i < 4; i++)
        {
            new_board[i] = new int[4];
            for (int j = 0; j < 4; j++)
            {
                new_board[i][j] = board[i][j];
            }
        }
    }
    int xdir[] = {-1, -1, 0, 1, 1, 1, 0, -1}; //for traversing in
    int ydir[] = {0, 1, 1, 1, 0, -1, -1, -1}; //all directions
    if (x < 0 || x >= 4 || y < 0 || y >= 4 || board[x][y] != 0)
    {
        return NULL;
    }
    bool move_possible = false;
    for (int i = 0; i < 8; i++)
    {
        int x_step = xdir[i];
        int y_step = ydir[i];
        int current_x = x + x_step;
        int current_y = y + y_step;
        int count = 0;
        while (current_x >= 0 && current_x < 4 && current_y >= 0 && current_y < 4)
        {
            if (new_board[current_x][current_y] == 0)
            {
                break;
            }
            else if (new_board[current_x][current_y] != player)
            {
                current_x += x_step;
                current_y += y_step;
                count++;
            }
            else
            {
                if(count>0)
                {
                    move_possible=true;
                    if(ischeck)
                    {
                        return new_board;
                    }
                    int convert_x=current_x-x_step;
                    int convert_y=current_y-y_step;
                    while(convert_x!=x||convert_y!=y)
                    {
                        new_board[convert_x][convert_y]=player;
                        convert_x=convert_x-x_step;
                        convert_y=convert_y-y_step;
                    }
                    new_board[x][y]=player;
                }
                break;
            }
        }
    }
    if(move_possible)
    {
        return new_board;
    }
    else
    {
        return NULL;
    }
    
}
vector<pair<int, int> *> *possible_moves(int **board, int player)
{
    vector<pair<int, int> *> *output = new vector<pair<int, int> *>();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                if (make_move(board, i, j, player, true))
                {
                    pair<int, int> *p = new pair<int, int>(i, j);
                    output->push_back(p);
                }
            }
        }
    }
    return output;
}
int evaluate_board(int **board, bool &completed)
{
    if (possible_moves(board, 1)->size() != 0 || possible_moves(board, 2)->size() != 0)
    {
        completed = false;
        return 0;
    }
    completed = true;
    int count[3];
    for (int i = 0; i < 4; i++) //counting number of ones and twos in the evaluation function
    {
        for (int j = 0; j < 4; j++)
        {
            count[board[i][j]]++;
        }
    }
    return count[1] - count[2];
}
int main()
{
    int **board=new int* [4];
    for(int i=0; i<4; i++)
    {
        board[i]=new int [4];
        for(int j=0; j<4; j++)
        {
            board[i][j]=0;
        }
    }
    board[1][1]=2;
    board[1][2]=1;
    board[2][1]=1;
    board[2][2]=2;
    bool check=false;
    cout<<evaluate_board(board, check)<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}