#include <R.h>
#include <Rmath.h>

void kernel_smooth(double *x, int *n, double *xpts,
				   int *nxpts, double *h, double *result)
{
	int i, j;
	double d, ksum;

	for(i=0; i < *nxpts; i++) 
	{
		ksum = 0;
		for(j=0; j < *n; j++) 
		{
			d = xpts[i] - x[j];
			ksum += dnorm(d / *h, 0, 1, 0);
		}
		result[i] = ksum / ((*n) * (*h));
	}
}