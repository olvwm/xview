all : libs olvwm clients

install : install-libs install-olvwm install-clients

dep :
	apt-get install -y xutils-dev libx11-dev libxt-dev libxext-dex libxpm-dev bison flex

libs :
	(cd xview-3.2p1.4; bash Build-LinuxXView.bash libs)

install-libs :
	(cd xview-3.2p1.4; make SUBDIRS='lib' install)

olvwm :
	(cd xview-3.2p1.4; bash Build-LinuxXView.bash olvwm)

install-olvwm :
	(cd xview-3.2p1.4/clients; make SUBDIRS='olvwm-4.1' install)

clients :
	(cd xview-3.2p1.4; bash Build-LinuxXView.bash clients)

install-clients :
	(cd xview-3.2p1.4; make SUBDIRS='clients' install)
