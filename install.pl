#!/usr/bin/perl
use strict;
use warnings;
system "mkdir /usr/bin/cfcf";
system "cp cfc.c /usr/bin/cfcf";
chdir "/usr/bin/cfcf";
system "gcc -o cfc cfc.c";
system "chmod 777 /usr/bin/cfcf";
