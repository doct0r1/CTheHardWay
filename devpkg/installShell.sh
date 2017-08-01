set -e  #make it abort on the first error

# go somewhere safe // i'll chose the same directory I'm working on
cd ~/Desktop/C_HardWay/ex41/

# get the source to base APR 1.6.2
curl -L -O http://archive.apache.org/dist/apr/apr-1.6.2.tar.gz

# extract it and go into the source
tar -xzvf apr-1.6.2.tar.gz
cd apr-1.6.2

# configure, make, make install
./configure
make
sodu make install

# reset and cleanup
cd ~/Desktop/C_HardWay/ex41/
rm -rf apr-1.6.2 apr-1.6.2.tar.gz

# do the same with apr-util
curl -L -O http://archive.apache.org/dist/apr/apr-util-1.6.0.tar.gz

# extract it
tar -xzvf apr-util-1.6.0.tar.gz
cd apr-util-1.6.0

# configure, make, make install
./configure --with-apr=/usr/local/apr
# you need that extra parameter to configure because apt-util can't really find it because... who knows.

make
sudo make install

# cleanup
cd ~/Desktop/C_HardWay/ex41/
rm -rf apr-util-1.6.0* apr-1.6.2.*