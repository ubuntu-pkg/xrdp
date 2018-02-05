# Ubuntu packaging recipe for xrdp

Tested on Ubuntu 16.04

* Create an empty working directory
 ```
mkdir ~/xrdp-build
cd ~/xrdp-build
 ```

* Build xrdp
 ```
apt install git devscripts equivs gdebi-core
git clone -b ubuntu-devel https://github.com/ubuntu-xrdp/xrdp.git
cd xrdp
mk-build-deps -i -r
debuild binary
 ```

* Remove old packages manually. Old xrdp config and initscripts can cause problems
 ```
apt-get purge xrdp
 ```

* Install built package
 ```
cd ..
gdebi ./xrdp_*git*.deb
 ```

