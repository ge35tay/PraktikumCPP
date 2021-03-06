/*
 * main.cpp
 *
 *  Created on: 02.04.2022
 *      Author: Yinghan Huang
 */

#include "PosEstimation.h"
#include "Maneuver.h"
#include "RobotControl.h"
#include <fstream>


int main(){
	// double SpeedR, SpeedL, T;   // for estimation
	// double x, y, w;       // true vaule
	// PosEstimation PosE;
	// std::fstream File_pos, File_result;
	// double * coord;
	// int flag = 0;

	// File_pos.open("PosEstimationInput.txt", std::ios::in);  // read only
	// File_result.open("PosEstimationVgl.txt", std::ios::in);	// read only

	// if(!File_pos.is_open()){
	// 	std::cout << "File no exit \n" << std::endl;
	// }
	// else{
	// 	while(!File_pos.eof()){
	// 		File_pos >> SpeedR >> SpeedL >> T;
	// 		File_result >> x >> y >> w;
	// 		PosE.PredictPosition(SpeedR, SpeedL, T);
	// 		coord = PosE.GetPosition();
	// 		std::cout << "Estimated X: " << coord[0] << ", Y: " << coord[1] << ", w: " << coord[2] << std::endl;


	// 		// compare true value and estimated value
	// 		if((x-coord[0] > 1e-4) || (y-coord[1] > 1e-4) || (w-coord[2] > 1e-4)){
	// 			flag = 1;
	// 		}
	// 	}
	// 	File_pos.close();
	// 	File_result.close();
	// }

	// if(flag == 0){
	// 	std::cout << "Well played, exactly estimate \n" << std::endl;
	// }
	// else{
	// 	std::cout << "Your estimation is intersting \n" << std::endl;
	// }


	// Maneuver maneuver8, maneuverO;
	// maneuverO.CalcCircle(2.0,0.3,0.04);
	// maneuverO.Loglist("LogFileCircle.txt");
	// maneuver8.CalcEight(5.0,1.0,10.0);
	// maneuver8.Loglist("LogFileEight.txt");

	RobotControl robotControl;
	do{
		robotControl.Communicate();
	}while(robotControl.isActive());
	

	return 0;
}


