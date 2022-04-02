/**
 * @file Datei_L_und_S.cpp
 * @author Yinghan Huang 03728454 and Zhishen Zhang 03736826
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>

void read_file(std::string Dateiname){
	std::ifstream ifile;
	char line[40] = {0};
	ifile.open(Dateiname, std::ios::in);
	if(!ifile.is_open())
	{
		std::cout << "file does not exit";
		return;
	}
	else{

		while(ifile.getline(line, 40)){
			std::cout << line << '\n';
		}

		ifile.close();
	}
}

void write_file(std::string Dateiname){
	std::ofstream ofile;
	std::string line;
	ofile.open(Dateiname, std::ios::app);
	if(!ofile.is_open())
	{
		std::cout << "file does not exit";
		return;
	}
	else{

		while(getline(std::cin, line)){
			if(line == "exit"){
				break;
			}
			else{
				ofile << line << std::endl;
			}
		}

		ofile.close();
	}
}

int main(){
	std::cout<<"read test:"<<std::endl;
	std::cout<<"----read starts----"<<std::endl;
	read_file("text.txt");
	std::cout<<"----read ends----\n"<<std::endl;
	std::cout<<"now you can add somthing to the txt file and enter \"exit\" to close the file:"<<std::endl;
	write_file("text.txt");
	std::cout<<"\nAfter modification, the txt file is:"<<std::endl;
	read_file("text.txt");
	return 0;
}
