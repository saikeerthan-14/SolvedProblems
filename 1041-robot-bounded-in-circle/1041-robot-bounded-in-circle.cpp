class Solution {
public:
    bool isRobotBounded(string instructions) {
        /*
         Command Angle : movement
             G       0 : dx=0,dy=1
         L/RRR      90 : dx=-1,dy=0
         LL/RR     180 : dx=0, dy=-1
         LLL/R     270 : dx=1,dy=0
        */
        int dir[4][2]={{0,1}, {-1,0}, {0,-1}, {1,0}};
        int pos_x=0,pos_y=0,angle=0;
        
        for(auto command:instructions){
            if(command=='L')
                angle=(angle+90)%360;
            else if(command=='R')
                angle=(angle+270)%360;
            else
            {
                pos_x+=dir[angle/90][0];
                pos_y+=dir[angle/90][1];
            }
        }
        return (pos_x==0 && pos_y==0) || angle>0;
    }
};