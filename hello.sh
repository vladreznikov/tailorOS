#!/bin/bash
# My script

#Cmd: $1
#password: $2
#status: $3
_mydir="$(pwd)"
echo "`dirname $0`"

	if [ $1 = "password" ]
	then
		>init.txt
		echo "status=001" | tee init.txt	
		sleep .1
		echo $2 | sudo -S -k apt-get install gzip tar wget bash binutils file python3 bc libcurl4-gnutls-dev libexpat1-dev gettext libz-dev libssl-dev git g++ minicom 
	fi


	if [ $1 = "download" ]
	then
		>init.txt
		echo "status=002" | tee init.txt
		wget "https://buildroot.org/downloads/buildroot-2019.05.1.tar.gz" 
		>init.txt
		echo "status=003" | tee init.txt
		tar -xzvf buildroot-2019.05.1.tar.gz 
		>init.txt
		echo "status=004" | tee init.txt
		cd buildroot-2019.05.1 && git clone https://github.com/vladreznikov/minimal_raspberrypi_config.git
		>init.txt
		echo "status=010" | tee init.txt 
		echo "the pwd is $(pwd)" 
		make BR2_EXTERNAL="$(pwd)"/minimal_raspberrypi_config minimal_defconfig
	 	cd ..
		echo "status=020" | tee init.txt
		#echo "status=020" | tee init.txt
		#make list-defconfigs
		>init.txt
		echo "status=100" | tee init.txt 
		#echo "$direct"  | tee init.txt
		
		#cd buildroot-2019.05.1 && make BR2_EXTERNAL=~/Desktop/dissertation_app/tailorOS/minimal_raspberrypi_buildroot-master/  raspberrypi3_minimal_defconfig 
		
		
	
	fi

# wget "http://cachefly.cachefly.net/100mb.test"




