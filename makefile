convert: main.c configGlobalConstants.h checkRangeMode.c checkRangeMode.h checkCmdLineArgs.c checkCmdLineArgs.h convert.c convert.h
	gcc -o convert main.c configGlobalConstants.h checkRangeMode.c checkRangeMode.h checkCmdLineArgs.c checkCmdLineArgs.h convert.c convert.h

ctest: main.c checkCmdLineArgs.c checkRangeMode.c convert.c
	gcc -o ctest --coverage main.c checkCmdLineArgs.c checkRangeMode.c convert.c
