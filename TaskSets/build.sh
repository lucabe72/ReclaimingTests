cd Fake
make
cd ..
cd MP-Guarantee
make
make bclumax_test
cd ..
cd schedtool-dl
make
cd ..
cd rt-app
./autogen.sh
./configure --with-deadline --with-json
make
cd ..
