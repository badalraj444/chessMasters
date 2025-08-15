#include <iostream>

using namespace std;

class pieces
{
protected:
    string color;
    int x, y; // pos
    bool alive;

public:
void moveTo(int x_, int y_)
    {
        if (x_ < 1 || x_ > 8 || y_ < 1 || y_ > 8)
        {
            // throw error
            cout<<"invalid position!";
        }
        x = x_;
        y = y_;
    }
    pieces(string color_, int x_, int y_){
        color = color_;
        moveTo(x_ , y_);
        alive = true;
    }
    void capture(){
        alive = false;
        //free position
    }
void getinfo(){
    cout<<"color: "<<color<<endl;
    cout<<"position: "<<x<<" , "<<y<<endl;
    cout<<"alive: "<<alive<<endl;
}    
};

int main(){
    pieces p1("white",2,3);
    p1.getinfo();
    p1.capture();
    p1.getinfo();
    p1.moveTo(5,4);
    p1.getinfo();
    return 0;
}