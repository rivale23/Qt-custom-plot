rmdir build
mkdir build
cd build

REM XCOPY ..\required_dlls . /i
cmake  "-GMinGW Makefiles" -DCMAKE_BUILD_TYPE=Release .. "-DCMAKE_PREFIX_PATH:STRING=C:/Qt/5.9.9/mingw53_32" "-DQT_QMAKE_EXECUTABLE:STRING=C:/Qt/5.9.9/mingw53_32/bin/qmake.exe" ..
mingw32-make -j5

QtPlot.exe
cd ..