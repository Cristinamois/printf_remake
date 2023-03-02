#ifndef R_PRINTF_H
#define R_PRINTF_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

# define BASE16_MIN	"0123456789abcdef"
# define BASE16_MAJ "0123456789ABCDEF"
# define MALLOC_ERROR 4
# define C 'c'
# define S 's'
# define P 'p'
# define D 'd'
# define I 'i'
# define U 'u'
# define x 'x'
# define X 'X'
# define f 'f'
# define F 'F'


typedef struct s_conversion
{
    va_list             paramInfo;
    unsigned int        _totalLen;
    long long           _ifNumber;
    long long           _ifPointer;
    char                _ifChar;
    char                *_ifStr;
    bool                _isSpace;
    bool                _isZero;
    bool                _isPlus;
    bool                _isMinus;
    int                 _argLen;
    bool                _hashtag;
    char                *_ARGVAL;
    int                 _ARGNBR;
    int                 _count;
    char                _actual;
}               t_conversion;

//UTILS//
void    ft_putchar(t_conversion *what, char c);
void    ft_putstr(t_conversion *what, char *str);
void    ft_putnbr(t_conversion *what, long long nbr);
int     argLenInt(long long nbr, t_conversion *what);
int     argLenUInt(unsigned int nbr, t_conversion *what);
int     argLenStr(char *str, t_conversion *what);
int	toINT(char c);
char	*joinNumbers(t_conversion *what, char c);
void	ft_bzero(char *str);

//PARSER//
void    parser(t_conversion *what, const char *str);
void doTheJob(t_conversion *what, char c);
void    treatHexa(t_conversion *what, char c);

//FORMAT TREATING//
void    treatFormat(t_conversion *what, int rep);

//reset/free//

void resetToOrigin(t_conversion *what);


int ft_printf(const char *, ...);

#endif