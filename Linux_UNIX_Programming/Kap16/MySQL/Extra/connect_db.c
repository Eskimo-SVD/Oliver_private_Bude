#include <stdio.h>
#include <sys/types.h>
#include <regex.h>
#include <mysql/mysql.h>

#define __MAX_LINE__ 100


/*	Compile with -D_DATA_FILE_="/path/to/db/data"
	data is a ascci text file with variable/value pairs:
		VAR Value
	splitted by _1_ whitespace.
	comments start with a # at the _first_ character of a line
	Please set this Variables:
		user
		passwd
		database
		host
	and if you dont use the default port or localhost then
		port
	*/

int connect_db(mysql *mysql)
{
	FILE	*db_data		= NULL;
	regex_t	 reg;
	char	 user[__MAX_LINE__]	= "";
	char	 passwd[__MAX_LINE__]	= "";
	char	 database[__MAX_LINE__]	= "";
	char	 host[__MAX_LINE__]	= "";
	int	 port			= 0;
	char	 tmp[__MAX_LINE__];
	char	 buf[__MAX_LINE__];
	int	 a, b;
	int	 length;

	if((db_data = fopen(_DATA_FILE_, "r")) == NULL)return 1;	// File error
	/*	Syntax 		*/
	regcomp(&reg, "^([a-zA-Z0-9:]+)[ ][a-zA-Z0-9]+$", REG_EXTENDED | REG_NEWLINE);
	while(fgets(buf, __MAX_LINE__, db_data))
	{
		length = strlen(buf);
		if(length < 3)continue;
		if(length >= __MAX_LINE__)
		{
			fclose(db_data);
			regfree(&reg);
			return 2;	// Line to long. If your data lines are proper, use a higher value for __MAX_LINE__
		}
		if(buf[0] == '#')continue;
		/*	Syntax check	*/
		if(regexec(&reg, buf, 0, 0, 0))
		{
			fclose(db_data);
			regfree(&reg);
			return 3;	// Syntax error in configuration file
		}
		/*	Own split funktion. Regex and strtok are oversized	*/
		for(a = 0, b = 0; a < strlen(buf); a++)
		{
			if(buf[a] == ' ')b++;
		}
		if(b != 1)
		{
			fclose(db_data);
			regfree(&reg);
			return 4;	// More or less then one whitespace - Syntax error
		}
		if((strncmp(buf, "user: ", 6)) == 0)sscanf(buf, "%s %s", &tmp, &user);
		if((strncmp(buf, "passwd: ", 8)) == 0)sscanf(buf, "%s %s", &tmp, &passwd);
		if((strncmp(buf, "database: ", 10)) == 0)sscanf(buf, "%s %s", &tmp, &database);
		if((strncmp(buf, "host: ", 6)) == 0)sscanf(buf, "%s %s", &tmp, &host);
		if((strncmp(buf, "port: ", 6)) == 0)sscanf(buf, "%s %d", &tmp, &port);
	}
	fclose(db_data);
	regfree(&reg);
	if((strlen(user) < 1) || (strlen(passwd) < 1) || (strlen(database) < 1) || (strlen(host) < 1))return 5;
	// not enough data to connect




	mysql_init(mysql);
	if((mysql_real_connect(mysql, host, user, passwd, database, port, NULL, 0)) == NULL)return 6;	// can't connect, see mysql_error()
	return 0;	//	We are connected
}
