#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>

#define LIB_INCLUDE_IMPLEMENTATION
#include "lib/lib.hpp"
#define LINUX_LIB_INCLUDE_IMPLEMENTATION
#include "lib/linux_lib.hpp"

int main() {
	struct timespec previous = {};
	clock_gettime(CLOCK_MONOTONIC, &previous);

//	double percentage = 6.0;
//	double percentage = 66.6;
//	double percentage = 99.0;
	double percentage = 100.0;
	double work_time = percentage * 10;

//	int counter = 0;

	while(true) {
//		counter += 1;

		double elapsed = elapsed_since(previous, MS);
		if(elapsed >= work_time) {
			struct timespec duration = {};
			duration.tv_nsec = (1000 - (long)work_time) * 1000 * 1000;
			if(nanosleep(&duration, NULL) == -1) {
				assert(false);
			}

			clock_gettime(CLOCK_MONOTONIC, &previous);
		}
	}

	return 0;
}