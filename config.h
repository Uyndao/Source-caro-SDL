// thêm win_path[5] và int winner

#ifndef CONFIG
#define CONFIG

struct Point{
    int x, y;
    Point(){
        x = 0;
        y = 0;
    }

    Point(int x_, int y_){
        x = x_;
        y = y_;
    }

    void operator=(Point p){
        x = p.x;
        y = p.y;
    }
};
//
int winner=0;
Point win_path[5];
bool started = false;
bool end = false;
//
const int WIDTH = 50;
const int HEIGHT = 30;
const int PAUSE_TIME = 500; // milisecond

#endif // CONFIG
