#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
			
        particle();
		virtual ~particle(){};

        void resetForce();
        void addForce(float x, float y);
        void addDampingForce();
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
	
		void bounceOffWalls();
	
	
        float damping;

        void	scaleCreature();
        
        ofPoint vertices[3][3];
        ofPoint currVertices[3][3];
        
        ofPoint topHandle;
        ofPoint midHandle;
        ofPoint lowerBoundary;
        ofPoint lowHandle;
        
        ofPoint topHandleDefault;
        ofPoint midHandleDefault;
        ofPoint lowerBoundaryDefault;
        ofPoint lowHandleDefault;
        
        float tentacleLength;
        float creatureScale;
        
        ofPoint justX;
        ofPoint justY;
        ofPoint bothXandY;
        
        float currVel;
        float angle;

        
        vector < ofPoint > points;


    protected:
    private:
};

#endif // PARTICLE_H
