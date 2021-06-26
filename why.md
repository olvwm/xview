RATIONALE
=========

Can I keep my red stapler, please?
----------------------------------
2021 June 18

This is just a long winded explanation of why this repo exists.

My window manager of choice (for a couple of _decades_ now) has been the
[OpenLook Virtual Window Manager (olvwm)](https://en.wikipedia.org/wiki/Olvwm)

**_Thank you Scott Oaks_**, for software that I've used almost every single day
for over 25 years!

My first contact with olvwm was soon after I started working at Sun Microsystems
and I was hooked. I did prefer a "somber grey" background to the "sky blue"
default, but that was easy enough to change. An obvious reason for such a long
term attachment is that it was the only window manager that gives you lots of
"virtual screens" which could be shoe-horned into a single real screen and
allowed you to see all your windows on all screens at a glance and switch to
any one of them using the keyboard (or the mouse, or any combination).

Nowadays, although other choices (such as [fvwm](https://en.wikipedia.org/wiki/Fvwm)) with virtual screens are available, in my opinion though, they were
not as good as olvwm (at least when I tested them).

Even after Sun's internal switch from [OpenWindows](https://en.wikipedia.org/wiki/OpenWindows)
to the [Common Desktop Environment (CDE)](https://en.wikipedia.org/wiki/Common_Desktop_Environment),
I continued using olvwm instead of the default [Motif Window Manager (mwm)](https://en.wikipedia.org/wiki/Motif_Window_Manager)
since the olvwm+xview package continued to be available within the Sun network.
I never understood why people tolerated mwm with its "opaque desktops"
at the bottom of the screen when olvwm with its much superior functionality
of being able to see all your windows on all screens already existed.

After I left Sun (then Oracle) I continued to use olvwm on my laptop which
at that time ran Solaris x86. Eventually when I got a laptop which needed
drivers that were not available on Solaris, I made the transition (maybe
~10 years ago) moving to Linux/Ubuntu when I found that a port of olvwm/xview
existed for Debian (and by extension, on Ubuntu).

Here's a handy link for everything you need to know to run [olvwm on Ubuntu](http://mlab.no/blog/2015/11/olvwm-on-ubuntu/)

There is an older link (with some outdated info) about [xview on various OSes](https://archive.physionet.org/physiotools/xview/)
(Note: this site also has links to download the "lucida" fonts that are needed
in xview - but that font dependency is optional on Debian/Ubuntu)

Now, here's the trick question: If you have an open source piece of userland
window manager software running on top of an open source piece of kernel
software, all your window manager troubles are over, right?

Apparently not, because it turns out, Ubuntu 16.04(Xenial) which went out of
long term support recently<sup>[1](#ubuntu_lts)</sup>, was the last version of
Ubuntu on which olvwm is still available as an installable package.

So why is olvwm [no longer in Ubuntu?](https://packages.ubuntu.com/search?keywords=olvwm)
It turns out this is because the last
existing version of xview on Debian is available only in Jessie(oldoldstable)
and it was removed from the newer releases. Searching around for info on why
xview needed to be pulled out of Debian led me to [bugid 852532](https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=852532)
which lists some of the patches that were generated to fix some of the 64 bit
type mismatch issues in olvwm.

The (g)rumblings about removing
xview due to 64 bit issues appear to have started [as early as 2005](https://linux.debian.bugs.dist.narkive.com/iEEqkilp/bug-296561-ftp-debian-org-please-remove-broken-xview-ia64-upload)

xview languished in this limbo until it was turned into an [orphaned package](https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=911774) on 24 Oct 2018 and
[removed from Debian](https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=911787)
post haste on the very same day.

In case you are curious about the life and death of this package on Ubuntu,
the entire [history is available](https://launchpad.net/debian/+source/xview/+publishinghistory)

Looking around for other alternate Linux distros which include the olvwm package
led me to the [olvwm Arch AUR bundle](https://aur.archlinux.org/packages/olvwm/)
but digging deeper showed that the AUR package internally depends on links to
the xview Debian package's tar files which have now link rotted away since xview
is no longer available on Debian.

Slack might be a [viable 32 bit alternative](https://slackbuilds.org/repository/14.2/libraries/xview/)
if that is all you need.

Yet another (non-Linux) alternative might be to switch to [NetBSD](http://ftp.netbsd.org/pub/pkgsrc/current/pkgsrc/wm/olvwm/README.html)
which has xview/olvwm (via pkgsrc) but again only for [32-bit](http://daemonforums.org/showthread.php?t=11373)

FreeBSD had a port which appears to have been deleted [last year (April 2020)](https://www.freshports.org/x11-wm/olvwm)

Yet another ancient version seems to be available from [PLD Linux](https://git.pld-linux.org/?p=packages/xview.git;a=blob;f=xview.spec;hb=HEAD)
but the links mentioned there appear to suffer from link rot as well.

Over on [Devuan](https://en.wikipedia.org/wiki/Devuan), there was a
[discussion](https://lists.dyne.org/lurker/message/20210331.175901.1545d784.es.html)
as recently as 3 months ago
about resurrecting xview with an extremely helpful reply from Andreas Messer
on how to integrate it into Devuan.

Given that nobody is working on the upstream sources (the last update to
olvwm4.5 was in 2003 and work on xview may have stopped much earlier than that),
the only feasible choice most distro maintainers usually have is to get rid of
the offending package. All that I'm attempting to do here is to maintain a
copy of the last built source + fixes I've made to keep things working.

All of the mailing list discussion about olvwm (and xview) makes me believe that
I'm not the only one with this quixotic obsession. And even if there was no one
else in the world that had an interest in keeping olvwm alive, I think it is
worth my time to at least try and build it on my own so I can be free of random
distro dependencies (and/or arbitrary maintainer choices).

The easiest way to do this, that I can see, is to stick the code on github,
keep a local version controlled copy on my laptop and call it a day. If my
laptop crashes, I can pull from Github and if Github goes away, I can perhaps
host the git repo elsewhere. Also, if there is anyone out there like me, who
still uses olvwm, they can grab a copy from Github if they ever need to tinker
with it (or even host it somewhere else to their liking).

Now that xview is no longer in Debian, the latest Debian source packages have
also vanished, but the Arch AUR build which used the Debian tar files
points to these links:
- http://http.debian.net/debian/pool/main/x/xview/xview_3.2p1.4.orig.tar.gz
- http://http.debian.net/debian/pool/main/x/xview/xview_3.2p1.4-28.2.debian.tar.xz

Since these are newer than the links pointed at by the current Ubuntu/launchpad
sources, I'll choose them as the starting point for the xview code dump.
These are also pointed at by the [Debian](https://launchpad.net/debian/+source/xview/3.2p1.4-28.2)
(and the equivalent [Ubuntu](https://launchpad.net/ubuntu/+source/xview/3.2p1.4-28.2) versions). So that gives me some reassurance that it was the last
available version.

The sha256 checksums of the above tar files are:
- fcc88f884a6cb05789ed800edea24d9c4cf1f60cb7d61f3ce7f10de677ef9e8d and
- c84f18a588b848a95f2fed08c3d0514e96792408ebf8120e53e585efd3045f96 respectively.

Note that although the first link (currently) exists, the second one doesn't.
Luckily a [mirror was available](https://launchpad.net/ubuntu/+archive/primary/+sourcefiles/xview/3.2p1.4-28.2/xview_3.2p1.4-28.2.debian.tar.xz) and I was able
to get a copy from there.

Searching github for any prior work dealing with xview gives me:
- ptribble's [version for Illumos](https://github.com/ptribble/xview-illumos) and
- an archive of [Ian Darwin's OpenLookCDROM](https://github.com/IanDarwin/OpenLookCDROM) (see also: https://www.oreilly.com/openbook/openlook and ftp://ftp.ora.com/pub/openlook/vol3ol.pdf)

Neither of the github repos has what I'm looking for:
- ptribble's code is based on the older Debian patch set and he seems to
have made changes to make things work for his private "tribblix" distro.
I'd like to just stick with a distro which is Debian/Ubuntu-like for now.
- Ian Darwin's repo has a snapshot of the original xview code and does not
include any of the more recent Debian work to get things running on Linux.

Since I can't use either of those existing repos, I'll generate a new repo
using the tar files mentioned earlier as the basis and then build and test
olvwm and if I can't get something working with mostly minimal changes,
perhaps I should just get over it, move on and see what else is new in the
[wide, wide, world of window managers](https://l3net.wordpress.com/2014/02/15/a-memory-comparison-of-light-linux-desktops-part-3/)

Anyway, wish me luck ...

Footnote:

<a name="ubuntu_lts">1</a>:
Ubuntu Linux 16.04 LTS reached the end of its five-year LTS window on
April 30th 2021 and is no longer supported by Canonical except through a
paid annual Extended Security Maintenance (ESM).
