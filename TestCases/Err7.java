/*
 * Syntax error test 7:
 * Line 16: missing '(' in a while stmt
 *
 */
public class Err7
{

    public static void main( String[] args )
    {
	int i = 0;
	int n = 10;
	int sum = 0;
 
	sum = 0;
	while  i <= n ) {
	    sum = sum + i;
	    i = i + 1;
	}
 
	return;
    }
}
