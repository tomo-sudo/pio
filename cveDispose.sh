#!/bin/bash

ok="OK"
passwd=""
tmpRt=""

packName=""
versionNum=""
versionSuffix=""

dscName=""
address=""

debName=""

mainVersion=""
littleVersion=""

packVersion=""

atomicValueComp(){
	rt=0
	deb=$1
	apt=$2
	if [[ ${#deb} > ${#apt} ]];then
		rt=1
		return $rt
	elif [[ ${#deb} == ${#apt} ]];then

		if [[ $deb > $apt ]];then
			rt=1
		fi
	fi

	echo "deb $deb; apt $apt; rt $rt "
	return $rt
}

function suffixComp(){
	rt=0

	debSuffix=$1
	aptSuffix=$2

	if [[ $debSuffix =~ "deb" ]] && [[ $aptSuffix =~ "deb" ]];then
	
		        debSuffix=${debSuffix:3}
		        aptSuffix=${aptSuffix:3}
	
			if [[ $debSuffix =~ [a-z] ]];then
				if [[ $aptSuffix =~ [a-z] ]];then
					token=`echo $debSuffix | tr -d "[0-9]"`
					echo "suffixComp $token"

					debSuffixL=${debSuffix%$token*}
					aptSuffixL=${aptSuffix%$token*}

					atomicValueComp $debSuffixL $aptSuffixL
					rt=$?
					echo "suffixComp $rt"
					if [[ $rt == 1 ]];then
						return $rt
					fi

					debSuffixR=${debSuffix#*$token}
					aptSuffixR=${aptSuffix#*$token}

					atomicValueComp $debSuffixR $aptSuffixR
					rt=$?
					echo "suffixComp $rt"

				fi
			fi
	fi 

	return $rt
}


function packNameParse(){
	tmpRt=$1
	dscName=${tmpRt##*/}
	dscName=${dscName%?}
	
	packName=${dscName%%_*}

	packVersion=${dscName#*_}
	packVersion=${packVersion%.*}
}

function packVersionParse(){
	if [[ $packVersion =~ [~] ]];then
	    	versionNum=${packVersion%~*}
		versionSuffix=${packVersion##*~}
	else
		versionNum=$packVersion
	fi
}

function numVersionParse(){
	numVersion=$1

	if [[ $numVersion =~ [-]  ]];then
		mainVersion=${numVersion%%-*}	
		littleVersion=${numVersion#*-}
	else
		mainVersion=$numVersion
	fi
}

function getRt(){
	for index in `cat $1`
	do
		if [ -n "$index" ];then
			tmpRt=$index
		fi
	done
}

function getDebVersion(){
	count=0
	flag=0
	for index in `cat $1`
	do
		if [ -n "$index" ];then
			if [ "Package-List:" = "$index"  ];then
				let count=0
				let flag=1
			fi
			
			if  [ $count = 1 ] && [ $flag = 1 ];then 
				debName=$index
				echo "debName $debName"
				let flag=0
				break
			fi
				
			let count++
		fi
	done
}

function isNeedUpdate()
{
	rt=0

	debMainVersion=$1
	aptMainVersion=$2
	
	while :
	do
		deb=${debMainVersion%%.*}	
		debMainVersion=${debMainVersion#*.}

		apt=${aptMainVersion%%.*}
		aptMainVersion=${aptMainVersion#*.}

		atomicValueComp $deb $apt
		rt=$?
		echo $rt

		if [[ $rt == 1 ]];then
			break
		fi

		if [[ "${debMainVersion}" =~ [.] ]];then
			if [[ "$aptMainVersion" =~ [.] ]];then
				echo "no update"
			else
				echo "33 need update using debian storage"
				rt=1	
				break
			fi
		else
			if [[ "$aptMainVersion" =~ [.]  ]];then
				echo "no update"
			else
				atomicValueComp $debMainVersion $aptMainVersion
				rt=$?
				echo $rt
			fi
			break
		fi
	done

	return $rt
}

function dispSource(){

	packageName=$1
	judgeGitlab $packageName
	result=$?

	if [[ 1 == $result ]];then
		return
	fi

	tmpPath="./dscFileName"
	getRt $tmpPath
	echo "tmpRt $tmpRt"

	packNameParse $tmpRt
	packVersionParse 

	echo "packName $packName"
	echo "versionNum $versionNum"
	debVersionSuffix=$versionSuffix
	echo "debVersionSuffix $versionSuffix"
	echo "dscFileName $dscName"

	numVersionParse $versionNum
	debMainVersion=$mainVersion
	echo "debMainVersion $debMainVersion"
	debLittleVersion=$littleVersion
	echo "debLittleVersion $debLittleVersion"

	packDirPath="./$packageName"
	getDebVersion "$packDirPath/$dscName"
	aptVersion=`apt-cache policy $debName | sed -n '3p'`
	aptVersion=${aptVersion#*： }

	if [[ $aptVersion =~ [:] ]];then
		aptVersion=${aptVersion#*:}
	fi

	echo "apt$aptVersion"
	echo "deb$versionNum"

	packVersion=$aptVersion
	packVersionParse 
	aptVersionNum=$versionNum
	aptVersionSuffix=$versionSuffix
	echo "aptVersionNum $aptVersionNum"
	echo "aptVersionSuffix $aptVersionSuffix"

	numVersionParse $aptVersionNum
	aptMainVersion=$mainVersion
	echo "aptMainV $aptMainVersion"
	aptLittleVersion=$littleVersion
	echo "aptLittleVersion $aptLittleVersion"

	debPlusVersion=""
	aptPlusVersion=""

	if [[ "$debMainVersion" =~ [+] ]];then
		echo "+ start"
		debPlusVersion=${debMainVersion#*+}
		debMainVersion=${debMainVersion%%+*}
	fi

	if [[ "$aptMainVersion" =~ [+] ]];then
		echo "+ start"
		aptPlusVersion=${aptMainVersion#*+}
		aptMainVersion=${aptMainVersion%%+*}
	fi

	echo "debMainVersion $debMainVersion; debPlusVersion $debPlusVersion; aptMainVersion $aptMainVersion; aptPlusVersion $aptPlusVersion"
	echo "debLittleVersion $debLittleVersion; debVersionSuffix $debVersionSuffix; aptLittleVersion $aptLittleVersion; aptVersionSuffix $aptVersionSuffix"

	rt=0;

	isNeedUpdate $debMainVersion $aptMainVersion
	rt=$?

	if [[ $rt == 1 ]] && [[ ${#debPlusVersion} != 0 ]];then
		rt=0
		if [[ ${#aptPlusVersion} == 0 ]];then
			rt=1
		else
			atomicValueComp $debPlusVersion $aptPlusVersion
			rt=$?
			echo $rt
		fi
	fi

	echo "rt 1 $rt"

	if [[ $rt == 1 ]];then
		echo "suffix parse start"
		suffixComp $debVersionSuffix $aptVersionSuffix
		rt=$?
	fi

	if [[ 0 == $rt ]];then
		rm -rf $packDirPath/*
		cd $packDirPath
		apt-get source $packageName
		rt=$?
	
		if [[ 0 != $rt ]];then
			return
		fi

		cd -
	fi

	echo "rt 2 $rt"

	
	cd $packDirPath
	dpkg-source -x $dscName

#	if [ $? -ne 0 ];then
#		return
#	fi

	sourceDir="./`ls -t|head -n 1`"
	cd $sourceDir

	echo $passwd | sudo -S apt build-dep . -y

	if [ $? -ne 0 ];then
		return
	fi


	dpkg-buildpackage -nc -us -uc

	if [ $? -ne 0 ];then
		echo "$packageName deb generate error"
		return
	fi
}

function judgeGitlab(){
	packageName=$1
	if [ -z "$packageName" ];then
		echo "no pack in"
		return 0
	fi

	if [ "linux" = "$packageName" ];then
		echo "linux is not to be disposed"
		return 0
	fi

	python3 dispGitlab.py $packageName 

	tmpPath="./gitlabState"
	getRt $tmpPath
	gitlabRt=$tmpRt


	if [ $gitlabRt = 1 ];then
		echo "gitlab content exists"
		return 1

	elif [ $gitlabRt = 0 ];then
		echo "$packageName get source"
		python3 getSource.py $packageName
		return 0
	fi
}

dispSource $1
