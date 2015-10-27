#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

int convert_int(string t){
	int len = t.size();
	if ( (len >= 3 and t[0] != '-') or (t[0] == '-' and len>=4) ) {
		printf("Try to simplified the number\n");
		exit(0);
	}
	int res = 0;
	int i = 0;
	bool skip = false;
	while (i<len){
		if (t[i] == '-') {
			skip = true;
		}
		else {
			res += (int(t[i])-'0') * pow(10,len-i-1);
		}
		i++;
	}
	if (skip) return -res;
	else return res;
}


int main(int argc, char *argv[]){
	string help = "-h";
	if (argv[1] == help){
		printf("---- HELP PANEL ----\n");
		printf("#1 : help : \"-h\"\n");
		printf("#2 : format : rotN string cipher\n");
		printf("--------------------\n");
		exit(0);
	}
	else if (argc != 3) {
		printf("Invalid format! May be you need \"-h\"\n");
		exit(0);
	}

	string s = argv[1];
	int cipher = convert_int(argv[2]) % 26;

	//cout << s << " " << cipher << endl;

	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		if (s[i] >= 65 and s[i] <= 90){
			if (s[i] + cipher > 90) s[i] = s[i] - 26 + cipher;
			else if (s[i] + cipher < 65) s[i] = s[i] + 26 + cipher;
			else s[i] = s[i] + cipher;
		}
		else if (s[i] >= 97 and s[i] <= 122){
			if (s[i] + cipher > 122) s[i] = s[i] - 26 + cipher;
			else if (s[i] + cipher < 97) s[i] = s[i] + 26 + cipher;
			else s[i] = s[i] + cipher;
		}
		printf("%c",s[i]);
	}
	printf ("\n");
	exit(0);
}
