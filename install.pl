#!/usr/bin/perl
use strict;
use warnings;
if($<!=0){
    print "you must execute in sudo\n";
    print "install cfc --NOT OK\n";
    die;
}
print "what`s your folder name in /var/www/*/ ?";
#changing dir /var/www/*/
my $folder = <STDIN>;
chomp $folder;
open FP ,"<cfc.c";
$/=undef;
my $data=<FP>;
$data =~ s/_FOLDER_/$folder/;
close FP;
open FP ,">cfc_out.c";
print FP $data;
close FP;
#make debug interpreter
open FP,"<cfc.c";
$data=<FP>;
$data =~ s/save_input(){/save_input(){return;/;
close FP;
open FP,">cfc_debug.c";
print FP $data;
close FP;

if(-f "/usr/include/cfc_util.h"){
    print "delete orgin file...\n";
	system "rm /usr/include/cfc_util.h";
}
print "regist [cfc_util.h] in main C Std Lib...\n";
system "sudo cp cfc_util.h /usr/include/";
if(-d "/usr/bin/cfcf"){
    print "delete origin dir...\n";
	system "rm -r /usr/bin/cfcf";
}
system "mkdir /usr/bin/cfcf";
print "installing Lib...\n";
system "mv cfc_out.c /usr/bin/cfcf";
system "mv cfc_debug.c /usr/bin/cfcf";
chdir "/usr/bin/cfcf";
print "compiling Lib...\n";
system "gcc -o cfc cfc_out.c";
system "gcc -o cfcd cfc_debug.c";
system "chmod 777 /usr/bin/cfcf";
print "install cfc --OK\n";
