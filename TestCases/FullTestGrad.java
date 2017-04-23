/*
 * Full test program: all features of a grad version of TinyJava
 */
public class FullTestGrad
{

    static int     ifield = 0;
    static float[] vfield = null;

    static float compute( int n, float[] vec )
    {
	int   i   = 0;
	float sum = 0.0f;
 
	i = 0;
	while ( i < n ) {
	    sum = sum + vec[ i ];
	    i = i + 1;
	}
	return sum;
    }

    public static void main( String[] args )
    {
	int     i      = 0;
	int     size   = 0;
	float   sum    = 2.0f;
	float[] vector = null;
 
	size = 10;
	if( size <= ifield )
	    SimpleIO.printString( "FullTestGrad.main: Error: negative size value\n" );
	else {
	    vector = new float[ size ];
	    if( vector == null )
		SimpleIO.printString( "FullTestGrad.main: Error: failed to creat vector array\n" );
	    else {
		for( i = 0; i < size; i++ )
		    vector[ i ] = i + 1;
		sum = compute( 10, vector );
		SimpleIO.printFloat( sum );       // print the result
		SimpleIO.println();               // print the newline
		ifield = size;
		vfield = vector;
		sum = compute( ifield, vfield );  // call compute
		SimpleIO.printFloat( sum );       // print the result
		SimpleIO.println();               // print the newline
	    }
	}
	return;
    }
}
