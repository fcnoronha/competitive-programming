// DIOPHANTINE EQUATIONS

/*
	A diophantine equantion is an equantion in the form

		ax + by = c, 

	with a,b,x,y,d being interger values.

	The equation has one or more solutions iff mdc(a,b) divides c.

*/

// Find a solution
int gcd(int a, int b, int &x, int &y){

	if (a == 0){
		x = 0;
		y = 1;
		return b;
	}

	int x1, y1;
	int d = gcd(b%a, a, x1, y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return d;
}

bool solve(int a, int b, int c, int &x0, int &y0){

	// Solution will be stored in x0 and y0
	int g = gcd(abs(a), abs(b), x0, y0);
	
	if (c%g)
		return false;

	x0 *= c/g;
	y0 *= c/g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}

/*

	All the other solutions will be in the following form:

	x = x0 + k*(b/g)  ,  y = y0 - k*(a/g)

	for k being any interger.	
*/	