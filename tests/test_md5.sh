#!/bin/bash

MD5_PERSO="./ft_ssl md5 "
MD5_ORIGIN="md5 "

COL=$(tput cols)
RES_POS=$(($COL - 4))
MOVE_TO_COL="printf \\033[${RES_POS}G"
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
NORMAL=$(tput sgr0)
RES=0


test_md5 ()
{
	printf "MD5 -> %s" "$1"
	if [ -z $3 ]
	then
		(eval ${MD5_PERSO} $2) > my_hash
		(eval ${MD5_ORIGIN} $2) > origin_hash
	else
		(eval $3 "$4" | eval ${MD5_PERSO} $2) > my_hash
		(eval $3 "$4" | eval ${MD5_ORIGIN} $2) > origin_hash
	fi
 
	diff my_hash origin_hash
	if [ $? -eq 0 ]
	then
		$MOVE_TO_COL
		printf "%s" "${GREEN}[OK]${NORMAL}" $'\n'
	else
		$MOVE_TO_COL
		printf "%s" "${RED}[KO]${NORMAL}" $'\n'
		RES=1
	fi
	rm my_hash
	rm origin_hash
}

test_md5 'empty string 0' '-s ""'
test_md5 'empty input 0' '' 'echo ' ''

test_md5 'subject 0' '' 'echo ' '"pickle rick"'
test_md5 'subject 1' '-p' 'echo ' '"Do not pity the dead, Harry."'
test_md5 'subject 2' '-q -r' 'echo ' '"Pity the living."'
test_md5 'subject 3' '-s "pity those that aren\x27t following baerista on spotify."'
test_md5 'subject 4' '-p auteur' 'echo ' '"be sure to handle edge cases carefully"'
test_md5 'subject 5' 'auteur' 'echo ' '"some of this will not make sense at first"'
test_md5 'subject 6' '-p -r auteur' 'echo ' '"but eventually you will understand"'
test_md5 'subject 7' '-p -s "foo" auteur' 'echo ' '"GL HF let\x27s go"'
test_md5 'subject 8' '-r -p -s "foo" auteur -s "bar"' 'echo ' '"one more thing"'
test_md5 'subject 9' '-r -q -p -s "foo" auteur' 'echo ' '"just to be extra clear"'

test_md5 'simple string 0' '-s "easy"'
test_md5 'simple string 1' '-s "This test contain 48 bytes so I made it biggerr"' 
test_md5 'simple string 2' '-s "Hello"'
test_md5 'simple string 3' '-s "Hello Darkness"' 
test_md5 'simple string 4' '-s "Hello Darkness my old friend"' 

test_md5 'quite string 0' '-q -s "easy"' 
test_md5 'quite string 1' '-q -s "This test contain 48 bytes so I made it biggerr"' 
test_md5 'quite string 2' '-q -s "Hello"' 
test_md5 'quite string 3' '-q -s "Hello Darkness"' 

test_md5 'reverse string 0' '-r -s "Hello Darkness"' 
test_md5 'reverse string 1' '-r -s "top"' 
test_md5 'reverse string 2' '-r -s "How is that a reverse thing"' 
test_md5 'reverse string 3' '-r -s "Maybe a longer input is bad ?"' 


test_md5 'long string 0' '-s "dailleurs clcreuso je suis dsol mais mes entrainjjjjjjjjjjj"' 
test_md5 'long string 1' '-s "dailleurs clcjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjhgfjhgfjreuso je suis dsol mais mes entrainjjjjjjjjjjj"' 
test_md5 'long string 2' '-s "dailleurs clcreuso je suis dsol mais mes entrainjdssssssssssssssssssssssssssssgfdshhhhhhhhhhhhhhhgfddddddddddddddddddddddddddjjjjjjjjjjjjjjjhgddjhfgjjjjjjjjjj"' 

test_md5 'stdin 0' '-p -p -p' 'echo ' 'Bonjour'
test_md5 'stdin 1' '-p' 'echo ' 'Bonjour les amis'
test_md5 'stdin 2' '-p' 'echo ' 'Bonjourrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr'

test_md5 'end -s 0' '-s'
test_md5 'end -s 1' 'src -s'
test_md5 'end -s 2' '-s test Makefile -s'

test_md5 'file then string 0' 'auteur -s test'
test_md5 'file then directory 0' 'auteur src'

test_md5 'stdin 2' '-p' 'echo ' 'Bonjourrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr'
test_md5 'stdin 2' '-p' 'echo ' 'Bonjourrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr'

test_md5 'no flag 0' 'auteur' 
test_md5 'no flag 1' 'Makefile' 
test_md5 'no flag 2' 'ft_ssl' 
test_md5 'no flag 2' '/bin/*' 

test_md5 'files 0' '-p' 'cat ' 'auteur'
test_md5 'files 1' '-p' 'cat ' 'src/ft_ssl.c'

test_md5 'quite reverse string 0' '-q -r -s "Hello Darkness my old friend"' 

test_md5 'quite strings 0' '-q -s "Hello" -s "My friend"' 
test_md5 'quite strings 1' '-q -s "Hello" -s "Darkness my old friend"' 
test_md5 'quite strings 2' '-q -s "Hello Darkness" -s "my old friend"' 

test_md5 'multiple string 0' '-s Hello -s My' 
test_md5 'multiple string 1' '-s My -s old -s Friend' 
test_md5 'multiple string 2' '-s Hello -s "This test contain 48 bytes so I made it biggerr"' 
#test_md5 'multiple string 3' '-s I -s Dont -s know -s what -s I -s should -s -test'

test_md5 'reverse then quite string 0' '-r -s "Maybe a longer input is bad ?" -q -s "oupsi"' 

test_md5 'string then quite string 0' '-s "Maybe a longer input is bad ?" -q -s "oupsi"' 

exit ${RES}
