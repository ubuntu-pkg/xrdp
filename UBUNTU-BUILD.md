# Building Ubuntu package

Tested on Ubuntu 16.04

* Create an empty working directory
 ```
mkdir ~/xrdp-build
cd ~/xrdp-build
 ```

* Install dependencies
 ```
apt install git devscripts equivs gdebi-core
git clone -b ubuntu-devel https://github.com/ubuntu-xrdp/xrdp.git
cd xrdp
mk-build-deps -i -r
 ```

* Build xorgxrdp, on Ubuntu 16.04
 ```
debuild binary
 ```

* Build xorgxrdp, on Ubuntu 18.04
 ```
debuild -- binary
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
 
* Install matching version of xrdp-xorg (e.g. from https://github.com/ubuntu-pkg/xorgxrdp/releases)
