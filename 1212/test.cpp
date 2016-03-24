#include <stdio.h>
#include <string.h>

int main () {
  char input[333334];
	int i;
	int input_len;

  scanf("%s", input);

	input_len = strlen(input);

	if (input[0] == '1') printf("%s", "1");
	if (input[0] == '2') printf("%s", "10");
	if (input[0] == '3') printf("%s", "11");
	if (input[0] == '4') printf("%s", "100");
	if (input[0] == '5') printf("%s", "101");
	if (input[0] == '6') printf("%s", "110");
	if (input[0] == '7') printf("%s", "111");
	if (input[0] == '0') printf("%s", "0");

	for(i = 1; i < input_len; i++){
		if (input[i] == '1') printf("%s", "001");
		if (input[i] == '2') printf("%s", "010");
		if (input[i] == '3') printf("%s", "011");
		if (input[i] == '4') printf("%s", "100");
		if (input[i] == '5') printf("%s", "101");
		if (input[i] == '6') printf("%s", "110");
		if (input[i] == '7') printf("%s", "111");
		if (input[i] == '0') printf("%s", "000");
	}

  return 0;
}
