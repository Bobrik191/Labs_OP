#include <iostream>
#include "Stream.h"
#include "FileP.h"
#define _CrtSetDebugFillThreshold

using namespace std;

int set_mode(int argc, char** argv) {
	if (argc != 3) return -1;

	std::string flag{ argv[1] },
		mode{ argv[2] };

	if (flag != "-mode") return -1;

	if (mode == "FilePointer") return 1;
	if (mode == "FileStream") return 2;

	return -1;
}

int main(int argc, char* argv[]) {
	int mode = set_mode(argc, argv);

	if (mode == -1) {
		cout << "Invalid specified" << endl;
		return 1;
	}
	if (mode == 1) {
		cout << "FilePointer mode" << endl;
		char* filein = FP_enter_name();
		FP_write_to_file(filein);
		char* fileout = FP_enter_name();
	
		FP_print_file(filein);

		char* str1 = FP_read_text(filein);
		FP_work_file(str1, fileout);
		FP_print_file(fileout);

		char* str = FP_read_text(fileout);
		FP_replaceDuplicatesWithBrackets(str, fileout);
		FP_print_file(fileout);
	}
	else if (mode == 2) {
		cout << "FileStream mode" << endl;
		string file1 = enter_name();
		write_to_file(file1);

		string fileout = enter_name();

		print_file(file1);

		string str = read_file(file1);
		work_file(str, fileout);
		print_file(fileout);

		string interm = read_file(fileout);
		string result = replaceDuplicatesWithBrackets(interm);
		add_data_to_file(fileout, result);
		print_file(fileout);
	}
	return 0;
}