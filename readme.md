# Ubuntu packaging recipe for xrdp

Tested on Ubuntu 15.10

* Create an empty working directory
 ```
mkdir ~/xrdp-build
cd ~/xrdp-build
 ```

* Build and install X11rdp, if you don't already have it. This is necessary since ubuntu's vncserver won't work for copy&paste
 ```
git clone https://github.com/scarygliders/X11RDP-o-Matic
cd X11RDP-o-Matic 
./X11rdp-o-matic.sh --justdoit --noinstall
cd ..
apt-get install gdebi-core
gdebi ./X11RDP-o-Matic/packages/x11rdp/x11rdp_*.deb
 ```

* Build xrdp separately. This is needed since currently X11RDP-o-Matic's build does not include fuse support
 ```
git clone -b ubuntu https://github.com/ubuntu-xrdp/xrdp.git
cd xrdp
dpkg-checkbuilddeps
 ```
install necessary dependencies using ``apt-get``, then continue
 ```
dpkg-buildpackage -b
cd ..
 ```

* Remove old packages manually. Old xrdp config and initscripts can cause problems
 ```
apt-get purge xrdp
 ```

* Install built package
 ```
gdebi ./xrdp_0.9.0+git*.deb
 ```

