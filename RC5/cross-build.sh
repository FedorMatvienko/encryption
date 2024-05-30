# Команда для запуска
# sudo cross-build.sh

BUILD=$PWD/.build
rm -rf $BUILD
mkdir -p $BUILD
cd $BUILD
#CC=clang CXX=clang++ scan-build cmake --build .
CC=clang CXX=clang++ cmake ..
cmake --build .
./RC5