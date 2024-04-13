#include <iostream>
#include <utility>
#include <cassert>

class piece{
public:
	int position[6];
	int liberation;
    piece();
	int calculateliberation(piece counterpart);
};

piece::piece(){
    for (int i=0; i<6; i++) {
        std::cin>>this->position[i];
        assert(position[i]>=0 && position[i]<=18);
    }
};
int piece::calculateliberation(piece counterpart){
#define selfside this->position
#define counterside counterpart.position
    int plate[19][19]={0};
    for(int i=0; i<6;i+=2){
        plate[selfside[i]][selfside[i+1]]=1;
        plate[counterside[i]][counterside[i+1]]=1;
    }
    int liberation = 0;

    for(int i=0; i<6; i+=2){
        std::pair<int, int> site(selfside[i],selfside[i+1]);
        if(site==std::pair<int,int>(0,0)){
            liberation+=2-plate[0][1]-plate[1][0];  continue;
        }
        else if(site==std::pair<int,int>(0,18)){
            liberation+=2-plate[0][17]-plate[1][18];  continue;
        }
        else if(site==std::pair<int,int>(18,18)){
            liberation+=2-plate[18][17]-plate[17][18]; continue;
        }
        else if(site==std::pair<int,int>(18,0)){
            liberation+=2-plate[17][0]-plate[18][1]; continue;
        }
        else if(selfside[i]==0){
            liberation+=3-plate[site.first][site.second-1]-plate[site.first][site.second+1]
                       -plate[site.first+1][site.second]; continue;
        }else if(selfside[i]==18){     
            liberation+=3-plate[site.first][site.second-1]-plate[site.first][site.second+1]
                       -plate[site.first-1][site.second]; continue;
        }else if(selfside[i+1]==0){
            liberation+=3-plate[site.first][site.second-1]-plate[site.first-1][site.second]
                       -plate[site.first+1][site.second]; continue;
        }else if(selfside[i+1]==18){
            liberation+=3-plate[site.first][site.second-1]-plate[site.first-1][site.second]
                       -plate[site.first+1][site.second]; continue;
        }else {
            liberation+=3-plate[site.first][site.second-1]-plate[site.first-1][site.second]
                       -plate[site.first+1][site.second]; continue;
        }
    }
    
    return liberation;
}


int main(void){
	piece black,white;
    std::cout<<"%d %d"<<black.calculateliberation(white)<<white.calculateliberation(black)<<std::endl;

}
