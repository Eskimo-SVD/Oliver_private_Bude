#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <mysql/mysql.h>

int escaped_length(char *str)
{
	int	pos;
	int	length;
	int	str_length;

	str_length = strlen(str);
	for(pos = 0, length = 0; pos < str_length; pos++, length++)
	{
		switch(str[pos])
		{
			case '\"': length++;
			           break;
			case '\'': length++;
				   break;
			case '\\': length++;
				   break;
			case '\n': length++;
				   break;
			case '\r': length++;
				   break;
			default  : break;
		}
	}
	return length;
}


int mysql_printf(char *str, ...)
{
	int	 pos_src;
	int	 pos_dst;
	int	 str_length;
	int	 tmp;
	int	 this_int;
	int	 db_result;
	double	 this_double;
	int	 length;
	char	 tmp_char;
	char	*tmp_str;
	char	*query	= NULL;
	va_list	 list;


	str_length	= strlen(str);

	/*	Calculate string length		*/

	va_start(list, str);
	for(pos_src = 0, length = 0; pos_src < str_length; pos_src++, length++)
	{
		if(str[pos_src] == '%')
		{
			pos_src++;
			if(pos_src >= str_length)
			{
				fprintf(stderr, "Syntax Error:\t%s\n", str);
				exit(1);
			}
			switch(str[pos_src])
			{
				case '%' : break;
				case 'c' : tmp_char = va_arg(list, int);
					   switch(tmp_char)
					   {
						   case '\'': length++;
							      break;
						   case '\"': length++;
							      break;
						   case '\n': length++;
							      break;
						   case '\r': length++;
							      break;
						   default  : break;
					   }
					   break;
				case 'd' : this_int = va_arg(list, int);
					   for(tmp = 1; this_int >= 1; tmp++)this_int = this_int/10;
					   length += tmp;
					   break;
				case 'f' : this_double = va_arg(list, double);
					   for(tmp = 20; this_double >= 1; tmp++)this_double = this_double/10;
					   length += tmp;
					   break;
				case 's' : length += (escaped_length(va_arg(list, char *)));
					   break;
				default  : fprintf(stderr, "Syntax Error:\t%s\n", str);
					   break;
			}
		}
	}


	va_end(list);
	va_start(list, str);

	if((query = malloc((length +1) * sizeof(char))) == NULL)return -1;

	/*	Build valid mysql string	*/

	for(pos_src = 0, pos_dst = 0; pos_src < str_length; pos_src++, pos_dst++)
	{
		if(str[pos_src] == '%')
		{
			pos_src++;
			if(pos_src >= str_length)
			{
				fprintf(stderr, "Syntax Error:\t%s\n", str);
				exit(1);
			}
			switch(str[pos_src])
			{
				case '%' : query[pos_dst]	= str[pos_src];
					   break;
				case 'c' : tmp_char = (char)va_arg(list, int);
					   switch(tmp_char)
					   {
						   case '\'': query[pos_dst++]	= '\\';
							      query[pos_dst]	= tmp_char;
							      break;
						   case '\"': query[pos_dst++]	= '\\';
							      query[pos_dst]	= tmp_char;
							      break;
						   case '\n': query[pos_dst++]	= '\\';
							      query[pos_dst]	= tmp_char;
							      break;
						   case '\r': query[pos_dst++]	= '\\';
							      query[pos_dst]	= tmp_char;
							      break;
						   default  : query[pos_dst]	= tmp_char;
							      break;
					   }
					   break;
				case 'd' : this_int = va_arg(list, int);
					   query[pos_dst]	= '\0';
					   sprintf(query, "%s%d", query, this_int);
					   pos_dst		= strlen(query)-1;
					   break;
				case 'f' : query[pos_dst]	= '\0';
					   sprintf(query, "%s%lf", query, va_arg(list, double));
					   pos_dst		= strlen(query)-1;
					   break;
				case 's' : tmp_str = va_arg(list, char *);
					   for(tmp = 0; tmp < strlen(tmp_str); tmp++)
					   {
						   switch(tmp_str[tmp])
						   {
							   case '\'' : query[pos_dst++] = '\\';
								       query[pos_dst++] = tmp_str[tmp];
								       break;
							   case '\"' : query[pos_dst++] = '\\';
								       query[pos_dst++] = tmp_str[tmp];
								       break;
							   case '\n' : query[pos_dst++] = '\\';
								       query[pos_dst++] = tmp_str[tmp];
								       break;
							   case '\r' : query[pos_dst++] = '\\';
								       query[pos_dst++] = tmp_str[tmp];
								       break;
							   default   : query[pos_dst++] = tmp_str[tmp];
								       break;
						   }
					   }
				pos_dst--;
				break;
				default  : fprintf(stderr, "Syntax Error:\t%s\n", str);
				exit(1);
				break;
			}
		}
		else query[pos_dst]	= str[pos_src];
	}

	query[pos_dst]	= '\0';
	
	va_end(list);
	db_result = mysql_real_query(mysql, query, strlen(query));
	free(query);

	return db_result;
}



