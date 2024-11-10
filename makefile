convert: main.c configGlobalConstants.h checkRangeMode.c checkRangeMode.h checkCmdLineArgs.c checkCmdLineArgs.h convert.c convert.h
	gcc -o convert main.c configGlobalConstants.h checkRangeMode.c checkRangeMode.h checkCmdLineArgs.c checkCmdLineArgs.h convert.c convert.h

ctest: main.c configGlobalConstants.h checkRangeMode.c checkRangeMode.h checkCmdLineArgs.c checkCmdLineArgs.h convert.c convert.h
	gcc -o ctest --coverage main.c configGlobalConstants.h checkRangeMode.c checkRangeMode.h checkCmdLineArgs.c checkCmdLineArgs.h convert.c convert.h
