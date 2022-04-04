/*
 * Manezver.cpp
 *
 *  Created on: 03.04.2022
 *      Author: Yinghan Huang
 */
#include "Maneuver.h"
#include <fstream>
#include <iostream>

Maneuver::Maneuver(){
	adWishSpeed[0] = 0;
	adWishSpeed[1] = 0;
};

void Maneuver::CalcCircle(double Radius, double Speed, double Timestep){
    Coordlist.clear();
    for(int counter=1; counter < (int)((2 * M_PI) / ((Speed / Radius) * Timestep)); counter++){
        double x = Radius * sin(counter * Speed * Timestep / Radius);
        double y = Radius * (1 - cos(counter * Speed * Timestep / Radius));
        Maneuver::Coord Round_coord = Maneuver::Coord(x, y, Speed);
        Coordlist.push_back(Round_coord);
    }
    //iter = Coordlist.begin();
}



void Maneuver::CalcEight(double dRadius, double dSpeed, double dTimestep){
    Coordlist.clear();
    for(int counter=1; counter < (int)((2 * M_PI) /((dSpeed / dRadius) * dTimestep)); counter++){

        double x = dRadius*sin(counter*dSpeed*dTimestep/dRadius);
        double y = dRadius*(1-cos(counter*dSpeed*dTimestep/dRadius));
        Maneuver::Coord this_coord =  Maneuver::Coord(x, y,dSpeed);
        Coordlist.push_back(this_coord);
    }
    //under circle
    for(int counter=1; counter < (int)((2 * M_PI) /((dSpeed / dRadius) * dTimestep)); counter++){
        
        double x = dRadius*sin(counter*dSpeed*dTimestep/dRadius);
        double y = -dRadius*(1-cos(counter*dSpeed*dTimestep/dRadius));
        Maneuver::Coord this_coord =  Maneuver::Coord(x, y, dSpeed);
        Coordlist.push_back(this_coord);

    }
    //iter = Coordlist.begin();

};


void Maneuver::Loglist(std::string sDatei){

    std::ofstream ofile;
	ofile.open(sDatei, std::ofstream::trunc);
	if(!ofile.is_open())
	{
		std::cout << "file does not exit";

	}else{

        //write the file
        for (iter = Coordlist.begin(); iter != Coordlist.end(); ++iter){
            ofile << iter->dX <<"\t"<<iter->dY<<std::endl;
        }
    }
    //close the file
	ofile.close();


}  


bool Maneuver::isRunning(){
    if(bIsRunning){
        return true;
    }else{
        return false;
    }
}

void Maneuver::start(){
    iter=Coordlist.begin();
    bIsRunning = true;

}

void Maneuver::stop(){
    bIsRunning = false;
};

void Maneuver::Proceed(){
    bIsRunning = true;
}

void Maneuver::CalcManeuverSpeed(double dX, double dY, double dW){

    

    if(iter!= Coordlist.end()){
    	// check if the soll position is reached:
        //Winkeld zwischen soll und Akt berechnen
        //soll - akt
    	if(sqrt(pow((iter->dX - dX), 2) + pow((iter->dY - dY), 2)) > dPosDifference)
    	{
    		double phi = atan2((iter->dY-dY), (iter->dX-dX));

    		//4. Winkeldifferenzberechnen:
    		double deltaPhi = phi - dW;
    		 //5. Winkeldifferenzauf]-M_PI,M_PI]begrenzen:
    		if(deltaPhi > M_PI){
    			deltaPhi -= 2*M_PI;
    		}
    		if(deltaPhi <= -M_PI){
    		    deltaPhi += 2*M_PI;
    		}
    		 // 6. Rotationsanteilbestimmen
    		 double dRot = 2*deltaPhi;
    		 if(dRot > 0.5){
    			 dRot = 0.5;
    		 }
    		 if(dRot < -0.5){
    		     dRot = -0.5;
    		 }
    		 // 7. Translationsanteilübernehmen:
    		 double dTra = iter->dV;

    		 // 8. Geschwindigkeitsanteileüberprüfen:
    		 if(dTra*dRot>0){

    			 if(dTra + dRot > dMaxSpeed){
    				 dTra = dMaxSpeed - dRot;
    		     }
    			 if(dTra + dRot < -dMaxSpeed){
    		         dTra = -dMaxSpeed - dRot;
    		     }

    		 }
    		 if(dTra*dRot<0){

    			 if(dTra - dRot > dMaxSpeed){
    				 dTra = dMaxSpeed + dRot;
    		     }
    			 if(dTra - dRot < -dMaxSpeed){
    		         dTra = -dMaxSpeed + dRot;
    		     }

    		 }
    		         // 9.Geschwindigkeiten summieren:
    		 adWishSpeed[0] = dTra + dRot;
    		 adWishSpeed[1] = dTra - dRot;
    	}
    	else{
    		iter ++;
    	}
    }
    if(iter == Coordlist.end()){
    	adWishSpeed[0] = 0.0;
    	adWishSpeed[1] = 0.0;
    	stop();
    	printw("list out");
    }

}




double * Maneuver::GetManeuverSpeed(){
	double *p = adWishSpeed;
    return p;
};
