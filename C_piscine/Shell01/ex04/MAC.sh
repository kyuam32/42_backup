ifconfig | grep -w ether | sed 's/ether//g' | tr -d ' ' | tr -d '	'
