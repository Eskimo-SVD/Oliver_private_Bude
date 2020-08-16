#!/usr/bin/awk -f

{
	print $1 , $3, $4
}
END { print "Anzahl der Einträge in /etc/passwd: " NR }


