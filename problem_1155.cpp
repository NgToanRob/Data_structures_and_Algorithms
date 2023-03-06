#include <iostream>
#include<math.h>
#include <vector>

using namespace std;

vector<char> result;

struct Vercites{
    char ch;
    int w;
};

void record(Vercites &x, Vercites &y, char sign){
    result.push_back(x.ch);
    result.push_back(y.ch);
    result.push_back(sign);
    result.push_back('\n');
}


void substraction_V(Vercites &x, Vercites &y){
    // Subtract until either is zero
    while(x.w && y.w){
        record(x,y,'-');
        x.w -= 1;
        y.w -= 1;
    }
}

// Transfer weight through a third vertex
void move_W(Vercites &a, Vercites &b, Vercites &c){
    while(c.w > 0){
        record(b,a,'+');
        record(c,b,'-');
        a.w = a.w + 1;
        c.w = c.w - 1;
    }
}

bool isAdjacent(int a, int b){
    if(a > b) swap(a, b);
    if (b - a == 4) return true;
    if (a < 4 && b >= 4) return false;
    if (b - a == 3) return true;
    if(a + 1 == b) return true;
    return false;
}

int main(){
    Vercites a = {'A'}, b = {'B'}, c = {'C'}, d = {'D'}, e = {'E'}, f = {'F'}, g = {'G'}, h = {'H'};
    // Enter the troubleduons of the Vercites
    cin>>a.w>>b.w>>c.w>>d.w>>e.w>>f.w>>g.w>>h.w;

    /*
    Tow sets of bipartite graph:
     - set 1: A C F H
     - set 2: B D E G
    */

    if(a.w + f.w + c.w + h.w != b.w + d.w + e.w + g.w ){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<Vercites> cube = {a,b,c,d,e,f,g,h};
   
    //Find the adjacent edges and subtract their weights if the condition is satisfied
    for(int i = 0; i < 8; i++){
        for(int j = 0;j < 8; j++){
            if(isAdjacent(i,j)){
                substraction_V(cube[i],cube[j]);
            }
        }
    }

    // C F H -> A
    // F - B - A
    if(cube[5].w > 0) move_W(cube[0],cube[1],cube[5]); 
    // H - E - A
    if(cube[7].w) move_W(cube[0],cube[4],cube[7]);
    // C - B - A
    if(cube[2].w) move_W(cube[0],cube[1],cube[2]);

    // D E G -> B
    // D - C - B
    if(cube[3].w) move_W(cube[1],cube[2],cube[3]);
    // E - A - B
    if(cube[4].w) move_W(cube[1],cube[0],cube[4]); 
    // G - C - B
    if(cube[6].w) move_W(cube[1],cube[2],cube[6]);

    //After putting the weight on the top of A, B, we just need to subtract their weight
    substraction_V(cube[0],cube[1]);

    for(char c: result) cout << c;

}