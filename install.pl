#!/usr/bin/perl
use strict;
use warnings;
if(-f "/usr/include/cfc_util.h"){
	system "rm /usr/include/cfc_util.h";
}
system "sudo cp cfc_util.h /usr/include/";
if(-d "/usr/bin/cfcf"){
	system "rm -r /usr/bin/cfcf";
}
system "mkdir /usr/bin/cfcf";
system "cp cfc.c /usr/bin/cfcf";
chdir "/usr/bin/cfcf";
system "gcc -o cfc cfc.c";
system "chmod 777 /usr/bin/cfcf";
