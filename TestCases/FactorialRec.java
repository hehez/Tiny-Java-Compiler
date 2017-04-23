/*
 * recursive factorial calculation
 */

public class FactorialRec
{

    static int n = 0;
    static int fact = 0;

    static int factorial( int n )
    {
	int retValue = 1;

	if ( n <= 1 )
	    retValue = 1;
	else
	    retValue = n * factorial( n - 1 );

	return retValue;
    }

    public static void main( String[] args )
    {
 
	SimpleIO.printString( "Enter an integer: " );
	n =  SimpleIO.readInt(); 	          // read n
	fact = factorial( n );                    // call factorial
	SimpleIO.printString( "Factorial of " );
	SimpleIO.printInt( n );                   // print n
	SimpleIO.printString( " = " );     
	SimpleIO.printInt( fact );                // print the result
	SimpleIO.println();
	return;
    }
}
 
