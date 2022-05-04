#ifndef	GETFUNC_H
#define	GETFUNC_H

enum { LOOP = -3, CR, ERR, OK};

#define		MIN			0
#define		MAX			99999999
#define		NUM_MIN		0
#define		NUM_MAX		10
#define		DIG_MAX		10

int getString(char *pro, char *buf, int size);
int getNumber(char *pro, int min, int max);

#endif /* GETFUNC_H */
