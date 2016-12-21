#include <cstdio>

char banString[10] = "CAMBRIDGE";
char inputString[111];

int main() {
	scanf("%s", inputString);

	for (int i = 0; inputString[i]; i++) {
		for (int j = 0; banString[j]; j++) {
			if (inputString[i] == banString[j]) {
				inputString[i] = 1;
			}
		}
	}

	for (int i = 0; inputString[i]; i++) {
		if (inputString[i] != 1) printf("%c", inputString[i]);
	}

	return 0;
}
