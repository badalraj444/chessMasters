#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

class pieces
{
protected:
    int color; //0 or 1
    int x, y; // pos
    bool alive;
    
public:
virtual ~pieces() = default;
virtual bool validMove(int x1, int y1) = 0;
void moveTo(int X, int Y)
    {
        if  (X < 1 || X > 8 || Y < 1 || Y > 8)
        {
            // throw error
            cout<<"error\n";
            return;
        }
        if(!validMove(X,Y)){
            //throw error
            cout<<"error\n";
            return;
        }
        x = X;
        y = Y;
    }
    pieces(int C, int X, int Y){
        color = C;
        x = X;
        y = Y;
        alive = true;
    }
    void capture(){
        alive = false;
        //free position
    }
    int getColor() const{
        return color;
    }    
    pair<int,int> getPosition() const{
        return make_pair(x,y);
    }
    void getInfo() const{
        cout<<"color: "<<color<<endl<<"position: "<<x<<" "<<y<<endl;
    }
};

class king: public pieces{
public:
    king(int C, int X, int Y) : pieces(C, X, Y) {
    }
    bool validMove(int x1, int y1){
        if(abs(x1-x)>1 || abs(y1-y)>1) return false;
        return true;
    }

};

int main(){
    king k1(1,2,2);
    k1.moveTo(4,2);
    k1.getInfo();
    return 0;
}
