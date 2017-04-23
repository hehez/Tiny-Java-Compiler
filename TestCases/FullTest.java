/*
 * Full test program: all features of an undergrad version of TinyJava
 */
public class FullTest
{

    static int   field1 = 1;
    static float field2 = 1.0f;

    static int method( int n, float incr )
    {
	int   i   = 0;
	float sum = 0.0f;
 
	i = 1;
	while ( i <= n ) {
	    sum = sum + i;
	    i = i + 1;
	}
	return (int) (sum + incr);
    }

    public static void main( String[] args )
    {
	int   cnt = 0;
	float sum = 2.0f;
 
	SimpleIO.printString( "Enter a small, positive integer: " );
	cnt = SimpleIO.readInt();
	if( cnt <= 0 )
	    SimpleIO.printString( "FullTest.main: Error: negative value entered\n" );
	else {
	    field1 = field1 + cnt;
	    field2 = method( cnt, 11.11f ) + sum;    // call count
	    SimpleIO.printFloat( field2 );           // print the result
	    SimpleIO.println();                      // print the newline
	}
	return;
    }
}
