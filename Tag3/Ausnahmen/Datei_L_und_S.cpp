#include <string>
#include <iostream>
#include <fstream>
#include <exception>

class nofileException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Die Datei existiert nicht";
	}
};
void read_file(std::string Dateiname){
	std::ifstream ifile;
	char line[40] = {0};
	ifile.open(Dateiname, std::ios::in);
	if(ifile.fail())
	{
		throw nofileException{};
	}
	else{

		while(ifile.getline(line, 40)){
			std::cout << line << '\n';
		}

		ifile.close();
	}
}


int main(){
	try{
		read_file("texts.txt");
	}
	catch (nofileException& e){
		std::cout << e.what()<<std::endl;
	}


	return 0;
}
