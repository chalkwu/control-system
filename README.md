# controlSys
A GUI for control system, MPC 

example:
input: string  a_string = "(( x1 * exp-2^x2 + u1) - (cos-5+x3))* (sinu2+   cos9) ";
  int a_lx = 3; //length of states
	int a_lu = 2; //length of inputs
	double x[3] = { 1, 2, 4 };
	double u[2] = { 1, 1.57 };
  
return:  -0.290191

For now, the uniary operators limits on exp(exponential), sin, cos. As for ln, log, they will be added later.
For divison "/", if the expression is illegel, such as "1/0", it returns a large number, 10000000000.
Later, I will do some error handles.

For minus sign "-", don't feed the function string like "5 + - 3".
However, "5 + -3" is good to go.

Cheers.


