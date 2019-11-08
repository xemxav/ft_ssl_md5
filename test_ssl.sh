#!/bin/bash

check_test ()
{
	eval $1
	if [ $? -ne 0 ]
	then
		exit 1
	fi
}


check_test './tests/test_md5.sh'
check_test './tests/test_sha256.sh'
#check_test './tests/test_sha384.sh'
#check_test './tests/test_sha512.sh'
#check_test './tests/test_sha512224.sh'
#check_test './tests/test_sha512256.sh'
