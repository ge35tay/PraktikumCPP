#include <string>
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
	read_file("text.txt");
	write_file("text.txt");
	return 0;
}
