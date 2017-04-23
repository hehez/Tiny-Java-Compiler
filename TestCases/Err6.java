/*
 * Syntax error test 6:
 * Line 23: error in main method parameter declaration (no argument name)
 *
 */
public class Err6
{

    static int count( int n )
    {
	int i = 0;
	int sum = 0;
 
	i = 1;
	sum = 0;
	while ( i <= n ) {
	    sum = sum + i;
	    i = i + 1;
	}
	return sum;
    }

    public static void main( String[] )
    {
	int i = 0;
	int sum = 0;
 
	i = SimpleIO.readInt();    // read i 
	sum = count( i );          // call count
	SimpleIO.printInt( sum );  // print the result
	SimpleIO.println();        // print the newline
	return;
    }
}
