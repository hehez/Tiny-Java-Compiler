/*
 * Syntax error test 8:
 * Line 16: error in a while stmt expression
 *
 */
public class Err8
{

    public static void main( String[] args )
    {
	int i = 0;
	int n = 10;
	int sum = 0;
 
	sum = 0;
	while ( i  n ) {
	    sum = sum + i;
	    i = i + 1;
	}
 
	return;
    }
}
