using namespace std;

#include <time.h>
#include<stdlib.h>

#define X_SIZE_OF_LED 8
#define Y_SIZE_OF_LED 8
#define X_CENTER 4
#define Y_CENTER 4


//for pitch
int array[X_SIZE_OF_LED][Y_SIZE_OF_LED];

int newGame = 1;

class Rectangle{
    protected:
        int x, y;
    public:
        Rectangle(int i, int j){
            x = i;
            y = j;
        }

        int getX(){
            return x;
        }

        int getY(){
            return y;
        }
        
};

class Controller : public Rectangle{
    private:
       int left0Right1;
    public:
        void controllerInit(){
            if(left0Right1 == 0){
                y = Y_CENTER - 1;
                x = 0;
            }
            else{
                y = Y_CENTER - 1;
                x = X_SIZE_OF_LED - 1;
            }
            updateArray();
        }

        Controller(int i) : Rectangle(X_CENTER, Y_CENTER){
            // 0 for left controller, 1 for right controller
            left0Right1 = i;
            controllerInit();
        }

        void updateArray(){
            array[x][y] = 1;
            array[x][y+1] = 1;
            array[x][y+2] = 1;
        }

        bool go_up(){
            if(y > 0){
                array[x][y + 2] = 0;
                y -= 1;
                array[x][y] = 1;
                return true;
            }
            return false;
        }
        bool go_down(){
            if(y + 3 < Y_SIZE_OF_LED){
                array[x][y] = 0;
                array[x][y + 3] = 1;
                y += 1;
                return true;
            }
            return false;
        }

};

Controller left(0);
Controller right(1);

class Ball : public Rectangle{
    private :
        int moving_direction;//0 means stable, 1 means right up, 2 means right down, 3 means left down, 4 means left up

        bool go_up(){
            if(y > 0){
                array[x][y] = 0;
                right.updateArray();
                left.updateArray();
                y -= 1;
                array[x][y] = 1;
                return true;
            }
            return false;
        }
        bool go_down(){
            if(y + 1 < Y_SIZE_OF_LED){
                array[x][y] = 0;
                right.updateArray();
                left.updateArray();
                y += 1;
                array[x][y] = 1;
                return true;
            }
            return false;
        }
        bool go_left(){
            if(x > 0){
                array[x][y] = 0;
                left.updateArray();
                x -= 1;
                array[x][y] = 1;
                return true;
            }
            return false;
        }
        bool go_right(){
            if(x + 1 < X_SIZE_OF_LED){
                array[x][y] = 0;
                right.updateArray();
                x += 1;
                array[x][y] = 1;
                return true;
            }
            return false;
        }
        bool move1(){
            if(x == (X_SIZE_OF_LED - 2) && y >= (right.getY()) && y <= (right.getY() + 3)){
                 moving_direction = 4;
                 move4();
            }
            else{
                if(!go_right()){
                    ballInit();
                    return true;
                }
                if(!go_up()){
                    moving_direction = 2;
                    go_down();
                }
            }
            return false;
        }
        
        bool move2(){
            if(x == (X_SIZE_OF_LED - 2) && y >= (right.getY() - 1) && y<= (right.getY() + 2)){
                moving_direction = 3;
                move3();
            }
            else{
                if(!go_right()){
                    ballInit();
                    return true;
                }
                if(!go_down()){
                    moving_direction = 1;
                    go_up();
                }
            }
            return false;
        }
        bool move3(){
            if(x == 1 && y >= (left.getY() - 1) && y <= (left.getY() + 2)){
                moving_direction = 2;
                move2();
            }
            else{
                if(!go_left()){
                    ballInit();
                    return true;
                }
                if(!go_down()){
                    moving_direction = 4;
                    go_up();
                }
            }
            return false;
        }
        bool move4(){
            if(x == 1 && y >= (left.getY()) && y<= (left.getY() + 3)){
                moving_direction = 1;
                move1();
            }
            else{
                if(!go_left()){
                    ballInit();
                    return true;
                }
                if(!go_up()){
                    moving_direction = 3;
                    go_down();
                }
            }   
            return false;
        }


    public :
        Ball() : Rectangle(X_CENTER, Y_CENTER){
            srand(time(NULL));
            ballInit();
        }
        void ballInit(){
            array[x][y] = 0;
            x = X_CENTER;
            y = Y_CENTER;
            array[x][y] = 1;
            moving_direction = rand() % 4 + 1;
            newGame = 1;
        }
        bool move(){
            switch(moving_direction){
                case 1:
                    return move1();
                case 2:
                    return move2();
                case 3:
                    return move3();
                case 4:
                    return move4();
                default:
                    return false;
            }
        }
        void make3(){
            array[2][2] = 1;
            array[3][2] = 1;
            array[3][3] = 1;
            array[3][4] = 1;
            array[3][5] = 1;
            array[3][6] = 1;
            array[2][4] = 1;
            array[2][6] = 1;
        }
        void remove3(){
            array[2][2] = 0;
            array[3][2] = 0;
            array[3][3] = 0;
            array[3][4] = 0;
            array[3][5] = 0;
            array[3][6] = 0;
            array[2][4] = 0;
            array[2][6] = 0;
        }
        void make2(){
            array[2][2] = 1;
            array[3][2] = 1;
            array[3][3] = 1;
            array[3][4] = 1;
            array[3][6] = 1;
            array[2][4] = 1;
            array[2][5] = 1;
            array[2][6] = 1;
        }
        void remove2(){
            array[2][2] = 0;
            array[3][2] = 0;
            array[3][3] = 0;
            array[3][4] = 0;
            array[3][6] = 0;
            array[2][4] = 0;
            array[2][5] = 0;
            array[2][6] = 0;
        }
        void make1(){
            array[2][2] = 1;
            array[2][3] = 1;
            array[2][4] = 1;
            array[2][5] = 1;
            array[2][6] = 1;
        }
        void remove1(){
            array[2][2] = 0;
            array[2][3] = 0;
            array[2][4] = 0;
            array[2][5] = 0;
            array[2][6] = 0;
        }

};


