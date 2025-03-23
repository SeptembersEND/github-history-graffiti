#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdint.h>
#include <string.h>


#define WEEKS	48
// '-1': not day yet
//  0-9: draw
const int8_t timeline[7][WEEKS] = {
	/*Su*/ {0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	/*Mo*/ {0,0,0,0,0,0,0,0,4,3,2,2,1,2,2,3,4,0,0,1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0},
	/*Tu*/ {0,0,0,0,0,0,0,0,4,2,2,1,1,1,2,2,4,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
	/*We*/ {0,0,0,0,0,0,0,0,4,3,4,4,4,4,4,3,4,0,0,1,1,1,0,1,1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0},
	/*Th*/ {0,0,0,0,0,0,0,0,4,4,1,4,1,4,1,4,4,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,-1},
	/*Fr*/ {0,0,0,0,0,0,0,0,0,4,1,1,1,1,1,4,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,-1},
	/*Sa*/ {0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1},
};
const int today = 350;

void print(const int8_t line[7][WEEKS]) {
	for (int y=0; y<7; y++) {
		for (int x=0; x<WEEKS; x++) {
			char c = line[y][x];
			if (c >= 0 && c <= 9) {
				printf("%c", c+'0');
			}
			// TODO: add higher values
			else if (c == -1) {
				printf("#");
			}
			else {
				printf("%d", c);
				assert(0 && "Timeline has a value outside of range");
			}
		}
		printf("\n");
	}
}
void run(int val) {
#define BUFS	256
	//printf("%d ", val); return;
	char buf[BUFS] = {0};
	memset(buf, 0, BUFS);
	static int test = 211;

	snprintf(buf, BUFS, "git add . && git commit -m 'Commit Position: #%d try 10 masked' --no-edit --date=\"$(date -uRd $(date -ud '2025-01-01 + %d days' +\%Y-%s-%s))\"", test++, val+1, "%m", "%d");
	FILE* outfile = fopen("command", "w");
	assert(outfile != NULL);
	fprintf(outfile, "Command: `%s`\n", buf);
	fclose(outfile);
	printf("%s\n", buf);
	system(buf);
}
int main(void) {
	int thevalue = 0;
	for (int x=6; x>0; x--) {
		printf("%d\n", timeline[x][WEEKS-1]);
		if (timeline[x][WEEKS-1] >= 0) {
			thevalue = x;
			break;
		}
		assert(timeline[x][WEEKS-1]==-1 && "Incorrect timeline, start with -1's");
		//printf("%c\n", timeline[x][WEEKS-1]);
	}
	printf("Backup: %d\n", thevalue);
	assert(thevalue != 0);


	const int totallength = (today-thevalue) - (WEEKS * 7);
	//printf("%d\n", totallength);
	int z=totallength;

	print(timeline);
	for (int y=0; y<7; y++) {
		for (int x=0,z=WEEKS-1; x<WEEKS-1; x++,z--) {
			char c = timeline[y][x];
			if (c > 0 && c <= 9) {
				int r = (((today-thevalue) - (z * 7)) + y)-1;
				//printf("%d,", r);
				for (int x=0; x<c; x++) {
				assert(c != 0);
					run(r);
				}
			}
		}
		printf("\n");
	}
}
