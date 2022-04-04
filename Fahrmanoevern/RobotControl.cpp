/**
 * @file RobotControl.cpp
 * @author Yinghan Huang and Zhishen Zhang
 * @brief 
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "RobotControl.h"
#include <cstdlib>
#include <unistd.h>
#include <mutex>

RobotControl::RobotControl(){
    interface.Initialize(0.04, transferFunction);
	transferPointer = this;
	bIsActive = false;
	iMicros[0] = 1500;
	iMicros[1] = 1500;
	current_speed[0] = 0;
	current_speed[1] = 0;
};




void RobotControl::Communicate(){

    // get the maneuver path 
    char givenChar, order;
    double chosenRadius = 0; 
    double chosenSpeed = 0;


    std::cout<<"Should a new maneuver be performed? Enter \"y\" or \"n\""<<std::endl;
    std::cin >> givenChar;
    while(givenChar!='y' && givenChar!='n'){
        std::cin.clear();
        std::cout<<"Please try again\n";
        std::cin >> givenChar;
//        std::cout<<"givenhar"<<givenChar<<std::endl;
    }

    if(givenChar =='y'){
    	bIsActive = true;
        //Radius
        std::cout<<"Please enter the desired radius for the maneuver\n";
        std::cin >> chosenRadius;
        while(chosenRadius<=0){
            std::cin.clear();
            std::cout<<"The radius should be a positive number, please try again!\n";
            std::cin >> chosenRadius;
        }

        //Speed
        std::cout<<"Please enter the desired speed for the maneuver\n";
        std::cin >> chosenSpeed;
        while(chosenSpeed<=0){
            std::cin.clear();
            std::cout<<"The speed should be a positive number, please try again!\n";
            std::cin >> chosenSpeed;
        }

        //path shape
        std::cout<<"Please enter the desired maneuver\nEnter \"8\" for the 8-shaped path and \"o\" for a circle-shaped path\n";
        std::cin >> givenChar;
        while(givenChar!='8' && givenChar!='o'){
            std::cin.clear();
            std::cout<<"Please try again\n";
            std::cin >> givenChar;

        }
        // the corresponding movement generation
        if(givenChar == '8'){
            maneuver.CalcEight(chosenRadius, chosenSpeed, timeStep);


        }else if(givenChar == 'o'){
            maneuver.CalcCircle(chosenRadius, chosenSpeed, timeStep);
        }
        //Positionsschaetzung zuruecksetzen
        posEstimation.Reset();

        //ncurses starte
        initscr();
        //step method starten
        sigprocmask(SIG_UNBLOCK, &interface.mask, nullptr);
        nodelay(stdscr, TRUE);
        noecho();
        //Solange nicht q gedrueckt wurde Benutzerwunsch einlesen 
        //und folgende Optionen anbieten: Start, Stop, Proceed
        while (1) {

            //printw("Press J to Start,  K to Proceed, L to Stop\n");
            //givenChar = '\0';
            order = getch();
            if (order != ERR) {

                switch (order) {
                	clear();
                    case 'J'://start
                        printw("%c\n", order);
                        maneuver.start();
                        break;

                    case 'K': //proceed
                        printw("%c\n", order);
                        maneuver.Proceed();
                        break;
                    case 'L': //strop
                        printw("%c\n", order);
                        maneuver.stop();
                        break;
                    case 'q':
                    	maneuver.stop();
                    	break;
                }
                if (order == 'q') break;
            }
        }
    
        //Warten bis Roboter steht
        while( current_speed[0] != 0.0 && current_speed[1] != 0.0){
        	continue;
        };

        //Step-Methode anhalten
        //maneuver.stop();

        //necurse beenden 
        sigprocmask(SIG_BLOCK, &interface.mask, nullptr);
        endwin();

    }else if(givenChar == 'n'){

        bIsActive = false;
    }
    

}

void RobotControl::Step(){
    current_speed[0] = *(interface.GetInput());
    current_speed[1] = *(interface.GetInput() + 1);

    if(!maneuver.isRunning()){
        iMicros[0] = 1500;
        iMicros[1] = 1500;

    }else{

        posEstimation.PredictPosition(current_speed[0], current_speed[1], timeStep);
        double xEst, yEst, winkelEst;
        xEst = *(posEstimation.GetPosition());
        yEst = *(posEstimation.GetPosition()+1);
        winkelEst = *(posEstimation.GetPosition()+2);

        maneuver.CalcManeuverSpeed(xEst, yEst, winkelEst);
//        //left is 1
        motorL.CalculateU(*(maneuver.GetManeuverSpeed()+1) ,current_speed[1]);
        motorR.CalculateU(*(maneuver.GetManeuverSpeed()) ,current_speed[0]);
        iMicros[0] = int(motorR.GetU() + 1500);
        iMicros[1] = int(motorL.GetU() + 1500);

        if(iMicros[0]>2000){
            iMicros[0] = 2000;
        }

        if(iMicros[1]>2000){
            iMicros[1] = 2000;
        }

        if(iMicros[0]<1000){
            iMicros[0] = 1000;
        }

        if(iMicros[1]<1000){
            iMicros[1] = 1000;
        }


    }
    interface.SetOutputs(iMicros);
}

void RobotControl::transferFunction()
{
	transferPointer->Step();
}

RobotControl *RobotControl::transferPointer = nullptr;

bool RobotControl::isActive(){
	if(bIsActive){
		return true;
	}else{
		return false;
	}
}
