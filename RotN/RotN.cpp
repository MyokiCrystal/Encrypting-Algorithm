#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <iostream>
using namespace std;

intmax_t StI(string t){
	intmax_t temp;
	istringstream(t) >> temp;
	return temp;
}

const string help = "-h";

int main(int argc,char *argv[]){
	if (argc == 1 or argv[1] == help){
		printf("---- HELP PANEL ----\n");
		printf("#1 : help : \"-h\"\n");
		printf("#2 : format : rotN string cipher\n");
		printf("#3 : alphabet rule:\n");
		printf("abcdefghijklmnopqrstuvwxyz\n");
		printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
		printf("0123456789\n");
		printf("--------------------\n");
		exit(0);
	}
	else if (argc != 3) {
		printf("Invalid format! May be you need \"-h\"\n");
		exit(0);
	}
	else {
		int cipher = StI(argv[2]) % 26;
		if (cipher <= 0) {
			printf("Invalid format! May be you need \"-h\"\n");
			exit(0);
		}

		string s = argv[1];
		intmax_t len = s.size();

		//printf("%s %d\n", s.c_str(), cipher);

		for (intmax_t i = 0; i < len; ++i){
			int temp = s[i];
			if (temp >= 65 and temp <= 90){
				temp = ( ( ( temp - 65 ) + cipher ) % 26 ) + 65 ;
			}
			else if (temp >= 97 and temp <= 122){
				temp = ( ( ( temp - 97 ) + cipher ) % 26 ) + 97 ;
			}
			else if (temp >= 48 and temp <= 57){
				temp = ( ( ( temp - 48 ) + cipher ) % 10 ) + 48 ;
			}
			printf ("%c",temp);
		}
		printf("\n");
		exit(0);
	}
}
