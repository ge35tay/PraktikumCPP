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
};




void RobotControl::Communicate(){

    // get the maneuver path 
    char givenChar;
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
            maneuver.CalcEight(chosenRadius, chosenSpeed,timeStep);


        }else if(givenChar == 'o'){
            maneuver.CalcCircle(chosenRadius, chosenSpeed,timeStep);
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
            clear();
            printw("Press 1 to Start,  2 to Proceed, 3 to Stop\n");
            givenChar = '\0';
            givenChar = getch();
            if (givenChar == 'q'){
                break;
            }
            if (givenChar != ERR) {
                switch (givenChar) {
                    case '1'://start
                        printw("%c\n", givenChar);
                        maneuver.start();
                        break;

                    case '2': //proceed
                        printw("%c\n", givenChar);
                        maneuver.Proceed();
                        break;
                    case '3': //proceed
                        printw("%c\n", givenChar);
                        maneuver.stop();
                        break;
                }
            }
        }
    
        //Warten bis Roboter steht
        while(!(abs(current_speed[0] <= 0.005) && abs(current_speed[1]) <= 0.005)){};

        //Step-Methode anhalten
        maneuver.stop();

        //necurse beenden 
        sigprocmask(SIG_BLOCK, &interface.mask, nullptr);
        endwin();

    }else{

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
        iMicros[0] = motorR.GetU() + 1500;
        iMicros[1] = motorL.GetU() + 1500;

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

        interface.SetOutputs(&iMicros[0]);
    }
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
