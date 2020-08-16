#!/usr/bin/awk -f

#Aufruf ./13.4.bash /var/log/syslog
BEGIN {
	printf "| %-30s | %-15s | \n", "Dienst", "Anzahl"
	printf "----------------------------------------------------\n"
	dienst[0]="kernel"
	dienst[1]="dhclient"
	anzahl[0]=0
	anzahl[1]=0
}
{
	if ( $5 ~ /kernel:/ )
	{
	anzahl[0]++1
	}
	if ( $5 ~ /dhclient:/ )
	{
	anzahl[1]++1
	}
}
END {
		for (count=0; count <= 1; count++)
		{
			printf "| %-30s | %-15d | \n", dienst[count],  anzahl[count]
			printf "----------------------------------------------------\n"
		}
}

