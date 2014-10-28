#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
	system("git remote add upstream https://github.com/trumae/ec8top.git");
	system("git fetch upstream");
	system("git merge upstream/master");
	system("git push origin");
   	return EXIT_SUCCESS;
}
