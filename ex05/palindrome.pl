#!/usr/bin/perl
use strict;
use warnings;

print "Enter a string: ";
my $str = <STDIN>;
chomp $str;

my $rev = reverse $str;
if ($str eq $rev) {
	print "The string is a palindrome!\n"
} else {
	print "The string is not a palindrome!\n"
}
