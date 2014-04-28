#!/bin/sh
set -e
file_func=name_func.txt
FLAG=flag
echo "parsing func_name.txt......."

while read LINE
do
	type=`echo $LINE |awk -F " " '{print $1}'`
	func=`echo $LINE |awk -F " " '{print $2}'`
	var=`echo $LINE |awk -F " " '{print $3}'`
	filename=$func
	echo type: $type
	echo func: $func
	echo var: $var
	dirname=$filename
	filename=$(echo $filename)_flag
	echo filename:$filename
	echo dirname:$dirname
	
	##add dir
	rm -rf $dirname
	mkdir $dirname
	
	complexdirname=$dirname/$filename
	echo complexdirname:$complexdirname
	
	#######################源文件list############################################
	#include header
	echo -e \#include \"$filename.h\" >$complexdirname.c
	#add set function 
	echo void setflag_$func\(void\) >>$complexdirname.c
	echo {                          >>$complexdirname.c
	echo "    $var = 1;"            >>$complexdirname.c
	echo }                          >>$complexdirname.c
	
	###add \n
	echo >>$complexdirname.c
	
	##add get function
	echo $type getflag_$func\(void\) >>$complexdirname.c
	echo {                       >>$complexdirname.c
	echo "    return $var;"      >>$complexdirname.c
	echo }                       >>$complexdirname.c
	
	###add \n
	echo >>$complexdirname.c
	
	#add clr function
	echo void clrflag_$func\(void\) >>$complexdirname.c
	echo {                       >>$complexdirname.c
	echo "    $var = 0;"         >>$complexdirname.c
	echo }                       >>$complexdirname.c
	#######################头文件list############################################
	#add func declaration 
	header=$(echo $filename | tr '[a-z]' '[A-Z]') 
	echo header:$header
	echo "#ifndef _"$header"__H"            >$complexdirname.h
	echo "#define _"$header"__H"            >>$complexdirname.h
	echo -e void"\t"setflag_$func\(void\)\; >>$complexdirname.h
	echo -e $type"\t"getflag_$func\(void\)\;>>$complexdirname.h
	echo -e void"\t"clrflag_$func\(void\)\; >>$complexdirname.h
	echo "#endif"                           >>$complexdirname.h
	

done < $file_func
