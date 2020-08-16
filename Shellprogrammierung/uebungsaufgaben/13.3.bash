#!/usr/bin/awk -f

#Aufruf ./7.2.bash /etc/passwd

BEGIN {
printf "| %-20s | %-10s | %-10s |\n", "Benutzename", "UserID", "GroupID"
printf "--------------------------------------------------\n"
FS=":"
}
$3 >= 1000 {
	counter+=1
	printf "| %-20s | %-10s | %-10s |\n", $1 , $3, $4 
  printf "--------------------------------------------------\n"
}
END { 
	print "Anzahl der Einträge in /etc/passwd: " NR 
	print "Anzahl der Einträge mit UserID > 1000 : " counter
	}
